$FreeBSD$

--- ../src/solaris/hpi/native_threads/src/threads_bsd.c	7 Feb 2002 05:19:54 -0000	1.12
+++ ../src/solaris/hpi/native_threads/src/threads_bsd.c	25 Feb 2003 16:31:54 -0000
@@ -22,32 +22,23 @@
 #include "np.h"
 
 #include <pthread.h>
+#include <pthread_np.h>
 
 #if defined(__FreeBSD__)
 
-#include <pthread_np.h>
+#include <assert.h>
 
-/* Remove defines from pthread.h so pthread_private.h can be included */
-#undef pthread_condattr_default
-#undef pthread_mutexattr_default
 #undef pthread_attr_default
+#undef pthread_mutexattr_default
+#undef pthread_condattr_default
 #include "pthread_private.h"
 
-#include <assert.h>
-#include <ucontext.h>
-#include <machine/ucontext.h>
-
-#include <sys/exec.h>
-#include <vm/vm.h>
-#include <vm/pmap.h>
-#include <machine/pmap.h>
-#include <machine/vmparam.h>
-
 #endif
 
 #include <string.h>
 #include <signal.h>
 #include <sys/signal.h>
+#include <sys/time.h>
 #include <sys/resource.h>
 #include <stdlib.h>
 #include <string.h>
@@ -63,14 +54,9 @@
 /* Private functions used to implement native threading. --billh */
 
 #ifdef DEBUG_BSD_NATIVE_THREADS
-void _pthread_suspend_all_np(void);
-void _pthread_resume_all_np(void);
-#endif
-void record_uc(sys_thread_t *, ucontext_t *);
-void record_gc_registers_of(sys_thread_t *);
-
-void dumpThreadStates();
 void dumpThreadLogStates(pthread_t);
+void dumpThreadStates();
+#endif
 
 /*
  * Suspend a thread.  Used to implement java.lang.Thread.suspend(),
@@ -108,28 +94,24 @@
 int
 np_stackinfo(void **addr, long *sizep)
 {
-    thread_t self = pthread_self();
-    int base;
-    int size;
-
-    if (!pthread_equal(self, _thread_initial)) {
-        *addr = self->stack;
-	*sizep = (long) PTHREAD_STACK_DEFAULT;
-
-    } else {
-	/* in main()'s thread */
-	struct rlimit r;
-
-	if (getrlimit(RLIMIT_STACK, &r) == -1)
-	    return SYS_ERR;
-
-	/* PS_STRINGS is also from sys/exec.h in FreeBSD, but as macro. --billh */
-
-	*addr  = (void *) (PS_STRINGS +1);
-	*sizep = (long)r.rlim_cur;
-    }
+    pthread_attr_t attr;
+    size_t size;
 
+    if ((errno = pthread_attr_init(&attr)))
+	return SYS_ERR;
+    if ((errno = pthread_attr_get_np(pthread_self(), &attr)))
+	goto err;
+    if ((errno = pthread_attr_getstackaddr(&attr, addr)))
+	goto err;
+    if ((errno = pthread_attr_getstacksize(&attr, &size)))
+	goto err;
+    *sizep = size;
+    pthread_attr_destroy(&attr);
     return SYS_OK;
+
+err:
+    pthread_attr_destroy(&attr);
+    return SYS_ERR;
 }
 
 /*
@@ -177,7 +159,7 @@
 	Do this for the FreeBSD implementation too, since this is a silly
 	function anyways.  --billh
 */
-	return TRUE;
+    return TRUE;
 }
 
 
@@ -190,38 +172,54 @@
 static void
 record_thread_regs()
 {
-    sys_thread_t *tid;
+    struct pthread *self = pthread_self();
+    sys_thread_t *tid = ThreadQueue;
     int i;
-    int sp;
 
-    tid = ThreadQueue;
-    for (i = 0; i < ActiveThreadCount && tid != 0; i++) {
-	int i;
-
-	if (tid->sys_thread != 0) {
-#ifdef __bsdi__
-	    /* if thread has already been initialized */
-	    if (pthread_getstackpointer_np(tid->sys_thread, &sp) == 0)
-		tid->sp = sp;
-	    else
-		tid->sp = 0;
-#elif __FreeBSD__
-#endif
-            tid->sp = tid->sys_thread->stack;
-//#endif	//__FreeBSD__
-/*	Potential race here if the stack isn't setup before GC. --billh */
-	} else {
+    for (i = 0; i < ActiveThreadCount && tid != NULL; i++, tid = tid->next) {
+	struct pthread *thread = tid->sys_thread;
+
+	if (thread == 0) {
 	    /*
 	     * thread is still in the process of being initalized.
 	     * So GC should not care about this thread. Just
 	     * set its sp to 0, and this will force GC to ignore it.
 	     */
 	    tid->sp = 0;
+	    continue;
 	}
 
-	record_gc_registers_of(tid);
+        tid->sp = thread->stack;
+/*	Potential race here if the stack isn't setup before GC. --billh */
 
-	tid = tid->next;
+	/*
+	 * The thread that calls this function will alway be the JVM GC thread,
+	 * so skip over it in the list of threads.
+	 */
+	if (thread != self && (thread->flags & PTHREAD_FLAGS_PRIVATE) == 0) {
+	    register_t *regbase;
+
+#ifdef DEBUG_BSD_NATIVE_THREADS
+	    /*
+	     * Got search candidate..
+	     */
+	    if (thread->state != PS_SUSPENDED)
+		dumpThreadLogStates(thread);
+#endif
+
+	    regbase = (register_t*) &thread->ctx.jb[0];
+	    tid->regs[0] = regbase[6];	/* eax */
+	    tid->regs[1] = 0;		/* ecx (missing) */
+	    tid->regs[2] = 0;		/* edx (missing) */
+	    tid->regs[3] = regbase[1];	/* ebx */
+	    tid->regs[4] = regbase[3];	/* ebp */
+	    tid->regs[5] = regbase[4];	/* esi */
+	    tid->regs[6] = regbase[5];	/* edi */
+
+#ifdef DEBUG_BSD_NATIVE_THREADS
+	    dumpThreadStates();
+#endif
+	}
     }
 
 #ifdef DEBUG_BSD_NATIVE_THREADS
@@ -239,14 +237,7 @@
 {
     sysAssert(SYS_QUEUE_LOCKED(sysThreadSelf()));
 
-#ifdef DEBUG_BSD_NATIVE_THREADS
-    _pthread_suspend_all_np();
-#else
-    pthread_single_np();
-#endif
-
-//usleep(100000 *3);
-
+    pthread_suspend_all_np();
     record_thread_regs();
     return SYS_OK;
 }
@@ -259,42 +250,13 @@
 np_multi(void)
 {
     sysAssert(SYS_QUEUE_LOCKED(sysThreadSelf()));
-#ifdef DEBUG_BSD_NATIVE_THREADS
-    _pthread_resume_all_np();
-#else
-    pthread_multi_np();
-#endif
+    pthread_resume_all_np();
 }
 
-
-
-
+#ifdef DEBUG_BSD_NATIVE_THREADS
 /* pthreads hackery begins --billh */
 
-#define ANALRETENTIVE (6 + 1)
-
-char SuspendList[ANALRETENTIVE][16] = 
-{
-	"SUSP_NO",		/* Not suspended. */
-	"SUSP_YES",		/* Suspended. */
-	"SUSP_JOIN",		/* Suspended, joining. */  
-	"SUSP_NOWAIT",		/* Suspended, was in a mutex or condition queue. */
-	"SUSP_MUTEX_WAIT",	/* Suspended, still in a mutex queue. */
-	"SUSP_COND_WAIT",	/* Suspended, still in a condition queue. */
-	"susp boundless"
-};
-
-char *getSuspendStateString(enum pthread_susp suspendState)
-{
-	if (suspendState < ANALRETENTIVE)
-		return &SuspendList[suspendState][0];
-	else 
-		return &SuspendList[ANALRETENTIVE-1][0];
-}
-
-#define SATAN (21 + 1) /* for the error string at the end of the list */
-
-char SignalList [SATAN][16]
+char SignalList [][16]
 =
 {
 	"PS_RUNNING",
@@ -316,18 +278,17 @@
 	"PS_JOIN",
 	"PS_SUSPENDED",
 	"PS_DEAD",
-	"PS_DEADLCK",
+	"PS_DEADLOCK",
 	"PS_STATE_MAX",
-	"PS_REQUEST_WAITING_SUSPENDED",
 	"boundless"
 };
 
 char *getThreadStateString(enum pthread_state threadState)
 {
 	if (threadState < SATAN)
-		return &SignalList[threadState][0];
-	else 
-		return &SignalList[SATAN-1][0];
+		return SignalList[threadState];
+	else
+		return SignalList[SATAN-1];
 }
 
 void dumpThreadStates()
@@ -336,114 +297,29 @@
 	struct pthread	*thread;
 	struct pthread	*self = pthread_self();
 
-#ifdef DEBUG_BSD_NATIVE_THREADS
 	_thread_kern_sig_defer();
 	TAILQ_FOREACH(thread, &_thread_list, tle) {
 		if (thread != self) { /* special case this --billh */
-			printf("\tthread %d\t%s\t%s\n",
+			printf("\tthread %d\t%s\n",
 				threadCount,
-				getThreadStateString(thread->state),
-				getSuspendStateString(thread->suspended));
+				getThreadStateString(thread->state));
 
 			if (thread->state != PS_SUSPENDED)
 				dumpThreadLogStates(thread);
-		}
-		else
-		{
-			printf("\tgc thread %d\t%s\t%s\n",
+		} else {
+			printf("\tgc thread %d\t%s\n",
 				threadCount,
-				getThreadStateString(thread->state),
-				getSuspendStateString(thread->suspended));
+				getThreadStateString(thread->state))
 		}
 		++threadCount;
 	}
 	_thread_kern_sig_undefer();
 	printf("\n");
-#endif
-}
-
-
-#ifdef DEBUG_BSD_NATIVE_THREADS
-extern void _pthread_suspend_np_by_pthread_common(pthread_t);
-extern void _pthread_resume_by_pthread_common(pthread_t, enum pthread_susp);
-
-void
-_pthread_suspend_all_np(void)
-{
-	struct pthread	*thread;
-	struct pthread	*self = pthread_self();
-
-fprintf(stderr, "pthread_suspend_all_np\n");
-	/*
-	 * Defer signals to protect the scheduling queues from
-	 * access by the signal handler:
-	 */
-	_thread_kern_sig_defer();
-
-	/* Suspend all threads other than the current thread: */
-	TAILQ_FOREACH(thread, &_thread_list, tle) {
-		if (thread != self) {
-			_pthread_suspend_np_by_pthread_common(thread);
-		}
-	}
-
-	/*
-	 * Undefer and handle pending signals, yielding if necessary:
-	 */
-	_thread_kern_sig_undefer();
-fprintf(stderr, "pthread_suspend_all_np END\n");
-}
-
-/* Resume a thread: */
-void
-_pthread_resume_all_np(void)
-{
-	enum		pthread_susp old_suspended;
-	struct pthread	*thread;
-	struct pthread	*self = pthread_self();
-
-fprintf(stderr, "pthread_resume_all_np\n");
-	_thread_kern_sig_defer();
-
-	/*
-		Iterate through the thread list and resume suspended threads.
-		this is copied from pthread_resume_np(). --billh
-	*/
-
-	TAILQ_FOREACH(thread, &_thread_list, tle) {
-		if (thread != self) {
-			/* Cancel any pending suspensions: */
-
-			old_suspended = thread->suspended;
-			thread->suspended = SUSP_NO;
-
-			_pthread_resume_by_pthread_common(thread, old_suspended);
-
-		} // if !thread_self
-	} // TAILQ_FOREACH
-
-	/*
-	 * Undefer and handle pending signals, yielding if
-	 * necessary:
-	 */
-	_thread_kern_sig_undefer();
-fprintf(stderr, "pthread_resume_all_np END\n");
 }
-#endif
 
 /*
 	[A snippet from Dan Eichen's email on the subject]
 
-	It uses _longjmp (non-signal-saving/restoring) for the most part.
-	The only exception is when the process (currently running thread) is 
-	interrupted by a signal.  So your context types are a jmp_buf and
-	a ucontext_t (if interrupted by a signal).  If thread->ctxtype is
-	CTX_UC, the context is stored as a ucontext in thread->ctx.uc.
-	Otherwise, the context is stored as a jmp_buf in thread->ctx.jb.
-	We don't currently use CTX_JB and CTX_SJB, so don't even bother
-	with those cases.  Those should go away actually; all we need
-	to know is if it is a ucontext_t or a jmp_buf.
-
 	You can also look at src/gnu/usr.bin/binutils/gdb/freebsd-uthread.c.
 	It knows how to iterate through all the threads and pull out
 	(and even set) thread contexts.
@@ -462,19 +338,8 @@
 	--billh
 */
 
-void clear_gc_registers(sys_thread_t * jthread)
-{
-/* clear out x86 registers for the thread's "self" --billh */
-
-	jthread->regs[0] = 0; jthread->regs[1] = 0;
-	jthread->regs[2] = 0; jthread->regs[3] = 0;
-	jthread->regs[4] = 0; jthread->regs[5] = 0;
-	jthread->regs[6] = 0;
-}
-
 void dumpThreadLogStates(pthread_t thread)
 {
-#ifdef DEBUG_BSD_NATIVE_THREADS
 int i;
 	for(i=0; i < STATE_LOG_SIZE; ++i)
 	{
@@ -494,311 +359,5 @@
 		}
 	}
 	printf("\t\t***XXX\n");
-#endif
-}
-
-void record_gc_registers_of(sys_thread_t *javaThread)
-{
-struct pthread	*self	= pthread_self();
-struct pthread	*thread	= NULL;
-
-	assert( javaThread != NULL );
-	assert( javaThread->sys_thread != NULL );
-
-	thread = javaThread->sys_thread;
-
-	/*
-	 * The thread that calls this function will alway be the JVM GC thread,
-	 * so skip over it in the list of threads.
-	 */
-	if (	(thread == self)
-		|| ((thread->flags & PTHREAD_FLAGS_PRIVATE) != 1)
-	   )
-	{
-		record_uc(javaThread, &thread->ctx.uc);
-#ifdef DEBUG_BSD_NATIVE_THREADS
-		goto Terminate; // And do nothing with this pthread entry. 
-#endif
-	}
-
-	/*
-	 * Got search candiate..
-	 */
-	if (thread->state != PS_SUSPENDED)
-		dumpThreadLogStates(thread);
-
-	switch ((int)thread->ctxtype)
-	{
-		case CTX_JB_NOSIG:	/* 0) jmp_buf context without signal mask for blocking IO, etc... */
-		case CTX_JB:		/* 1) should never be CTX_JB */
-		case CTX_SJB:		/* 2) should never be CTX_SJB */
-			clear_gc_registers(javaThread);
-#ifdef DEBUG_BSD_NATIVE_THREADS
-			goto Terminate;
-#endif
-			break;
-		case CTX_UC:		/* 3) */
-			/* context is a ucontext_t */
-			record_uc(javaThread, &thread->ctx.uc);
-#ifdef DEBUG_BSD_NATIVE_THREADS
-			goto Terminate;
-#endif
-			break;
-		default:
-#ifdef DEBUG_BSD_NATIVE_THREADS
-			fprintf(stderr, "ctxtype failed %d.\n", thread->ctxtype);
-			goto TermFailed;
-#endif
-			break;
-	}
-
-#ifdef DEBUG_BSD_NATIVE_THREADS
-TermFailed:
-	fprintf(stderr, "Failed to find pthread struct.\n"); fflush(stderr);
-	assert(0);
-
-Terminate:
-	dumpThreadStates();
-#endif
 }
-
-void record_uc(sys_thread_t *t, ucontext_t *uc)
-{
-	mcontext_t *mc = &(uc->uc_mcontext);
-
-	t->regs[0] = mc->mc_eax;
-	t->regs[1] = mc->mc_ecx;
-	t->regs[2] = mc->mc_edx;
-	t->regs[3] = mc->mc_ebx;
-	t->regs[4] = mc->mc_ebp;
-	t->regs[5] = mc->mc_esi;
-	t->regs[6] = mc->mc_edi;
-}
-
-/*
-From /usr/src/lib/libc/i386/gen/_setjmp.S:
-ENTRY(_setjmp)
-	movl	4(%esp),%eax
-	movl	0(%esp),%edx
-	movl	%edx, 0(%eax)	/ * rta * /
-	movl	%ebx, 4(%eax)
-	movl	%esp, 8(%eax)
-	movl	%ebp,12(%eax)
-	movl	%esi,16(%eax)
-	movl	%edi,20(%eax)
-	fnstcw	24(%eax)
-	xorl	%eax,%eax
-	ret
-
-typedef JmpBufStruct
-{
-	int	edx, // Accumulator for operands and results data.
-		ebx, // Pointer to data in the DS segment.
-		esp, // Stack pointer (in the SS segment).
-		ebp, // Pointer to data on the stack (in the SS segment).
-		esi, // Pointer to data in the segment pointer to by the DS register; source pointer for string operations.
-		edi; // Pointer to data (or destination) in the segment pointer to by the ES register; destination pointer for string operations.
-
-} JmpBufStruct;
-
-
-void record_jb(sys_thread_t *t, JmpBufStruct *jb)
-{
-	t->regs[0] = jb->eax; // What about these two register ? they seem missing in jmp_buf.
-	t->regs[1] = / *jb->ecx;* / 0;
-	t->regs[2] = jb->edx; // The rest of these registers are defined...
-	t->regs[3] = jb->ebx;
-	t->regs[4] = jb->ebp;
-	t->regs[5] = jb->esi;
-	t->regs[6] = jb->edi;
-}
-*/
-
-#if 0
-static void
-finish_suspension(void *arg)
-{
-	if (_thread_run->suspended != SUSP_NO)
-		_thread_kern_sched_state(PS_SUSPENDED, __FILE__, __LINE__);
-}
-
-void _pthread_suspend_np_by_pthread_common(pthread_t thread)
-{
-struct timeval  tv;
-struct timespec current_ts;
-
-	switch (thread->state) {
-	case PS_RUNNING:
-		/*
-		 * Remove the thread from the priority queue and
-		 * set the state to suspended:
-		 */
-		PTHREAD_PRIOQ_REMOVE(thread);
-		PTHREAD_SET_STATE(thread, PS_SUSPENDED);
-		break;
-
-	case PS_SPINBLOCK:
-	case PS_FDR_WAIT:
-	case PS_FDW_WAIT:
-	case PS_POLL_WAIT:
-	case PS_SELECT_WAIT:
-		/*
-		 * Remove these threads from the work queue
-		 * and mark the operation as interrupted:
-		 */
-		if ((thread->flags & PTHREAD_FLAGS_IN_WORKQ) != 0)
-			PTHREAD_WORKQ_REMOVE(thread);
-		_thread_seterrno(thread,EINTR);
-
-		/* FALLTHROUGH */
-	case PS_SLEEP_WAIT:
-		thread->interrupted = 1;
-
-		/* FALLTHROUGH */
-	case PS_SIGTHREAD:
-	case PS_WAIT_WAIT:
-	case PS_SIGSUSPEND:
-	case PS_SIGWAIT:
-		/*
-		 * Remove these threads from the waiting queue and
-		 * set their state to suspended:
-		 */
-		PTHREAD_WAITQ_REMOVE(thread);
-		PTHREAD_SET_STATE(thread, PS_SUSPENDED);
-		break;
-
-	case PS_MUTEX_WAIT:
-		/* Mark the thread as suspended and still in a queue. */
-		thread->suspended = SUSP_MUTEX_WAIT;
-
-		PTHREAD_SET_STATE(thread, PS_SUSPENDED);
-		break;
-	case PS_COND_WAIT:
-#if 0
-		/* This is for a pthreads_cond_timedwait() --billh */
-		if (thread->wakeup_time.tv_sec != -1) {
-			/* (1) Use to restore the waiting-queue time that's left when the
-			 * thread is resumed. --billh
-			 */
-			_subtract_timespec3(thread, &current_ts, &thread->remaining_wakeup_time);
-
-			/* (2) So that it's inserted at the end of the waiting queue and
-			 * not scanned by the uthreads_kern.c waiting queue logic. It also
-			 * means to make it wait forever.
-			 */
-			thread->wakeup_time.tv_sec  = -1;
-			thread->wakeup_time.tv_nsec = -1;
-
-			/* (3) Remove and reinsert it at the end of waiting-queue
-			 * (automatic on the insertion attempt when (2)).
-			 */
-			PTHREAD_WORKQ_REMOVE(thread);
-			PTHREAD_WORKQ_INSERT(thread);
-		}
-#endif
-
-		/* Mark the thread as suspended and still in a queue. */
-		thread->suspended = SUSP_COND_WAIT;
-
-		PTHREAD_SET_STATE(thread, PS_SUSPENDED);
-		break;
-	case PS_JOIN:
-		/* Mark the thread as suspended and joining: */
-		thread->suspended = SUSP_JOIN;
-
-		PTHREAD_NEW_STATE(thread, PS_SUSPENDED);
-		break;
-	case PS_FDLR_WAIT:
-	case PS_FDLW_WAIT:
-	case PS_FILE_WAIT:
-		/* Mark the thread as suspended: */
-		thread->suspended = SUSP_YES;
-
-		/*
-		 * Threads in these states may be in queues.
-		 * In order to preserve queue integrity, the
-		 * cancelled thread must remove itself from the
-		 * queue.  Mark the thread as interrupted and
-		 * set the state to running.  When the thread
-		 * resumes, it will remove itself from the queue
-		 * and call the suspension completion routine.
-		 */
-		thread->interrupted = 1;
-		_thread_seterrno(thread, EINTR);
-		PTHREAD_NEW_STATE(thread, PS_RUNNING);
-		thread->continuation = finish_suspension;
-		break;
-
-	case PS_DEAD:
-	case PS_DEADLOCK:
-	case PS_STATE_MAX:
-	case PS_SUSPENDED:
-		/* Nothing needs to be done: */
-		break;
-	}
-}
-
-void _pthread_resume_by_pthread_common(pthread_t thread, enum pthread_susp old_suspended)
-{
-struct timeval  tv;
-struct timespec current_ts,
-		remaining_spec;
-
-	/* Is it currently suspended? */
-	if (thread->state == PS_SUSPENDED) {
-		/*
-		 * Defer signals to protect the scheduling queues
-		 * from access by the signal handler:
-		 */
-		_thread_kern_sig_defer();
-
-		switch (old_suspended) {
-		case SUSP_MUTEX_WAIT:
-			/* Set the thread's state back. */
-			PTHREAD_SET_STATE(thread,PS_MUTEX_WAIT);
-			break;
-		case SUSP_COND_WAIT:
-			/* For cases where it was doing a pthread_cond_timedwait()
-			 * Mark the remaining suspend time.
-			 * --billh
-			 */
-#if 0
-			if (thread->remaining_wakeup_time.tv_sec != -1) {
-				GET_CURRENT_TOD(tv);
-				TIMEVAL_TO_TIMESPEC(&tv, &current_ts);
-
-				_subtract_timespec3(remaining_spec, &thread->wakeup_time, &current_ts);
-				_thread_kern_set_timeout_by_pthread_timespec(thread, &remaining_spec);
-			}
-#endif
-
-			/* Set the thread's state back. */
-			PTHREAD_SET_STATE(thread,PS_COND_WAIT);
-			break;
-		case SUSP_JOIN:
-			/* Set the thread's state back. */
-			PTHREAD_SET_STATE(thread,PS_JOIN);
-			break;
-		case SUSP_NOWAIT:
-			/* Allow the thread to run. */
-			PTHREAD_SET_STATE(thread,PS_RUNNING);
-			PTHREAD_WAITQ_REMOVE(thread);
-			PTHREAD_PRIOQ_INSERT_TAIL(thread);
-			break;
-		case SUSP_NO:
-		case SUSP_YES:
-			/* Allow the thread to run. */
-			PTHREAD_SET_STATE(thread,PS_RUNNING);
-			PTHREAD_PRIOQ_INSERT_TAIL(thread);
-			break;
-		}
-
-		/*
-		 * Undefer and handle pending signals, yielding if
-		 * necessary:
-		 */
-		_thread_kern_sig_undefer();
-	}
-}
-
 #endif
