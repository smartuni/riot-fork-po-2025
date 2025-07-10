/*
 * Copyright (C) 2020 Freie Universität BerlinI2C_SPEED_FAST
 * Copyright (C) 2023 HAW Hamburg
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#pragma once

/**
 * @ingroup     boards_adafruit-feather-nrf52840-sense
 * @{
 *
 * @file
 * @brief       Peripheral configuration for the Adafruit Feather nRF52840
 *              Sense
 *
 * @author      Martine S. Lenders <m.lenders@fu-berlin.de>
 * @author      Michel Rottleuthner <michel.rottleuthner@haw-hamburg.de>
 *
 */

#include "periph_cpu.h"
#include "cfg_clock_32_0.h"
#include "cfg_rtt_default.h"
#include "cfg_timer_default.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name    UART configuration
 * @{
 */
static const uart_conf_t uart_config[] = {
    {
        .dev        = NRF_UARTE0,
        .rx_pin     = GPIO_PIN(0, 24),
        .tx_pin     = GPIO_PIN(0, 25),
#ifdef MODULE_PERIPH_UART_HW_FC
        .rts_pin    = GPIO_UNDEF,
        .cts_pin    = GPIO_UNDEF,
#endif
        .irqn       = UARTE0_UART0_IRQn,
    },
};

#define UART_0_ISR          (isr_uart0)

#define UART_NUMOF          ARRAY_SIZE(uart_config)
/** @} */

/**
 * @name    SPI configuration
 * @{
 */
static const spi_conf_t spi_config[] = {
    {
        .dev  = NRF_SPIM0,
        .sclk = GPIO_PIN(0, 14),
        .mosi = GPIO_PIN(0, 13),
        .miso = GPIO_PIN(0, 15),
    },
    {
        .dev  = NRF_SPIM1,
        .sclk = GPIO_PIN(0, 19),
        .mosi = GPIO_PIN(0, 17),
        .miso = GPIO_PIN(0, 22),
    }
};

#define SPI_NUMOF           ARRAY_SIZE(spi_config)
/** @} */

/**
 * @name    I2C configuration
 * @{
 */
static const i2c_conf_t i2c_config[] = {
    {
        .dev = NRF_TWIM1,
        .scl = 11,
        .sda = 12,
        .speed = I2C_SPEED_FAST
    }
};
#define I2C_NUMOF           ARRAY_SIZE(i2c_config)
/** @} */

static const pwm_conf_t pwm_config[] = {
    {
        NRF_PWM0,
        {
            GPIO_PIN(1,9),
        }
    },
    {
        NRF_PWM1,
        {
            GPIO_PIN(0,8),
        }
    }
};
#define PWM_NUMOF           ARRAY_SIZE(pwm_config)

#ifdef __cplusplus
}
#endif

/** @} */
