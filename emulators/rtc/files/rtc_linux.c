/*
 * Copyright by Vladimir N. Silyaev 2000
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD$
 * $vmFreeBSD: vmware/vmnet-only/freebsd/vmnet_linux.c,v 1.5 2000/01/23 22:29:50 vsilyaev Exp $
 */

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/kernel.h>
#include <sys/sockio.h>
#include <sys/sysproto.h>
#include <sys/socket.h>

#include <i386/linux/linux.h>
#include <i386/linux/linux_proto.h>
#if __FreeBSD_version >= 500012 || __FreeBSD_version >= 430000
#include <compat/linux/linux_ioctl.h>
#else
#include <i386/linux/linux_ioctl.h>
#endif

#include "rtc.h"

#define DEBUG 0
#if DEBUG
#define DEB(x) x
#else /* !DEBUG */
#define DEB(x)
#endif /* DEBUG */

#define LINUX_IOCTL_SET(n,low,high) \
static linux_ioctl_function_t linux_ioctl_##n; \
static struct linux_ioctl_handler n##_handler = {linux_ioctl_##n, low, high }; \
SYSINIT(n##register, SI_SUB_KLD, SI_ORDER_MIDDLE, linux_ioctl_register_handler, &n##_handler); \
SYSUNINIT(n##unregister, SI_SUB_KLD, SI_ORDER_MIDDLE, linux_ioctl_unregister_handler, &n##_handler);

#define LINUX_RTC_PIE_ON	0x7005
#define LINUX_RTC_IRQP_SET	0x700C

LINUX_IOCTL_SET(rtc, 0x7000, 0x70ff);

static int
#if __FreeBSD_version >= 500023
linux_ioctl_rtc(struct thread *p, struct linux_ioctl_args *args)
#else
linux_ioctl_rtc(struct proc *p, struct linux_ioctl_args *args)
#endif
{
	switch (args->cmd & 0xffff) {
	case LINUX_RTC_PIE_ON:
		args->cmd=RTCIO_PIE_ON;
		return ioctl(p, (struct ioctl_args*)args);	
	case LINUX_RTC_IRQP_SET:
		args->cmd=RTCIO_IRQP_SET;
		return ioctl(p, (struct ioctl_args*)args);	
	}
	return (ENOIOCTL);
}
