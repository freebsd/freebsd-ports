/*
 * Copyright (c) 2002  The FreeBSD Project
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
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD: /tmp/pcvs/ports/lang/ifc7/files/Attic/sysconf.c,v 1.1 2002-11-18 09:27:32 maho Exp $
 */
#include <unistd.h>
#include <errno.h>

#define _SC_UNDEF 0

static int linux_sysconf[] = {
    _SC_ARG_MAX,
    _SC_CHILD_MAX,
    _SC_CLK_TCK,
    _SC_NGROUPS_MAX,
    _SC_OPEN_MAX,
    _SC_STREAM_MAX,
    _SC_TZNAME_MAX,
    _SC_JOB_CONTROL,
    _SC_SAVED_IDS,
    _SC_REALTIME_SIGNALS,
    _SC_PRIORITY_SCHEDULING,
    _SC_TIMERS,
    _SC_ASYNCHRONOUS_IO,
    _SC_PRIORITIZED_IO,
    _SC_SYNCHRONIZED_IO,
    _SC_FSYNC,
    _SC_MAPPED_FILES,
    _SC_MEMLOCK,
    _SC_MEMLOCK_RANGE,
    _SC_MEMORY_PROTECTION,
    _SC_MESSAGE_PASSING,
    _SC_SEMAPHORES,
    _SC_SHARED_MEMORY_OBJECTS,
    _SC_AIO_LISTIO_MAX,
    _SC_AIO_MAX,
    _SC_AIO_PRIO_DELTA_MAX,
    _SC_DELAYTIMER_MAX,
    _SC_MQ_OPEN_MAX,
    _SC_UNDEF,
    _SC_VERSION,
    _SC_PAGESIZE,
    _SC_RTSIG_MAX,
    _SC_SEM_NSEMS_MAX,
    _SC_SEM_VALUE_MAX,
    _SC_SIGQUEUE_MAX,
    _SC_TIMER_MAX,
    _SC_BC_BASE_MAX,
    _SC_BC_DIM_MAX,
    _SC_BC_SCALE_MAX,
    _SC_BC_STRING_MAX,
    _SC_COLL_WEIGHTS_MAX,
    _SC_UNDEF,
    _SC_EXPR_NEST_MAX,
    _SC_LINE_MAX,
    _SC_RE_DUP_MAX,
    _SC_UNDEF,
    _SC_2_VERSION,
    _SC_2_C_BIND,
    _SC_2_C_DEV,
    _SC_2_FORT_DEV,
    _SC_2_FORT_RUN,
    _SC_2_SW_DEV,
    _SC_2_LOCALEDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_UNDEF,
    _SC_2_CHAR_TERM,
    _SC_UNDEF,
    _SC_2_UPE,
};

#define SYSCONF_SIZE (sizeof(linux_sysconf)/sizeof(int))

long __sysconf(int name)
{
    if (name >= SYSCONF_SIZE || linux_sysconf[name] == _SC_UNDEF) {
	errno = EINVAL;
	return -1;
    }

    return sysconf(linux_sysconf[name]);
}
