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
 * $vmFreeBSD: vmware/vmnet-only/freebsd/vmnet.c,v 1.14 2000/01/23 22:29:50 vsilyaev Exp $
 */

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/conf.h>
#include <sys/errno.h>
#include <sys/kernel.h>
#include <sys/malloc.h>
#include <sys/mbuf.h>
#include <sys/sockio.h>
#include <sys/socket.h>
#include <sys/filio.h>
#include <sys/poll.h>
#include <sys/proc.h>
#include <sys/uio.h>
#include <sys/vnode.h>

#include <machine/clock.h>

#include "rtc.h"

#ifdef MODULE_DEPEND
MODULE_DEPEND(rtc, linux, 1, 1, 1);
#endif

#define CDEV_MAJOR 202
#if defined(CDEV_MAJOR_) && CDEV_MAJOR != CDEV_MAJOR_
#error "CDEV_MAJOR != CDEV_MAJOR_"
#endif

#define	DEVICE_NAME	"rtc"

enum rtc_log_level {Lenter=0, Lexit=1, Linfo, Lwarning, Lfail};
#define DEBUG 0
#if DEBUG
#define DEB(x) x
#define DLog(level, fmt, args...)	printf("%s: " fmt "\n", __FUNCTION__ ,   ##args)
#else /* !DEBUG */
#define DEB(x)
#define	DLog(level, fmt, args...) 
#endif /* DEBUG */

struct rtc_softc {
	dev_t		dev; /* Back reference to device */
	struct {
	 int	freq;
	 struct {
		int	opened:1;
		int 	enabled:1;
	 } flags;
	struct callout rtc_handle;
	struct timespec lasttime;
	struct selinfo sip;
	int woken;
	void *rtc_ident;
	} var;
};

static d_open_t		rtc_open;
static d_close_t 	rtc_close;
static d_ioctl_t	rtc_ioctl;
static d_poll_t		rtc_poll;
static d_read_t		rtc_read;

static void rtc_callback(void *xtp);
static int rtc_modeevent(module_t mod, int cmd, void *arg);

static struct cdevsw rtc_cdevsw = {
#if __FreeBSD_version >= 500104
	.d_open =	rtc_open,
	.d_close =	rtc_close,
	.d_ioctl =	rtc_ioctl,
	.d_poll =	rtc_poll,
	.d_read =	rtc_read,
	.d_name =	DEVICE_NAME,
	.d_maj =	CDEV_MAJOR,
#else
	/* open */	rtc_open,
	/* close */	rtc_close,
	/* read */	rtc_read,
	/* write */	nowrite,
	/* ioctl */	rtc_ioctl,
	/* poll */	rtc_poll,
	/* mmap */	nommap,
	/* strategy */	nostrategy,
	/* name */	DEVICE_NAME,
	/* maj */	CDEV_MAJOR,
	/* dump */	nodump,
	/* psize */	nopsize,
	/* flags */	0,
#if __FreeBSD_version <= 500018
	/* bmaj */	-1,
#endif
#if __FreeBSD_version >= 500018 || __FreeBSD_version >= 430000
	/* kqfilter */	nokqfilter,
#endif
#endif 
};

/* 
 * Now declare the module to the system. 
 * IMPORTANT: Must be before netgraph node declaration.
 */
DEV_MODULE(rtc, rtc_modeevent, 0);


/* -=-=-=-=-=-=-=-=-= attach/detach device stuff -=-=-=-=-=-=-=-=-= */

static struct rtc_softc *
rtc_attach(dev_t dev)
{
	struct rtc_softc *sc;
	int unit;

#if __FreeBSD_version >= 500014
	unit = dev2unit(dev);
#else
	unit = lminor(dev);
#endif
	DLog(Lenter, "%d %p", unit, dev);
	if (dev->si_drv1) {
		DLog(Lexit, "old %p, %p", dev, dev->si_drv1);
		return dev->si_drv1;
	}

	MALLOC(sc, struct rtc_softc*, sizeof(*sc), M_DEVBUF, M_WAITOK);
	if (sc==NULL)
		return NULL;

	bzero(sc, sizeof(*sc));
	dev->si_drv1 = sc; /* Link together */
	sc->dev = dev;
	sc->var.freq = 1;

#if __FreeBSD_version >= 500000
	callout_init(&sc->var.rtc_handle, 1);
#else
	callout_init(&sc->var.rtc_handle);
#endif
	
	DLog(Lexit, "new %p,%p", dev, sc);
	return sc;
}

static int
rtc_detach(dev_t dev, struct rtc_softc *sc) 
{
	int error=0;

	if (sc == NULL) {
		return error;
	}

	callout_stop(&sc->var.rtc_handle);
	FREE(sc, M_DEVBUF);
	dev->si_drv1 = NULL;
	return error;
}

/* -=-=-=-=-=-=-=-=-= character device stuff -=-=-=-=-=-=-=-=-= */

int 
#if __FreeBSD_version >= 500023
rtc_open(dev_t dev, int oflag, int otyp, struct thread *p)
#else
rtc_open(dev_t dev, int oflag, int otyp, struct proc *p)
#endif
{
	struct rtc_softc *sc;
	
	sc = rtc_attach(dev);
	
	if (sc==NULL)
		return (EAGAIN);
	
	if (sc->var.flags.opened)
		return (EBUSY);
	
	sc->var.flags.opened = 1;
	
	return 0;
}

int 
#if __FreeBSD_version >= 500023
rtc_close(dev_t dev, int fflag, int otyp, struct thread *p)
#else
rtc_close(dev_t dev, int fflag, int otyp, struct proc *p)
#endif
{
	struct rtc_softc *sc = (struct rtc_softc *) dev->si_drv1;

	rtc_detach(dev, sc);
	sc->var.flags.opened = 0;
	return 0;
}

int 
#if __FreeBSD_version >= 500023
rtc_ioctl(dev_t dev, u_long cmd, caddr_t arg, int mode, struct thread *p)
#else
rtc_ioctl(dev_t dev, u_long cmd, caddr_t arg, int mode, struct proc *p)
#endif
{
	struct rtc_softc *sc = (struct rtc_softc *) dev->si_drv1;
	int error=0, freq, sleep;
	
	DLog(Lenter, "cmd 0x%04lx", cmd);
	switch (cmd) {
	case RTCIO_IRQP_SET:
		freq = *(int *)arg;
		if (freq < 2) {
			error = EINVAL;
			break;
		}
		if (freq > 1024) {
			error = EINVAL;
			break;
		}
		sc->var.freq = freq;
		if (sc->var.freq * 9 > hz * 8) {
			sc->var.freq = hz;
			printf("rtc: %d > kern.hz: Timing will be inaccurate, please increase hz.\n", sc->var.freq);
		}
		sleep = hz / sc->var.freq;
		DLog(Linfo, "Set RTC freq %d", sc->var.freq);
		callout_stop(&sc->var.rtc_handle);
		nanouptime(&sc->var.lasttime);
		callout_reset(&sc->var.rtc_handle, sleep, &rtc_callback, (void *)sc);
		break;
	case RTCIO_PIE_ON:
		sc->var.flags.enabled = 1;
		DLog(Linfo, "Enable interrupts");
		break;
	default:
		DLog(Lfail, "Unknown IOCTL 0x%04lx", cmd);
		error = EINVAL;
		break;
	}
	DLog(Lenter, "result %d", error);
	return (error);
}

int 
#if __FreeBSD_version >= 500023
rtc_poll(dev_t dev, int events, struct thread *p)
#else
rtc_poll(dev_t dev, int events, struct proc *p)
#endif
{
	struct rtc_softc *sc = (struct rtc_softc *) dev->si_drv1;
   	int revents = 0;
	
	if (!sc->var.flags.enabled) 
		return 0;

	if (events) {
		DLog(Linfo, "Delay for %d usec", delay);
		if (sc->var.woken) {
			sc->var.woken = 0;
			revents = events;
		} else {
			selrecord(p, &sc->var.sip);
		}
	}
	return revents;
}

int 
rtc_read(dev_t dev, struct uio *uio, int flags __unused)
{
	struct rtc_softc *sc = (struct rtc_softc *) dev->si_drv1;
	int error;
	
	if (!sc->var.flags.enabled) 
		return 0;

	if (flags & IO_NDELAY)
		return EAGAIN;

	DLog(Linfo, "Delay for %d usec", delay);
	error = tsleep(&sc->var.rtc_ident, PCATCH, "rtc rd", hz * 10);
	sc->var.woken = 0;
	return 0;
}

/* -=-=-=-=-=-=-=-=-= module load/unload stuff -=-=-=-=-=-=-=-=-= */
static dev_t rtc_dev = NULL;

static int
init_module(void)
{
	int error = 0;

#if __FreeBSD_version < 500104
   	error = cdevsw_add(&rtc_cdevsw);
	if (error) 
		return error;
#endif

	rtc_dev = make_dev(&rtc_cdevsw, 0, UID_ROOT, GID_WHEEL, 0644, DEVICE_NAME);
	if (rtc_dev==NULL)
		error = ENOMEM;

	return error;
}



static int
cleanup_module(void)
{
	int error = 0;

	destroy_dev(rtc_dev);
#if __FreeBSD_version < 500104
	error = cdevsw_remove(&rtc_cdevsw);
#endif
	DLog(Linfo, "return %d", error);
	return error;
}

static int
rtc_modeevent(module_t mod, int cmd, void *arg)
{
    int  error = 0;

    switch (cmd) {
    case MOD_LOAD:
	error = init_module();
	break;	

    case MOD_UNLOAD:
        /* fall through */
    case MOD_SHUTDOWN:
 	error = cleanup_module();
	break;

    default:	/* we only understand load/unload */
	error = EINVAL;
	break;
    }

    return (error);
}

void
rtc_callback(void *xtp)
{
	int sleep;
	struct rtc_softc *sc = (struct rtc_softc *)xtp;
	struct timespec curtime, nexttime, increment;

	if (callout_pending(&sc->var.rtc_handle) || !callout_active(&sc->var.rtc_handle))
		return;
	/* Wakeup sleepers */
	sc->var.woken = 1;
	selwakeup(&sc->var.sip);
	wakeup(&sc->var.rtc_ident);

	/* Setup for our next nap. */
	nanouptime(&curtime);
restart:
	increment.tv_sec = 0;
	increment.tv_nsec = 1000000000 / sc->var.freq;
	timespecadd(&sc->var.lasttime, &increment);
	nexttime.tv_sec = sc->var.lasttime.tv_sec;
	nexttime.tv_nsec = sc->var.lasttime.tv_nsec;
	timespecadd(&nexttime, &increment);
	if (timespeccmp(&nexttime, &curtime, <)) {
		/* Catch up if we lag curtime */
		sc->var.lasttime.tv_sec = curtime.tv_sec;
		sc->var.lasttime.tv_nsec = curtime.tv_nsec;
		timespecsub(&sc->var.lasttime, &increment);
		timespecsub(&nexttime, &curtime);
#if 0
		printf("lagging curtime by %d.%ld\n", nexttime.tv_sec, nexttime.tv_nsec);
#endif
		goto restart;
	} else {
		timespecsub(&nexttime, &curtime);
		sleep = nexttime.tv_nsec / (1000000000 / hz);
	}
	callout_reset(&sc->var.rtc_handle, sleep, &rtc_callback, xtp);
}
