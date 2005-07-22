/*
 * Copyright (c) 2005 Yahoo! Technologies Norway AS
 * Copyright (c) 2003 Overture Services Norway AS
 * Copyright (c) 2001 Daniel Eischen <deischen@FreeBSD.org>.
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
 * THIS SOFTWARE IS PROVIDED BY DANIEL EISCHEN AND CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
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
 * $FreeBSD: /tmp/pcvs/ports/devel/linuxthreads/files/wraputhread.c,v 1.4 2005-07-22 22:20:21 tegge Exp $
 */

#ifdef LINUXTHREADS_WRAP_API
#define COMPILING_WRAPUTHREAD
#endif
#include <pthread.h>
#include <stdlib.h>
#include <sys/errno.h>

#ifdef LINUXTHREADS_WRAP_API
#define __pthread_attr_destroy linuxthreads_pthread_attr_destroy
#define __pthread_attr_getdetachstate linuxthreads_pthread_attr_getdetachstate
#define __pthread_attr_getinheritsched linuxthreads_pthread_attr_getinheritsched
#define __pthread_attr_getschedparam linuxthreads_pthread_attr_getschedparam
#define __pthread_attr_getschedpolicy linuxthreads_pthread_attr_getschedpolicy
#define __pthread_attr_getscope linuxthreads_pthread_attr_getscope
#define __pthread_attr_init linuxthreads_pthread_attr_init
#define __pthread_attr_setdetachstate linuxthreads_pthread_attr_setdetachstate
#define __pthread_attr_setinheritsched linuxthreads_pthread_attr_setinheritsched
#define __pthread_attr_setschedparam linuxthreads_pthread_attr_setschedparam
#define __pthread_attr_setschedpolicy linuxthreads_pthread_attr_setschedpolicy
#define __pthread_attr_setscope linuxthreads_pthread_attr_setscope
#define __pthread_barrier_destroy linuxthreads_pthread_barrier_destroy
#define __pthread_barrier_init linuxthreads_pthread_barrier_init
#define __pthread_barrier_wait linuxthreads_pthread_barrier_wait
#define __pthread_barrierattr_destroy linuxthreads_pthread_barrierattr_destroy
#define __pthread_barrierattr_init linuxthreads_pthread_barrierattr_init
#define __pthread_barrierattr_setpshared linuxthreads_pthread_barrierattr_setpshared
#define __pthread_cancel linuxthreads_pthread_cancel
#define __pthread_condattr_destroy linuxthreads_pthread_condattr_destroy
#define __pthread_condattr_getpshared linuxthreads_pthread_condattr_getpshared
#define __pthread_condattr_init linuxthreads_pthread_condattr_init
#define __pthread_condattr_setpshared linuxthreads_pthread_condattr_setpshared
#define __pthread_cond_broadcast linuxthreads_pthread_cond_broadcast
#define __pthread_cond_destroy linuxthreads_pthread_cond_destroy
#define __pthread_cond_init linuxthreads_pthread_cond_init
#define __pthread_cond_signal linuxthreads_pthread_cond_signal
#define __pthread_cond_timedwait linuxthreads_pthread_cond_timedwait
#define __pthread_cond_wait linuxthreads_pthread_cond_wait
#define __pthread_create linuxthreads_pthread_create
#define __pthread_detach linuxthreads_pthread_detach
#define __pthread_equal linuxthreads_pthread_equal
#define __pthread_exit linuxthreads_pthread_exit
#define __pthread_getcpuclockid linuxthreads_pthread_getcpuclockid
#define __pthread_getschedparam linuxthreads_pthread_getschedparam
#define __pthread_join linuxthreads_pthread_join
#define __pthread_key_delete linuxthreads_pthread_key_delete
#define __pthread_kill linuxthreads_pthread_kill
#define __pthread_rwlockattr_init linuxthreads_pthread_rwlockattr_init
#define __pthread_rwlockattr_getpshared linuxthreads_pthread_rwlockattr_getpshared
#define __pthread_rwlockattr_setpshared linuxthreads_pthread_rwlockattr_setpshared
#define __pthread_rwlockattr_destroy linuxthreads_pthread_rwlockattr_destroy
#define __pthread_self linuxthreads_pthread_self
#define __pthread_setcanceltype linuxthreads_pthread_setcanceltype
#define __pthread_setcancelstate linuxthreads_pthread_setcancelstate
#define __pthread_setschedparam linuxthreads_pthread_setschedparam
#define __pthread_sigmask linuxthreads_pthread_sigmask
#define __pthread_testcancel linuxthreads_pthread_testcancel
#else
#define __pthread_attr_destroy pthread_attr_destroy
#define __pthread_attr_getdetachstate pthread_attr_getdetachstate
#define __pthread_attr_getinheritsched pthread_attr_getinheritsched
#define __pthread_attr_getschedparam pthread_attr_getschedparam
#define __pthread_attr_getschedpolicy pthread_attr_getschedpolicy
#define __pthread_attr_getscope pthread_attr_getscope
#define __pthread_attr_init pthread_attr_init
#define __pthread_attr_setdetachstate pthread_attr_setdetachstate
#define __pthread_attr_setinheritsched pthread_attr_setinheritsched
#define __pthread_attr_setschedparam pthread_attr_setschedparam
#define __pthread_attr_setschedpolicy pthread_attr_setschedpolicy
#define __pthread_attr_setscope pthread_attr_setscope
#define __pthread_barrier_destroy pthread_barrier_destroy
#define __pthread_barrier_init pthread_barrier_init
#define __pthread_barrier_wait pthread_barrier_wait
#define __pthread_barrierattr_destroy pthread_barrierattr_destroy
#define __pthread_barrierattr_init pthread_barrierattr_init
#define __pthread_barrierattr_setpshared pthread_barrierattr_setpshared
#define __pthread_cancel pthread_cancel
#define __pthread_condattr_destroy pthread_condattr_destroy
#define __pthread_condattr_getpshared pthread_condattr_getpshared
#define __pthread_condattr_init pthread_condattr_init
#define __pthread_condattr_setpshared pthread_condattr_setpshared
#define __pthread_cond_broadcast pthread_cond_broadcast
#define __pthread_cond_destroy pthread_cond_destroy
#define __pthread_cond_init pthread_cond_init
#define __pthread_cond_signal pthread_cond_signal
#define __pthread_cond_timedwait pthread_cond_timedwait
#define __pthread_cond_wait pthread_cond_wait
#define __pthread_create pthread_create
#define __pthread_detach pthread_detach
#define __pthread_equal pthread_equal
#define __pthread_exit pthread_exit
#define __pthread_getschedparam pthread_getschedparam
#define __pthread_join pthread_join
#define __pthread_key_delete pthread_key_delete
#define __pthread_kill pthread_kill
#define __pthread_rwlockattr_init pthread_rwlockattr_init
#define __pthread_rwlockattr_getpshared pthread_rwlockattr_getpshared
#define __pthread_rwlockattr_setpshared pthread_rwlockattr_setpshared
#define __pthread_rwlockattr_destroy pthread_rwlockattr_destroy
#define __pthread_self pthread_self
#define __pthread_setcanceltype pthread_setcanceltype
#define __pthread_setcancelstate pthread_setcancelstate
#define __pthread_setschedparam pthread_setschedparam
#define __pthread_sigmask pthread_sigmask
#define __pthread_testcancel pthread_testcancel
#endif

int   __pthread_atfork(void (*)(void), void (*)(void), void (*)(void));
int   __pthread_attr_destroy(pthread_attr_t *);
int   __pthread_attr_getdetachstate(const pthread_attr_t *, int *);
int   __pthread_attr_getguardsize(const pthread_attr_t *, size_t *);
int   __pthread_attr_getinheritsched(const pthread_attr_t *, int *);
int   __pthread_attr_getschedparam(const pthread_attr_t *,
				   struct sched_param *);
int   __pthread_attr_getschedpolicy(const pthread_attr_t *, int *);
int   __pthread_attr_getscope(const pthread_attr_t *, int *);
int   __pthread_attr_getstack(const pthread_attr_t *, void **, size_t *);
int   __pthread_attr_getstackaddr(const pthread_attr_t *, void **);
int   __pthread_attr_getstacksize(const pthread_attr_t *, size_t *);
int   __pthread_attr_init(pthread_attr_t *);
int   __pthread_attr_setdetachstate(pthread_attr_t *, int);
int   __pthread_attr_setguardsize(pthread_attr_t *, size_t);
int   __pthread_attr_setinheritsched(pthread_attr_t *, int);
int   __pthread_attr_setschedparam(pthread_attr_t *,
				   const struct sched_param *);
int   __pthread_attr_setschedpolicy(pthread_attr_t *, int);
int   __pthread_attr_setscope(pthread_attr_t *, int);
int   __pthread_attr_setstack(pthread_attr_t *, void *, size_t);
int   __pthread_attr_setstackaddr(pthread_attr_t *, void *);
int   __pthread_attr_setstacksize(pthread_attr_t *, size_t);
int   __pthread_barrier_destroy(pthread_barrier_t *);
int   __pthread_barrier_init(pthread_barrier_t *,
			     const pthread_barrierattr_t *,
			     unsigned int);
int   __pthread_barrier_wait(pthread_barrier_t *);
int   __pthread_barrierattr_destroy(pthread_barrierattr_t *);
int   __pthread_barrierattr_getpshared(const pthread_barrierattr_t *, int *);
int   __pthread_barrierattr_init(pthread_barrierattr_t *);
int   __pthread_barrierattr_setpshared(pthread_barrierattr_t *, int);
int   __pthread_cancel(pthread_t);
int   __pthread_cond_broadcast(pthread_cond_t *);
int   __pthread_cond_destroy(pthread_cond_t *);
int   __pthread_cond_init(pthread_cond_t *, const pthread_condattr_t *);
int   __pthread_cond_signal(pthread_cond_t *);
int   __pthread_cond_timedwait(pthread_cond_t *,
			       pthread_mutex_t *,
			       const struct timespec *);
int   __pthread_cond_wait(pthread_cond_t *, pthread_mutex_t *);
int   __pthread_condattr_destroy(pthread_condattr_t *);
int   __pthread_condattr_getpshared(const pthread_condattr_t *, int *);
int   __pthread_condattr_init(pthread_condattr_t *);
int   __pthread_condattr_setpshared(pthread_condattr_t *, int);
int   __pthread_create(pthread_t *,
		       const pthread_attr_t *,
		       void *(*)(void *),
		       void *);
int   __pthread_detach(pthread_t);
int   __pthread_equal(pthread_t, pthread_t);
void  __pthread_exit(void *);
int   __pthread_getconcurrency(void);
int   __pthread_getschedparam(pthread_t, int *, struct sched_param *);
void *__pthread_getspecific(pthread_key_t);
int   __pthread_join(pthread_t, void **);
int   __pthread_key_create(pthread_key_t *, void (*) (void *));
int   __pthread_key_delete(pthread_key_t);
int   __pthread_kill(pthread_t, int);
int   __pthread_mutex_destroy(pthread_mutex_t *);
int   __pthread_mutex_init(pthread_mutex_t *, const pthread_mutexattr_t *);
int   __pthread_mutex_lock(pthread_mutex_t *);
int   __pthread_mutex_timedlock(pthread_mutex_t *, const struct timespec *);
int   __pthread_mutex_trylock(pthread_mutex_t *);
int   __pthread_mutex_unlock(pthread_mutex_t *);
int   __pthread_mutexattr_destroy(pthread_mutexattr_t *);
int   __pthread_mutexattr_getpshared(const pthread_mutexattr_t *, int *);
int   __pthread_mutexattr_gettype(const pthread_mutexattr_t *, int *);
int   __pthread_mutexattr_init(pthread_mutexattr_t *);
int   __pthread_mutexattr_setpshared(pthread_mutexattr_t *, int);
int   __pthread_mutexattr_settype(pthread_mutexattr_t *, int);
int   __pthread_rwlock_destroy(pthread_rwlock_t *);
int   __pthread_rwlock_init(pthread_rwlock_t *,
			    const pthread_rwlockattr_t *);
int   __pthread_rwlock_rdlock(pthread_rwlock_t *);
int   __pthread_rwlock_timedrdlock(pthread_rwlock_t *,
				   const struct timespec *);
int   __pthread_rwlock_timedwrlock(pthread_rwlock_t *,
				   const struct timespec *);
int   __pthread_rwlock_tryrdlock(pthread_rwlock_t *);
int   __pthread_rwlock_trywrlock(pthread_rwlock_t *);
int   __pthread_rwlock_unlock(pthread_rwlock_t *);
int   __pthread_rwlock_wrlock(pthread_rwlock_t *);
int   __pthread_rwlockattr_destroy(pthread_rwlockattr_t *);
int   __pthread_rwlockattr_init(pthread_rwlockattr_t *);
int   __pthread_rwlockattr_getpshared(const pthread_rwlockattr_t *, int *);
int   __pthread_rwlockattr_setpshared(pthread_rwlockattr_t *, int);
pthread_t __pthread_self(void);
int   __pthread_setcancelstate(int, int *);
int   __pthread_setcanceltype(int, int *);
int   __pthread_setconcurrency(int);
int   __pthread_setschedparam(pthread_t, int, const struct sched_param *);
int   __pthread_setspecific(pthread_key_t, const void *);
int   __pthread_sigmask(int, const sigset_t *, sigset_t *);
void  __pthread_testcancel(void);

static pthread_mutex_t allocmutexlock = PTHREAD_MUTEX_INITIALIZER;
enum uthread_mutextype {
        UTHREAD_PTHREAD_MUTEX_ERRORCHECK        = 1,    /* Default POSIX mutex */
        UTHREAD_PTHREAD_MUTEX_RECURSIVE         = 2,    /* Recursive mutex */
        UTHREAD_PTHREAD_MUTEX_NORMAL            = 3,    /* No error checking */
        MUTEX_TYPE_MAX
};

enum {
	UTHREAD_PTHREAD_CREATE_JOINABLE = 0,
	UTHREAD_PTHREAD_CREATE_DETACHED = 1
};

enum {
	UTHREAD_PTHREAD_INHERIT_SCHED = 4,
	UTHREAD_PTHREAD_EXPLICIT_SCHED = 0
};


enum {
	UTHREAD_PTHREAD_SCOPE_SYSTEM = 2,
	UTHREAD_PTHREAD_SCOPE_PROCESS = 0
};

enum {
	UTHREAD_PTHREAD_PROCESS_PRIVATE = 0,
	UTHREAD_PTHREAD_PROCESS_SHARED = 1
};


enum {
	UTHREAD_PTHREAD_CANCEL_ENABLE = 0,
	UTHREAD_PTHREAD_CANCEL_DISABLE = 1,
	UTHREAD_PTHREAD_CANCEL_DEFERRED = 0,
	UTHREAD_PTHREAD_CANCEL_ASYNCHRONOUS = 2
};

#define UTHREAD_PTHREAD_CANCELED		((void *) 1)

enum {
	UTHREAD_PTHREAD_PRIO_NONE = 0,
	UTHREAD_PTHREAD_PRIO_INHERIT = 1,
	UTHREAD_PTHREAD_PRIO_PROTECT = 2
};
	

struct uthread_pthread_once {
	int		state;
	pthread_mutex_t	*mutex;
};

typedef struct uthread_pthread_once uthread_pthread_once_t;

/*
 * Flags for once initialization.
 */
#define UTHREAD_PTHREAD_NEEDS_INIT  0
#define UTHREAD_PTHREAD_DONE_INIT   1


static int allocbarrier(pthread_barrier_t **barrier);
static int alloccond(pthread_cond_t **cond);
static int allocmutex(pthread_mutex_t **mutex);
static int allocrwlock(pthread_rwlock_t **rwlock);

static int
allocbarrier(pthread_barrier_t **barrier)
{
	pthread_barrier_t *b;
	int ret;

	b = malloc(sizeof(pthread_barrier_t));
	if (b == NULL)
		return ENOMEM;
	ret = __pthread_barrier_init(b, NULL, 1);
	if (ret != 0) {
		free(b);
		return ret;
	}
	__pthread_mutex_lock(&allocmutexlock);
	if (*barrier != NULL) {
		__pthread_mutex_unlock(&allocmutexlock);
		__pthread_barrier_destroy(b);
		free(b);
		return 0;
	}
	*barrier = b;
	__pthread_mutex_unlock(&allocmutexlock);
	return 0;
}

static int
alloccond(pthread_cond_t **cond)
{
	pthread_cond_t *c;
	int ret;

	c = malloc(sizeof(pthread_cond_t));
	if (c == NULL)
		return ENOMEM;
	ret = __pthread_cond_init(c, NULL);
	if (ret != 0) {
		free(c);
		return ret;
	}
	__pthread_mutex_lock(&allocmutexlock);
	if (*cond != NULL) {
		__pthread_mutex_unlock(&allocmutexlock);
		__pthread_cond_destroy(c);
		free(c);
		return 0;
	}
	*cond = c;
	__pthread_mutex_unlock(&allocmutexlock);
	return 0;
}

static int
allocmutex(pthread_mutex_t **mutex)
{
	pthread_mutex_t *m;
	int ret;

	m = malloc(sizeof(pthread_mutex_t));
	if (m == NULL)
		return ENOMEM;
	ret = __pthread_mutex_init(m, NULL);
	if (ret != 0) {
		free(m);
		return ret;
	}
	__pthread_mutex_lock(&allocmutexlock);
	if (*mutex != NULL) {
		__pthread_mutex_unlock(&allocmutexlock);
		__pthread_mutex_destroy(m);
		free(m);
		return 0;
	}
	*mutex = m;
	__pthread_mutex_unlock(&allocmutexlock);
	return 0;
}

static int
allocrwlock(pthread_rwlock_t **rwlock)
{
	pthread_rwlock_t *rw;
	int ret;

	rw = malloc(sizeof(pthread_rwlock_t));
	if (rw == NULL)
		return ENOMEM;
	ret = __pthread_rwlock_init(rw, NULL);
	if (ret != 0) {
		free(rw);
		return ret;
	}
	__pthread_mutex_lock(&allocmutexlock);
	if (*rwlock != NULL) {
		__pthread_mutex_unlock(&allocmutexlock);
		__pthread_rwlock_destroy(rw);
		free(rw);
		return 0;
	}
	*rwlock = rw;
	__pthread_mutex_unlock(&allocmutexlock);
	return 0;
}

int
_pthread_atfork(void (*prepare)(void),
		void (*parent)(void),
		void (*child)(void))
{
	return __pthread_atfork(prepare, parent, child);
}

int
_pthread_attr_destroy(pthread_attr_t **attr)
{
	int ret;

	if (attr == NULL || *attr == NULL)
		return EINVAL;
	ret = __pthread_attr_destroy(*attr);
	if (ret == 0) {
		free(*attr);
		*attr = NULL;
	}
	return ret;
}


int
_pthread_attr_getdetachstate(const pthread_attr_t **attr, int *detachstate)
{
	int ret;
	int lstate;
	
	if (attr == NULL || *attr == NULL || detachstate == NULL)
		return EINVAL;
	ret = __pthread_attr_getdetachstate(*attr, &lstate);
	if (ret == 0) {
		switch (lstate) {
		case PTHREAD_CREATE_JOINABLE:
			*detachstate = UTHREAD_PTHREAD_CREATE_JOINABLE;
			break;
		case PTHREAD_CREATE_DETACHED:
			*detachstate = UTHREAD_PTHREAD_CREATE_DETACHED;
			break;
		default:
			ret = EINVAL;
		}
	}
	return ret;
}

int
_pthread_attr_getguardsize(const pthread_attr_t **attr, size_t *guardsize)
{
	if (attr == NULL || *attr == NULL)
		return EINVAL;
	return __pthread_attr_getguardsize(*attr, guardsize);
}

int
_pthread_attr_getinheritsched(const pthread_attr_t **attr, int *inherit)
{
	int ret;
	int linherit;

	if (attr == NULL || *attr == NULL || inherit == NULL)
		return EINVAL;
	ret = __pthread_attr_getinheritsched(*attr, &linherit);
	if (ret == 0) {
		switch (linherit) {
		case PTHREAD_EXPLICIT_SCHED:
			*inherit = UTHREAD_PTHREAD_EXPLICIT_SCHED;
			break;
		case PTHREAD_INHERIT_SCHED:
			*inherit = UTHREAD_PTHREAD_INHERIT_SCHED;
			break;
		default:
			ret = EINVAL;
		}
	}
	return ret;
}

int
_pthread_attr_getschedparam(const pthread_attr_t **attr,
			    struct sched_param *sparam)
{
	if (attr == NULL || *attr == NULL || sparam == NULL)
		return EINVAL;
	return __pthread_attr_getschedparam(*attr, sparam);
}

int
_pthread_attr_getschedpolicy(const pthread_attr_t **attr,
			     int *policy)
{
	if (attr == NULL || *attr == NULL || policy == NULL)
		return EINVAL;
	return __pthread_attr_getschedpolicy(*attr, policy);
}

int
_pthread_attr_getscope(const pthread_attr_t **attr,
		       int *scope)
{
	int ret;
	int lscope;

	if (attr == NULL || *attr == NULL || scope == NULL)
		return EINVAL;
	ret = __pthread_attr_getscope(*attr, &lscope);
	if (ret == 0) {
		switch (lscope) {
		case PTHREAD_SCOPE_SYSTEM:
			*scope = UTHREAD_PTHREAD_SCOPE_SYSTEM;
			break;
		case PTHREAD_SCOPE_PROCESS:
			*scope = UTHREAD_PTHREAD_SCOPE_PROCESS;
			break;
		default:
			ret = EINVAL;
		}
	}
	return ret;
}

int
_pthread_attr_getstack(const pthread_attr_t **attr,
		       void **stackaddr,
		       size_t *stacksize)
{
	if (attr == NULL || *attr == NULL ||
	    stackaddr == NULL || stacksize == NULL)
		return EINVAL;
	return __pthread_attr_getstack(*attr, stackaddr, stacksize);
}

int
_pthread_attr_getstackaddr(const pthread_attr_t **attr,
			   void **stackaddr)
{
	if (attr == NULL || *attr == NULL || stackaddr == NULL)
		return EINVAL;
	return __pthread_attr_getstackaddr(*attr, stackaddr);
}

int
_pthread_attr_getstacksize(const pthread_attr_t **attr,
			   size_t *stacksize)
{
	if (attr == NULL || *attr == NULL || stacksize == NULL)
		return EINVAL;
	return __pthread_attr_getstacksize(*attr, stacksize);
}

int
_pthread_attr_init(pthread_attr_t **attr)
{
	int ret;
	pthread_attr_t *res;

	if (attr == NULL)
		return EINVAL;
	res = malloc(sizeof(pthread_attr_t));
	if (res == NULL)
		return ENOMEM;
	ret = __pthread_attr_init(res);
	if (ret == 0)
		*attr = res;
	else
		free(res);
	return ret;
}
int
_pthread_attr_setdetachstate(pthread_attr_t **attr, int detachstate)
{
	if (attr == NULL || *attr == NULL)
		return EINVAL;
	switch (detachstate) {
	case UTHREAD_PTHREAD_CREATE_JOINABLE:
		return __pthread_attr_setdetachstate(*attr,
						     PTHREAD_CREATE_JOINABLE);
	case UTHREAD_PTHREAD_CREATE_DETACHED:
		return __pthread_attr_setdetachstate(*attr,
						     PTHREAD_CREATE_DETACHED);
	default:
		return EINVAL;
	}
}

int
_pthread_attr_setguardsize(pthread_attr_t **attr, size_t guardsize)
{
	if (attr == NULL || *attr == NULL)
		return EINVAL;
	return __pthread_attr_setguardsize(*attr, guardsize);
}

int
_pthread_attr_setinheritsched(pthread_attr_t **attr, int inherit)
{
	if (attr == NULL || *attr == NULL)
		return EINVAL;
	switch (inherit) {
	case UTHREAD_PTHREAD_EXPLICIT_SCHED:
		return __pthread_attr_setinheritsched(*attr,
						      PTHREAD_EXPLICIT_SCHED);
	case UTHREAD_PTHREAD_INHERIT_SCHED:
		return __pthread_attr_setinheritsched(*attr,
						      PTHREAD_INHERIT_SCHED);
	default:
		return EINVAL;
	}
}

int
_pthread_attr_setschedparam(pthread_attr_t **attr,
			    struct sched_param *sparam)
{
	if (attr == NULL || *attr == NULL || sparam == NULL)
		return EINVAL;
	return __pthread_attr_setschedparam(*attr, sparam);
}

int
_pthread_attr_setschedpolicy(pthread_attr_t **attr,
			     int policy)
{
	if (attr == NULL || *attr == NULL)
		return EINVAL;
	return __pthread_attr_setschedpolicy(*attr, policy);
}

int
_pthread_attr_setscope(pthread_attr_t **attr,
		       int scope)
{
	if (attr == NULL || *attr == NULL)
		return EINVAL;
	switch (scope) {
	case UTHREAD_PTHREAD_SCOPE_SYSTEM:
		return __pthread_attr_setscope(*attr, PTHREAD_SCOPE_SYSTEM);
	case UTHREAD_PTHREAD_SCOPE_PROCESS:
		return __pthread_attr_setscope(*attr, PTHREAD_SCOPE_PROCESS);
	default:
		return EINVAL;
	}
}

int
_pthread_attr_setstack(pthread_attr_t **attr,
		       void *stackaddr,
		       size_t stacksize)
{
	if (attr == NULL || *attr == NULL)
		return EINVAL;
	return __pthread_attr_setstack(*attr, stackaddr, stacksize);
}

int
_pthread_attr_setstackaddr(pthread_attr_t **attr,
			   void *stackaddr)
{
	if (attr == NULL || *attr == NULL)
		return EINVAL;
	return __pthread_attr_setstackaddr(*attr, stackaddr);
}

int
_pthread_attr_setstacksize(pthread_attr_t **attr,
			   size_t stacksize)
{
	if (attr == NULL || *attr == NULL)
		return EINVAL;
	return __pthread_attr_setstacksize(*attr, stacksize);
}

int
_pthread_barrier_destroy(pthread_barrier_t **barrier)
{
	int ret;

	if (barrier == NULL || *barrier == NULL)
		return EINVAL;
	ret = __pthread_barrier_destroy(*barrier);
	if (ret == 0) {
		free(*barrier);
		*barrier = NULL;
	}
	return ret;
}

int
_pthread_barrier_init(pthread_barrier_t **barrier,
		      pthread_barrierattr_t **battr,
		      unsigned int count)
{
	int ret;
	pthread_barrier_t *res;

	if (barrier == NULL)
		return EINVAL;
	res = malloc(sizeof(pthread_barrier_t));
	if (res == NULL)
		return ENOMEM;
	ret = __pthread_barrier_init(res, battr != NULL ? *battr : NULL,
				     count);
	if (ret == 0)
		*barrier = res;
	else
		free(res);
	return ret;
}

int
_pthread_barrier_wait(pthread_barrier_t **barrier)
{
	int ret;

	if (barrier == NULL)
		return EINVAL;
	if (*barrier == NULL) {
		ret = allocbarrier(barrier);
		if (ret != 0)
			return ret;
	}
	return __pthread_barrier_wait(*barrier);
}

int
_pthread_barrierattr_destroy(pthread_barrierattr_t **battr)
{
	int ret;

	if (battr == NULL || *battr == NULL)
		return EINVAL;
	ret = __pthread_barrierattr_destroy(*battr);
	if (ret == 0) {
		free(*battr);
		*battr = NULL;
	}
	return ret;
}

int
_pthread_barrierattr_getpshared(const pthread_barrierattr_t **battr,
				int *pshared)
{
	int ret;
	int lshared;

	if (battr == NULL || *battr == NULL || pshared == NULL)
		return EINVAL;
	ret = __pthread_barrierattr_getpshared(*battr, &lshared);
	if (ret == 0) {
		switch (lshared) {
		case PTHREAD_PROCESS_PRIVATE:
			*pshared = UTHREAD_PTHREAD_PROCESS_PRIVATE;
			break;
		case PTHREAD_PROCESS_SHARED:
			*pshared = UTHREAD_PTHREAD_PROCESS_SHARED;
			break;
		default:
			ret = EINVAL;
		}
	}
	return ret;
}

int
_pthread_barrierattr_init(pthread_barrierattr_t **battr)
{
	int ret;
	pthread_barrierattr_t *res;

	if (battr == NULL)
		return EINVAL;
	res = malloc(sizeof(pthread_barrierattr_t));
	if (res == NULL)
		return ENOMEM;
	ret = __pthread_barrierattr_init(res);
	if (ret == 0)
		*battr = res;
	else
		free(res);
	return ret;
}

int
_pthread_barrierattr_setpshared(pthread_barrierattr_t **battr,
				int pshared)
{
	if (battr == NULL || *battr == NULL)
		return EINVAL;
	switch (pshared) {
	case UTHREAD_PTHREAD_PROCESS_PRIVATE:
		return __pthread_barrierattr_setpshared(*battr,
							PTHREAD_PROCESS_PRIVATE);
	case UTHREAD_PTHREAD_PROCESS_SHARED:
		return __pthread_barrierattr_setpshared(*battr,
							PTHREAD_PROCESS_SHARED);
	default:
		return EINVAL;
	}
}

int
_pthread_cancel(pthread_t tid)
{
	return __pthread_cancel(tid);
}

int
_pthread_cond_broadcast(pthread_cond_t **cond)
{
	int ret;

	if (cond == NULL)
		return EINVAL;
	if (*cond == NULL) {
		ret = alloccond(cond);
		if (ret != 0)
			return ret;
	}
	return __pthread_cond_broadcast(*cond);
}

int
_pthread_cond_destroy(pthread_cond_t **cond)
{
	int ret;

	if (cond == NULL || *cond == NULL)
		return EINVAL;
	ret = __pthread_cond_destroy(*cond);
	if (ret == 0) {
		free(*cond);
		*cond = NULL;
	}
	return ret;
}

int
_pthread_cond_init(pthread_cond_t **cond,
		   pthread_condattr_t **cattr)
{
	int ret;
	pthread_cond_t *res;

	if (cond == NULL)
		return EINVAL;
	res = malloc(sizeof(pthread_cond_t));
	if (res == NULL)
		return ENOMEM;
	ret = __pthread_cond_init(res, cattr != NULL ? *cattr : NULL);
	if (ret == 0)
		*cond = res;
	else
		free(res);
	return ret;
}

int
_pthread_cond_signal(pthread_cond_t **cond)
{
	int ret;

	if (cond == NULL)
		return EINVAL;
	if (*cond == NULL) {
		ret = alloccond(cond);
		if (ret != 0)
			return ret;
	}
	return __pthread_cond_signal(*cond);
}

int
_pthread_cond_timedwait(pthread_cond_t **cond,
			pthread_mutex_t **mutex,
			const struct timespec *timespec)
{
	int ret;

	if (cond == NULL || mutex == NULL)
		return EINVAL;
	if (*cond == NULL) {
		ret = alloccond(cond);
		if (ret != 0)
			return ret;
	}
	if (*mutex == NULL) {
		ret = allocmutex(mutex);
		if (ret != 0)
			return ret;
	}
	return __pthread_cond_timedwait(*cond, *mutex, timespec);
}

int
_pthread_cond_wait(pthread_cond_t **cond,
		   pthread_mutex_t **mutex)
{
	int ret;

	if (cond == NULL || mutex == NULL)
		return EINVAL;
	if (*cond == NULL) {
		ret = alloccond(cond);
		if (ret != 0)
			return ret;
	}
	if (*mutex == NULL) {
		ret = allocmutex(mutex);
		if (ret != 0)
			return ret;
	}
	return __pthread_cond_wait(*cond, *mutex);
}

int
_pthread_condattr_destroy(pthread_condattr_t **cattr)
{
	int ret;

	if (cattr == NULL || *cattr == NULL)
		return EINVAL;
	ret = __pthread_condattr_destroy(*cattr);
	if (ret == 0) {
		free(*cattr);
		*cattr = NULL;
	}
	return ret;
}

int
_pthread_condattr_getpshared(const pthread_condattr_t **rwattr,
			     int *pshared)
{
	int ret;
	int lshared;

	if (rwattr == NULL || *rwattr == NULL || pshared == NULL)
		return EINVAL;
	ret = __pthread_condattr_getpshared(*rwattr, &lshared);
	if (ret == 0) {
		switch (lshared) {
		case PTHREAD_PROCESS_PRIVATE:
			*pshared = UTHREAD_PTHREAD_PROCESS_PRIVATE;
			break;
		case PTHREAD_PROCESS_SHARED:
			*pshared = UTHREAD_PTHREAD_PROCESS_SHARED;
			break;
		default:
			ret = EINVAL;
		}
	}
	return ret;
}

int
_pthread_condattr_init(pthread_condattr_t **cattr)
{
	pthread_condattr_t *res;
	int ret;

	if (cattr == NULL)
		return EINVAL;
	res = malloc(sizeof(pthread_condattr_t));
	if (res == NULL)
		return ENOMEM;
	ret = __pthread_condattr_init(res);
	if (ret == 0)
		*cattr = res;
	else
		free(res);
	return ret;
}

int
_pthread_condattr_setpshared(pthread_condattr_t **cattr,
			       int pshared)
{
	if (cattr == NULL || *cattr == NULL)
		return EINVAL;
	switch (pshared) {
	case UTHREAD_PTHREAD_PROCESS_PRIVATE:
		return __pthread_condattr_setpshared(*cattr,
						     PTHREAD_PROCESS_PRIVATE);
	case UTHREAD_PTHREAD_PROCESS_SHARED:
		return __pthread_condattr_setpshared(*cattr,
						     PTHREAD_PROCESS_SHARED);
	default:
		return EINVAL;
	}
}

int
_pthread_create(pthread_t *tid,
		const pthread_attr_t **attr,
		void *(*startfunc)(void *),
		void *arg)
{
	return __pthread_create(tid,
				attr != NULL ? *attr : NULL,
				startfunc,
				arg);
}

int
_pthread_detach(pthread_t tid)
{
	return __pthread_detach(tid);
}

int
_pthread_equal(pthread_t tid1, pthread_t tid2)
{
	return __pthread_equal(tid1, tid2);
}

void
_pthread_exit(void *retval)
{
	__pthread_exit(retval);
}

int
_pthread_getconcurrency(void)
{
	return __pthread_getconcurrency();
}

int
_pthread_getcpuclockid(pthread_t tid, clockid_t *clockid)
{
	return EINVAL;
}

int
_pthread_getschedparam(pthread_t tid, int *policy, struct sched_param *sparam)
{
	if (sparam == NULL || policy == NULL)
		return EINVAL;
	return __pthread_getschedparam(tid, policy, sparam);
}

void *
_pthread_getspecific(pthread_key_t key)
{
	return __pthread_getspecific(key);
}

int
_pthread_join(pthread_t tid, void **treturn)
{
	return __pthread_join(tid, treturn);
}

int
_pthread_key_create(pthread_key_t *key, void (*destructor) (void *))
{
	return __pthread_key_create(key, destructor);
}

int
_pthread_key_delete(pthread_key_t key)
{
	return __pthread_key_delete(key);
}

int
_pthread_kill(pthread_t tid, int signo)
{
	return __pthread_kill(tid, signo);
}

int
_pthread_mutex_destroy(pthread_mutex_t **mutex)
{
	int ret;
	
	if (mutex == NULL || *mutex == NULL)
		return EINVAL;
	ret = __pthread_mutex_destroy(*mutex);
	if (ret == 0) {
		free(*mutex);
		*mutex = NULL;
	}
	return ret;
}

int
_pthread_mutex_init(pthread_mutex_t **mutex, const pthread_mutexattr_t **mattr)
{
	int ret;
	pthread_mutex_t *res;

	if (mutex == NULL)
		return EINVAL;
	res = malloc(sizeof(pthread_mutex_t));
	if (res == NULL)
		return ENOMEM;
	ret = __pthread_mutex_init(res, mattr != NULL ? *mattr : NULL);
	if (ret == 0)
		*mutex = res;
	else
		free(res);
	return ret;
}

int
_pthread_mutex_lock(pthread_mutex_t **mutex)
{
	int ret;

	if (mutex == NULL)
		return EINVAL;
	if (*mutex == NULL) {
		ret = allocmutex(mutex);
		if (ret != 0)
			return ret;
	}
	return __pthread_mutex_lock(*mutex);
}

int
_pthread_mutex_timedlock(pthread_mutex_t **mutex,
			 const struct timespec *abstime)
{
	int ret;

	if (mutex == NULL)
		return EINVAL;
	if (*mutex == NULL) {
		ret = allocmutex(mutex);
		if (ret != 0)
			return ret;
	}
	return __pthread_mutex_timedlock(*mutex, abstime);
}

int
_pthread_mutex_trylock(pthread_mutex_t **mutex)
{
	int ret;

	if (mutex == NULL)
		return EINVAL;
	if (*mutex == NULL) {
		ret = allocmutex(mutex);
		if (ret != 0)
			return ret;
	}
	return __pthread_mutex_trylock(*mutex);
}

int
_pthread_mutex_unlock(pthread_mutex_t **mutex)
{
	if (mutex == NULL || *mutex == NULL)
		return EINVAL;
	return __pthread_mutex_unlock(*mutex);
}

int
_pthread_mutexattr_destroy(pthread_mutexattr_t **mattr)
{
	int ret;

	if (mattr == NULL || *mattr == NULL)
		return EINVAL;
	ret = __pthread_mutexattr_destroy(*mattr);
	if (ret == 0) {
		free(*mattr);
		*mattr = NULL;
	}
	return ret;
}

int
_pthread_mutexattr_getpshared(const pthread_mutexattr_t **mattr, int *pshared)
{
	int ret;
	int lshared;

	if (mattr == NULL || *mattr == NULL || pshared == NULL)
		return EINVAL;
	ret = __pthread_mutexattr_getpshared(*mattr, &lshared);
	if (ret == 0) {
		switch (lshared) {
		case PTHREAD_PROCESS_PRIVATE:
			*pshared = UTHREAD_PTHREAD_PROCESS_PRIVATE;
			break;
		case PTHREAD_PROCESS_SHARED:
			*pshared = UTHREAD_PTHREAD_PROCESS_SHARED;
			break;
		default:
			ret = EINVAL;
		}
	}
	return ret;
}

int
_pthread_mutexattr_gettype(const pthread_mutexattr_t **mattr, int *type)
{
	int ret;
	int ltype;

	if (mattr == NULL || *mattr == NULL || type == NULL)
		return EINVAL;
	ret = __pthread_mutexattr_gettype(*mattr, &ltype);
	if (ret == 0) {
		switch (ltype) {
		case PTHREAD_MUTEX_ERRORCHECK:
			*type = UTHREAD_PTHREAD_MUTEX_ERRORCHECK;
			break;
		case PTHREAD_MUTEX_RECURSIVE:
			*type = UTHREAD_PTHREAD_MUTEX_RECURSIVE;
			break;
		case PTHREAD_MUTEX_NORMAL:
			*type = UTHREAD_PTHREAD_MUTEX_NORMAL;
			break;
		default:
			return EINVAL;
		}
	}
	return ret;
}

int
_pthread_mutexattr_init(pthread_mutexattr_t **mattr)
{
	pthread_mutexattr_t *res;
	int ret;
	
	if (mattr == NULL)
		return EINVAL;
	res = malloc(sizeof(pthread_mutexattr_t));
	if (res == NULL)
		return ENOMEM;
	ret = __pthread_mutexattr_init(res);
	if (ret == 0)
		*mattr = res;
	else
		free(res);
	return ret;
}

int
_pthread_mutexattr_setpshared(pthread_mutexattr_t **mattr,
			      int pshared)
{
	if (mattr == NULL || *mattr == NULL)
		return EINVAL;
	switch (pshared) {
	case UTHREAD_PTHREAD_PROCESS_PRIVATE:
		return __pthread_mutexattr_setpshared(*mattr,
						      PTHREAD_PROCESS_PRIVATE);
	case UTHREAD_PTHREAD_PROCESS_SHARED:
		return __pthread_mutexattr_setpshared(*mattr,
						      PTHREAD_PROCESS_SHARED);
	default:
		return EINVAL;
	}
}

int
_pthread_mutexattr_settype(pthread_mutexattr_t **mattr, int type)
{
	if (mattr == NULL || *mattr == NULL)
		return EINVAL;
	switch (type) {
	case UTHREAD_PTHREAD_MUTEX_ERRORCHECK:
		return __pthread_mutexattr_settype(*mattr,
						   PTHREAD_MUTEX_ERRORCHECK);
	case UTHREAD_PTHREAD_MUTEX_RECURSIVE:
		return __pthread_mutexattr_settype(*mattr,
						   PTHREAD_MUTEX_ERRORCHECK);
	case UTHREAD_PTHREAD_MUTEX_NORMAL:
		return __pthread_mutexattr_settype(*mattr,
						   PTHREAD_MUTEX_NORMAL);
	default:
		return EINVAL;
	}
}

int
_pthread_once(uthread_pthread_once_t *once_control,
	      void (*init_routine) (void))
{
	if (once_control->state == UTHREAD_PTHREAD_NEEDS_INIT) {
		_pthread_mutex_lock(&(once_control->mutex));
		if (once_control->state == UTHREAD_PTHREAD_NEEDS_INIT) {
			init_routine();
			once_control->state = UTHREAD_PTHREAD_DONE_INIT;
		}
		_pthread_mutex_unlock(&(once_control->mutex));
	}
	return (0);
}

int
_pthread_rwlock_destroy(pthread_rwlock_t **rwlock)
{
	int ret;

	if (rwlock == NULL || *rwlock == NULL)
		return EINVAL;
	ret = __pthread_rwlock_destroy(*rwlock);
	if (ret == 0) {
		free(*rwlock);
		*rwlock = NULL;
	}
	return ret;
}

int
_pthread_rwlock_init(pthread_rwlock_t **rwlock,
		     const pthread_rwlockattr_t **rwlockattr)
{
	pthread_rwlock_t *res;
	int ret;

	if (rwlock == NULL)
		return EINVAL;
	res = malloc(sizeof(pthread_rwlock_t));
	if (res == NULL)
		return ENOMEM;
	ret = __pthread_rwlock_init(res,
				    rwlockattr != NULL ? *rwlockattr : NULL);
	if (ret == 0)
		*rwlock = res;
	else
		free(res);
	return ret;
}

int
_pthread_rwlock_rdlock(pthread_rwlock_t **rwlock)
{
	int ret;

	if (rwlock == NULL)
		return EINVAL;
	if (*rwlock == NULL) {
		ret = allocrwlock(rwlock);
		if (ret != 0)
			return ret;
	}
	return __pthread_rwlock_rdlock(*rwlock);
}

int
_pthread_rwlock_timedrdlock(pthread_rwlock_t **rwlock,
			    const struct timespec *abstime)
{
	int ret;

	if (rwlock == NULL)
		return EINVAL;
	if (*rwlock == NULL) {
		ret = allocrwlock(rwlock);
		if (ret != 0)
			return ret;
	}
	return __pthread_rwlock_timedrdlock(*rwlock, abstime);
}

int
_pthread_rwlock_timedwrlock(pthread_rwlock_t **rwlock,
			    const struct timespec *abstime)
{
	int ret;

	if (rwlock == NULL)
		return EINVAL;
	if (*rwlock == NULL) {
		ret = allocrwlock(rwlock);
		if (ret != 0)
			return ret;
	}
	return __pthread_rwlock_timedwrlock(*rwlock, abstime);
}

int
_pthread_rwlock_tryrdlock(pthread_rwlock_t **rwlock)
{
	int ret;

	if (rwlock == NULL)
		return EINVAL;
	if (*rwlock == NULL) {
		ret = allocrwlock(rwlock);
		if (ret != 0)
			return ret;
	}
	return __pthread_rwlock_tryrdlock(*rwlock);
}

int
_pthread_rwlock_trywrlock(pthread_rwlock_t **rwlock)
{
	int ret;

	if (rwlock == NULL)
		return EINVAL;
	if (*rwlock == NULL) {
		ret = allocrwlock(rwlock);
		if (ret != 0)
			return ret;
	}
	return __pthread_rwlock_trywrlock(*rwlock);
}

int
_pthread_rwlock_unlock(pthread_rwlock_t **rwlock)
{
	if (rwlock == NULL || *rwlock == NULL)
		return EINVAL;
	return __pthread_rwlock_unlock(*rwlock);
}

int
_pthread_rwlock_wrlock(pthread_rwlock_t **rwlock)
{
	int ret;

	if (rwlock == NULL)
		return EINVAL;
	if (*rwlock == NULL) {
		ret = allocrwlock(rwlock);
		if (ret != 0)
			return ret;
	}
	return __pthread_rwlock_wrlock(*rwlock);
}

int
_pthread_rwlockattr_destroy(pthread_rwlockattr_t **rwattr)
{
	int ret;

	if (rwattr == NULL || *rwattr == NULL)
		return EINVAL;
	ret = __pthread_rwlockattr_destroy(*rwattr);
	if (ret == 0) {
		free(*rwattr);
		*rwattr = NULL;
	}
	return ret;
}

int
_pthread_rwlockattr_getpshared(const pthread_rwlockattr_t **rwattr,
			       int *pshared)
{
	int ret;
	int lshared;

	if (rwattr == NULL || *rwattr == NULL || pshared == NULL)
		return EINVAL;
	ret = __pthread_rwlockattr_getpshared(*rwattr, &lshared);
	if (ret == 0) {
		switch (lshared) {
		case PTHREAD_PROCESS_PRIVATE:
			*pshared = UTHREAD_PTHREAD_PROCESS_PRIVATE;
			break;
		case PTHREAD_PROCESS_SHARED:
			*pshared = UTHREAD_PTHREAD_PROCESS_SHARED;
			break;
		default:
			ret = EINVAL;
		}
	}
	return ret;
}

int
_pthread_rwlockattr_init(pthread_rwlockattr_t **rwattr)
{
	pthread_rwlockattr_t *res;
	int ret;

	if (rwattr == NULL)
		return EINVAL;
	res = malloc(sizeof(pthread_rwlockattr_t));
	if (res == NULL)
		return ENOMEM;
	ret = __pthread_rwlockattr_init(res);
	if (ret == 0)
		*rwattr = res;
	else
		free(res);
	return ret;
}

int
_pthread_rwlockattr_setpshared(pthread_rwlockattr_t **rwattr,
			       int pshared)
{
	if (rwattr == NULL || *rwattr == NULL)
		return EINVAL;
	switch (pshared) {
	case UTHREAD_PTHREAD_PROCESS_PRIVATE:
		return __pthread_rwlockattr_setpshared(*rwattr,
						     PTHREAD_PROCESS_PRIVATE);
	case UTHREAD_PTHREAD_PROCESS_SHARED:
		return __pthread_rwlockattr_setpshared(*rwattr,
						       PTHREAD_PROCESS_SHARED);
	default:
		return EINVAL;
	}
}

pthread_t
_pthread_self(void)
{
	return __pthread_self();
}

int
_pthread_setcancelstate(int newstate, int *oldstate)
{
	int ret;
	int lold;
	
	switch (newstate) {
	case UTHREAD_PTHREAD_CANCEL_ENABLE:
		ret = __pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, &lold);
		break;
	case UTHREAD_PTHREAD_CANCEL_DISABLE:
		ret = __pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &lold);
		break;
	default:
		ret = EINVAL;
	}
	if (ret == 0 && oldstate != NULL) {
		switch (lold) {
		case PTHREAD_CANCEL_ENABLE:
			*oldstate = UTHREAD_PTHREAD_CANCEL_ENABLE;
			break;
		case PTHREAD_CANCEL_DISABLE:
			*oldstate = UTHREAD_PTHREAD_CANCEL_DISABLE;
			break;
		default:
			ret = EINVAL;
		}
	}
	return ret;
}

int
_pthread_setcanceltype(int newtype, int *oldtype)
{
	int ret;
	int lold;
	
	switch (newtype) {
	case UTHREAD_PTHREAD_CANCEL_DEFERRED:
		ret = __pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, &lold);
		break;
	case UTHREAD_PTHREAD_CANCEL_ASYNCHRONOUS:
		ret = __pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, &lold);
		break;
	default:
		ret = EINVAL;
	}
	if (ret == 0 && oldtype != NULL) {
		switch (lold) {
		case PTHREAD_CANCEL_DEFERRED:
			*oldtype = UTHREAD_PTHREAD_CANCEL_DEFERRED;
			break;
		case PTHREAD_CANCEL_ASYNCHRONOUS:
			*oldtype = UTHREAD_PTHREAD_CANCEL_ASYNCHRONOUS;
			break;
		default:
			ret = EINVAL;
		}
	}
	return ret;
}

int
_pthread_setconcurrency(int level)
{
	return __pthread_setconcurrency(level);
}

int
_pthread_setschedparam(pthread_t tid, int policy,
		       const struct sched_param *sparam)
{
	return __pthread_setschedparam(tid, policy, sparam);
}

int
_pthread_setspecific(pthread_key_t key, const void *value)
{
	return __pthread_setspecific(key, value);
}

int
_pthread_sigmask(int how, const sigset_t *set, sigset_t *oset)
{
	return __pthread_sigmask(how, set, oset);
}

void
_pthread_testcancel(void)
{
	__pthread_testcancel();
}

#ifdef LINUXTHREADS_WRAP_API

#include "internals.h"

void linuxthreads__pthread_cleanup_pop(struct _pthread_cleanup_buffer *buf,
				       int execute);
void linuxthreads__pthread_cleanup_push(struct _pthread_cleanup_buffer *buf,
					void (*)(void *),
					void *);

void wrap_pthread_cleanup_pop(int) __asm__("_pthread_cleanup_pop");

void wrap_pthread_cleanup_push(void (*)(void *), void *) __asm__("_pthread_cleanup_push");

#undef pthread_cleanup_pop
#undef pthread_cleanup_push
	
extern int pthread_cleanup_pop(int) __attribute__ ((weak, alias("_pthread_cleanup_pop")));

extern int pthread_cleanup_push(void (*)(void *), void *) __attribute__ ((weak, alias("_pthread_cleanup_push")));

struct wrap_pthread_cleanup_buffer {
	struct _pthread_cleanup_buffer _buf;
	void (*func)(void *);
	void *arg;
	void *nextfree;
};
	

static pthread_mutex_t cleanup_mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_key_t cleanup_key = (pthread_key_t) -1;
static void free_cleanup_buffers(void *arg);

static struct wrap_pthread_cleanup_buffer *
alloc_cleanup_buffer(void)
{
	struct wrap_pthread_cleanup_buffer *buf;

	if (cleanup_key == (pthread_key_t) -1) {
		__pthread_mutex_lock(&cleanup_mutex);
		if (cleanup_key == (pthread_key_t) -1) {
			if (__pthread_key_create(&cleanup_key,
						 free_cleanup_buffers) < 0) {
				__pthread_mutex_unlock(&cleanup_mutex);
				abort();
			}
		}
		__pthread_mutex_unlock(&cleanup_mutex);
	}
	buf = __pthread_getspecific(cleanup_key);
	if (buf == NULL) {
		buf = (struct wrap_pthread_cleanup_buffer *) 
			malloc(sizeof(struct wrap_pthread_cleanup_buffer));
	} else {
		__pthread_setspecific(cleanup_key, buf->nextfree);
	}
	if (buf != NULL) {
		buf->nextfree = NULL;
	}
	return buf;
}


static void
stash_cleanup_buffer(struct wrap_pthread_cleanup_buffer *buf)
{
	buf->nextfree = __pthread_getspecific(cleanup_key);
	__pthread_setspecific(cleanup_key, buf);
}

static void
free_cleanup_buffers(void *arg)
{
	struct wrap_pthread_cleanup_buffer *buf;
	struct wrap_pthread_cleanup_buffer *nbuf;
	
	buf = (struct wrap_pthread_cleanup_buffer *) arg;
	while (buf != NULL) {
		nbuf = buf->nextfree;
		free(buf);
		buf = nbuf;
	}
}

static void
wrap_cleanup(void *arg)
{
	struct wrap_pthread_cleanup_buffer *buf;
	
	buf = (struct wrap_pthread_cleanup_buffer *) arg;
	buf->func(buf->arg);

	/* Cannot free buffer yet ==> stash it on a thread specific freelist */
	stash_cleanup_buffer(buf);
}

void
wrap_pthread_cleanup_pop(int execute)
{
	pthread_descr self;
	struct _pthread_cleanup_buffer *buf;

	self = thread_self();
	buf = THREAD_GETMEM(self, p_cleanup);

	linuxthreads__pthread_cleanup_pop(buf, execute);
}

void
wrap_pthread_cleanup_push(void (*func)(void *),
			  void *arg)
{
	struct wrap_pthread_cleanup_buffer *buf;
	
	buf = alloc_cleanup_buffer();
	buf->func = func;
	buf->arg = arg;
	linuxthreads__pthread_cleanup_push(&buf->_buf, 
					   wrap_cleanup,
					   buf);
}
#endif
