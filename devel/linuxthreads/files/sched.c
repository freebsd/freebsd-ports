/*
 * Copyright (c) 1995 John Birrell <jb@cimlogic.com.au>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by John Birrell.
 * 4. Neither the name of the author nor the names of any co-contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * Extensively modified and added to by Richard Seaman, Jr. <dick@tar.com>
 *
 */
#include <sys/syscall.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <errno.h>
#include "pthread.h"
#include "internals.h"

int _sched_yield(void);
int _sched_setparam(pid_t pid, const struct sched_param *param);
int _sched_getparam(pid_t pid, struct sched_param *param);
int _sched_setscheduler(pid_t pid, int policy,
                         const struct sched_param *param);
int _sched_getscheduler(pid_t pid);
int _sched_get_priority_max(int policy);
int _sched_get_priority_min(int policy);
int _sched_rr_get_interval(pid_t pid, struct timespec *interval);

int __sched_setparam(pid_t pid, const struct sched_param *param);
int __sched_setscheduler(pid_t pid, int policy,
                         const struct sched_param *param);
int __sched_getscheduler(pid_t pid);
int __sched_get_priority_max(int policy);
int __sched_get_priority_min(int policy);
int __sched_getparam(pid_t pid, struct sched_param *param);
int __sched_rr_get_interval(pid_t pid, struct timespec *interval);
	
extern int _posix_priority_scheduling;

int
sched_yield(void)
{
	if (_posix_priority_scheduling)
	      return (_sched_yield());
	else
	      syscall(SYS_yield);
	return(0);
}

#ifdef HAVE_FIXED_SCHED_FUNCTIONS
int __sched_setparam(pid_t pid, const struct sched_param *param)
{
        if (_posix_priority_scheduling)
	  return (_sched_setparam(pid, param));
        else {
	  errno = ENOSYS;
	  return (-1);
	}
}

int __sched_setscheduler(pid_t pid, int policy,
                         const struct sched_param *param)
{
        if (_posix_priority_scheduling) {
	  return (_sched_setscheduler(pid, policy, param));
	} else {
	  errno = ENOSYS;
	  return (-1);
	}
}
int __sched_getscheduler(pid_t pid)
{
        if (_posix_priority_scheduling) {
	  return (_sched_getscheduler(pid));
	} else {
	  errno = ENOSYS;
	  return (-1);
	}
}
int __sched_get_priority_max(int policy)
{
        if (_posix_priority_scheduling)
	  return (_sched_get_priority_max (policy));
	else
	  errno = ENOSYS;
	  return (-1);
}
int __sched_get_priority_min(int policy)
{
        if (_posix_priority_scheduling)
	  return (_sched_get_priority_min (policy));
	else 
	  errno = ENOSYS;
	  return (-1);
}

int __sched_getparam(pid_t pid, struct sched_param *param)
{
        if (_posix_priority_scheduling)
	  return (_sched_getparam(pid, param));
	else {
	  errno = ENOSYS;
	  return (-1);
	}
}

int __sched_rr_get_interval(pid_t pid, struct timespec *interval)
{
        if (_posix_priority_scheduling)
	  return (_sched_rr_get_interval(pid, interval));
	else {
	  errno = ENOSYS;
	  return (-1);
	}
}
#else

#include <sys/rtprio.h>
#include <sys/types.h>

/* Defines take from sys/posix4/ksched.c */
#define p4prio_to_rtpprio(P) (RTP_PRIO_MAX - (P))
#define rtpprio_to_p4prio(P) (RTP_PRIO_MAX - (P))
#define P1B_PRIO_MIN rtpprio_to_p4prio(RTP_PRIO_MAX)
#define P1B_PRIO_MAX rtpprio_to_p4prio(RTP_PRIO_MIN)
#define p4prio_to_p_nice(P) (-(P + PRIO_MIN))
#define p_nice_to_p4prio(P) (-(P - PRIO_MAX))
#define P_NICE_PRIO_MIN p_nice_to_p4prio(PRIO_MAX)
#define P_NICE_PRIO_MAX p_nice_to_p4prio(PRIO_MIN)

int	_getpriority __P((int, int));
int	_setpriority __P((int, int, int));

int __sched_setparam(pid_t pid, const struct sched_param *param)
{
	int policy = __sched_getscheduler (pid);

	if (policy == -1)
		return (-1);
	return (__sched_setscheduler (pid, policy, param));
}

int sched_setparam(pid_t pid, const struct sched_param *param)
	__attribute__ ((weak, alias("__sched_setparam")));

int __sched_setscheduler(pid_t pid, int policy,
                         const struct sched_param *param)
{
	struct rtprio rtp;
	int max, min;
	int ret;
	int curtype;

	max = __sched_get_priority_max(policy);
	if (max == -1)
		return (-1);
	min = __sched_get_priority_min(policy);
	if (min == -1)
		return (-1);
	if (param->sched_priority > max  ||
	    param->sched_priority < min) {
		errno = EINVAL;
		return (-1);
	}

	switch (policy) {
	case SCHED_FIFO:
		rtp.type = RTP_PRIO_FIFO;
		rtp.prio = p4prio_to_rtpprio (param->sched_priority);
		return (rtprio (RTP_SET, pid, &rtp));
		
	case SCHED_RR:
		rtp.type = RTP_PRIO_REALTIME;
		rtp.prio = p4prio_to_rtpprio (param->sched_priority);
		return (rtprio (RTP_SET, pid, &rtp));

	case SCHED_OTHER:
		curtype = __sched_getscheduler (pid);
		if (curtype != SCHED_OTHER) {
			rtp.type = RTP_PRIO_NORMAL;
			rtp.prio = p4prio_to_rtpprio (0);
			ret = rtprio (RTP_SET, pid, &rtp);
			if (ret) 
				return (ret);
		}
		return (_setpriority (PRIO_PROCESS, pid,
				     p4prio_to_p_nice (param->sched_priority)));

	default:
		errno = EINVAL;
		return (-1);
	}
}

int sched_setscheduler(pid_t pid, int policy,
		       const struct sched_param *param)
	__attribute__ ((weak, alias("__sched_setscheduler")));
	
int __sched_getscheduler(pid_t pid)
{
	int ret;
	struct rtprio rtp;

	ret = rtprio (RTP_LOOKUP, pid, &rtp);
	if (!ret) {
		switch (rtp.type) {
		case RTP_PRIO_FIFO:
		ret = SCHED_FIFO;
		break;

		case RTP_PRIO_REALTIME:
		ret = SCHED_RR;
		break;

		default:
		ret = SCHED_OTHER;
		break;
		}
	}
	return (ret);
}

int sched_getscheduler(pid_t pid)
	__attribute__ ((weak, alias("__sched_getscheduler")));

int __sched_get_priority_max(int policy)
{
	switch (policy)
	{
		case SCHED_FIFO:
		case SCHED_RR:
		return (P1B_PRIO_MAX);

		case SCHED_OTHER:
		return(P_NICE_PRIO_MAX);

		default:
		errno = EINVAL;
		return (-1);
	}
}

int sched_get_priority_max(int policy)
	__attribute__ ((weak, alias("__sched_get_priority_max")));

int __sched_get_priority_min(int policy)
{
	switch (policy)
	{
		case SCHED_FIFO:
		case SCHED_RR:
		return (P1B_PRIO_MIN);

		case SCHED_OTHER:
		return(P_NICE_PRIO_MIN);

		default:
		errno = EINVAL;
		return (-1);
	}
}

int sched_get_priority_min(int policy)
	__attribute__ ((weak, alias("__sched_get_priority_min")));


int __sched_getparam(pid_t pid, struct sched_param *param)
{
	int ret = 0;
	struct rtprio rtp;

	ret = rtprio (RTP_LOOKUP, pid, &rtp);
	if (!ret) {
		switch (rtp.type) {
		case RTP_PRIO_FIFO:
		case RTP_PRIO_REALTIME:
			param->sched_priority = rtpprio_to_p4prio(rtp.prio);
			break;

		default:
			errno = 0;
			ret = _getpriority (PRIO_PROCESS, pid);
			if (ret == -1 && errno != 0) 
				return (-1);

			param->sched_priority = p_nice_to_p4prio(ret);
			break;
		}
	}
	return (ret);
		
}

int sched_getparam(pid_t pid, struct sched_param *param)
	__attribute__ ((weak, alias("__sched_getparam")));

int __sched_rr_get_interval(pid_t pid, struct timespec *interval)
{
        if (_posix_priority_scheduling)
	  return (_sched_rr_get_interval(pid, interval));
	else {
	  errno = ENOSYS;
	  return (-1);
	}
}

int sched_rr_get_interval(pid_t pid, struct timespec *interval)
	__attribute__ ((weak, alias("__sched_rr_get_interval")));

#endif
