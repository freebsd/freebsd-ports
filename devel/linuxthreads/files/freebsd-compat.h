#include <poll.h>
#include <bits/local_lim.h>
#include <sys/queue.h>
#include <sched.h>
#include <sys/types.h>
#include <sys/time.h>


#define __libc_close _close
#define __libc_nanosleep _nanosleep
#define __libc_read _read
#define __libc_waitpid waitpid
#define __libc_write _write
#define __libc_longjmp __longjmp
#define __libc_siglongjmp __siglongjmp
#define __libc_fork _fork
#define __libc_current_sigrtmin current_sigrtmin
#define __libc_current_sigrtmax current_sigrtmax
#define __libc_allocate_rtsig allocate_rtsig
#define __getpagesize getpagesize
#define __sched_param sched_param
#define __sched_get_priority_min sched_get_priority_min
#define __sched_get_priority_max sched_get_priority_max
#define __sched_setscheduler sched_setscheduler
#define __sched_getscheduler sched_getscheduler
#define __sched_getparam sched_getparam
#define __gettimeofday _gettimeofday
#define __poll _poll
#define __getpid _getpid
#define __jmp_buf jmp_buf
#define __sigaction _sigaction
#define _h_errno h_errno
#define __ptr_t void *
#define __pid_t pid_t

#ifndef __P
#   define __P(args)	args
#endif

#ifndef __PMT
#  define __PMT(args)	args
#endif

# define strong_alias(name, aliasname) \
  extern __typeof (name) aliasname __attribute__ ((alias (#name)));

#  define weak_alias(name, aliasname) \
  extern __typeof (name) aliasname __attribute__ ((weak, alias (#name)));

#define ENOTSUP EOPNOTSUPP

#define __builtin_expect(x,y) (x) == (y)
#define internal_function


#undef PAGE_SIZE 
#define PAGE_SIZE getpagesize()

#define MAP_ANONYMOUS MAP_ANON
#define MAP_GROWSDOWN MAP_STACK

#define __WCLONE WLINUXCLONE

#define SIGCONTEXT struct sigcontext * 
#define SIGCONTEXT_EXTRA_ARGS

# define __WAIT_STATUS_DEFN	int *

# define __SOCKADDR_ARG		struct sockaddr *
# define __CONST_SOCKADDR_ARG	__const struct sockaddr *

#define __ptr_t void *
#define __pid_t pid_t

/* Test if longjmp to JMPBUF would unwind the frame
   containing a local variable at ADDRESS.  */

/* XXXX check this for FreeBSD */
/* i386 only */
#define JB_SP	2
#define _JMPBUF_UNWINDS(jmpbuf, address) \
  ((void *) (address) < (void *) ((int *)(jmpbuf[0]._jb[JB_SP]))[1])

#define spinlock_t int
#define _SPINLOCK_INITIALIZER 0
#define _SPINLOCK(x) __pthread_acquire(x)
#define _SPINUNLOCK(x) *(x) = 0
/*#define TEST_FOR_COMPARE_AND_SWAP*/

#define __set_errno(val) errno = (val)

#define DEFAULT_PRIORITY 20

void	__libc_longjmp __P((jmp_buf, int)) __dead2;
void	__libc_siglongjmp __P((sigjmp_buf, int)) __dead2;

int	_gettimeofday __P((struct timeval *, struct timezone *));
pid_t	_getpid __P((void));
int	_sigaction __P((int, const struct sigaction *, struct sigaction *));
int	_poll __P((struct pollfd *_pfd, unsigned _nfds, int _timeout));

#include "clone.h"


