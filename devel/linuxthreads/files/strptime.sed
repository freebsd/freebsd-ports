1i\
#if __FreeBSD__ == 4
/.*MUTEX_STATIC.*/d
/^#include "pthread_private.h"/d
s/\&_gotgmt_mutexd/PTHREAD_MUTEX_INITIALIZER/
s/\&logname_lock/PTHREAD_MUTEX_INITIALIZER/
s/#include <libc_private.h>/extern int __isthreaded;/
$a\
#endif /* __FreeBSD__ == 4 */
