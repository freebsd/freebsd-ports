#include <poll.h>
#include <bits/local_lim.h>
#include <sys/queue.h>
#include <sched.h>
#include <sys/types.h>
#include <sys/time.h>


#if __FreeBSD__ >= 5
#define __libc_accept __sys_accept
#define __libc_close __sys_close
#define __libc_connect __sys_connect
#define __libc_fcntl __sys_fcntl
#define __libc_fork __sys_fork
#define __libc_fsync __sys_fsync
#define __libc_nanosleep __sys_nanosleep
#define __libc_open __sys_open
#define __libc_read __sys_read
#define __libc_waitpid __waitpid
#define __libc_write __sys_write
#define __libc_longjmp __longjmp
#define __libc_siglongjmp __siglongjmp
#define __libc_msync __sys_msync
#define __libc_recvfrom __sys_recvfrom
#define __libc_recvmsg __sys_recvmsg
#define __libc_sendmsg __sys_sendmsg
#define __libc_sendto __sys_sendto
#define __libc_sigaction __sys_sigaction
#define __libc_poll __sys_poll
#define __libc_getpid __sys_getpid
#else
#define __libc_accept _accept
#define __libc_close _close
#define __libc_connect _connect
#define __libc_fcntl _fcntl
#define __libc_fork _fork
#define __libc_fsync _fsync
#define __libc_nanosleep _nanosleep
#define __libc_open _open
#define __libc_read _read
#define __libc_waitpid __waitpid
#define __libc_write _write
#define __libc_longjmp __longjmp
#define __libc_siglongjmp __siglongjmp
#define __libc_msync _msync
#define __libc_recvfrom _recvfrom
#define __libc_recvmsg _recvmsg
#define __libc_sendmsg _sendmsg
#define __libc_sendto _sendto
#define __libc_sigaction _sigaction
#define __libc_poll _poll
#define __libc_getpid _getpid
#endif
#define __libc_wait __wait
#define __libc_system __system
#define __getpid __libc_getpid
#define __poll __libc_poll
#define __libc_tcdrain __tcdrain
#define __libc_pause __pause
#define __libc_current_sigrtmin current_sigrtmin
#define __libc_current_sigrtmax current_sigrtmax
#define __libc_allocate_rtsig allocate_rtsig
#define __getpagesize getpagesize
int __sched_setparam(pid_t, const struct sched_param *);
int __sched_getparam(pid_t, struct sched_param *);
int __sched_setscheduler(pid_t, int, const struct sched_param *);
int __sched_getscheduler(pid_t);
int __sched_yield(void);
int __sched_get_priority_max(int);
int __sched_get_priority_min(int);
int __sched_rr_get_interval(pid_t, struct timespec *);
#define __gettimeofday _gettimeofday
#define __jmp_buf jmp_buf
#define _h_errno h_errno
#define __ptr_t void *
#define __pid_t pid_t

ssize_t __libc_write(int, const void *, size_t);
ssize_t __libc_read(int, void *, size_t);
pid_t   __libc_waitpid(pid_t wpid, int *status, int options);
int	__libc_poll(struct pollfd *_pfd, unsigned int _nfsd, int _timeout);
pid_t	__libc_getpid(void);
pid_t	__libc_waitpid(pid_t, int *, int);
int	__libc_sigaction(int, const struct sigaction *, struct sigaction *);
int	__libc_fcntl(int, int, ...);
int	__libc_fsync(int);
int     __libc_msync(void *, size_t, int);
int     __libc_open(const char *, int, ...);
int     __libc_pause(void);
ssize_t __libc_pwrite(int, const void *, size_t, off_t);
ssize_t __libc_pread(int, void *, size_t, off_t);
int     __libc_tcdrain(int);
pid_t   __libc_wait(int *);
int     __libc_system(const char *);
int     __libc_accept(int s, struct sockaddr *addr, socklen_t *addrlen);
int	__libc_connect(int, const struct sockaddr *, socklen_t);
ssize_t __libc_recvfrom(int, void *, size_t, int, struct sockaddr *,
			socklen_t *);
ssize_t __libc_recvmsg(int, struct msghdr *, int);
ssize_t __libc_sendmsg(int, const struct msghdr *, int);
ssize_t __libc_sendto(int, const void *,
		      size_t, int, const struct sockaddr *, socklen_t);

#ifndef __P
#   define __P(args)	args
#endif

#ifndef __THROW
#define __THROW
#endif

#ifndef __restrict
#define __restrict
#endif

#define SHLIB_COMPAT(lib, old, new) 0

#define versioned_symbol(libname, realname, aliasname, libver) __strong_reference(realname,aliasname)

#define link_warning(symbol, warning) __warn_references(symbol, warning);

#ifndef __PMT
#  define __PMT(args)	args
#endif

# define strong_alias(name, aliasname) \
  extern __typeof (name) aliasname __attribute__ ((alias (#name)));

#  define weak_alias(name, aliasname) \
  extern __typeof (name) aliasname __attribute__ ((weak, alias (#name)));

#define ENOTSUP EOPNOTSUPP

#define __builtin_expect(x,y) (x)
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


