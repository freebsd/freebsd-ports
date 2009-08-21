--- newlib/libc/include/sys/types.h.orig	2006-09-14 01:09:27.000000000 +0300
+++ newlib/libc/include/sys/types.h	2007-06-01 12:22:26.000000000 +0300
@@ -199,52 +199,6 @@
 
 typedef unsigned short nlink_t;
 
-/* We don't define fd_set and friends if we are compiling POSIX
-   source, or if we have included (or may include as indicated
-   by __USE_W32_SOCKETS) the W32api winsock[2].h header which
-   defines Windows versions of them.   Note that a program which
-   includes the W32api winsock[2].h header must know what it is doing;
-   it must not call the cygwin32 select function.
-*/
-# if !(defined (_POSIX_SOURCE) || defined (_WINSOCK_H) || defined (__USE_W32_SOCKETS)) 
-#  define _SYS_TYPES_FD_SET
-#  define	NBBY	8		/* number of bits in a byte */
-/*
- * Select uses bit masks of file descriptors in longs.
- * These macros manipulate such bit fields (the filesystem macros use chars).
- * FD_SETSIZE may be defined by the user, but the default here
- * should be >= NOFILE (param.h).
- */
-#  ifndef	FD_SETSIZE
-#	define	FD_SETSIZE	64
-#  endif
-
-typedef	long	fd_mask;
-#  define	NFDBITS	(sizeof (fd_mask) * NBBY)	/* bits per mask */
-#  ifndef	howmany
-#	define	howmany(x,y)	(((x)+((y)-1))/(y))
-#  endif
-
-/* We use a macro for fd_set so that including Sockets.h afterwards
-   can work.  */
-typedef	struct _types_fd_set {
-	fd_mask	fds_bits[howmany(FD_SETSIZE, NFDBITS)];
-} _types_fd_set;
-
-#define fd_set _types_fd_set
-
-#  define	FD_SET(n, p)	((p)->fds_bits[(n)/NFDBITS] |= (1L << ((n) % NFDBITS)))
-#  define	FD_CLR(n, p)	((p)->fds_bits[(n)/NFDBITS] &= ~(1L << ((n) % NFDBITS)))
-#  define	FD_ISSET(n, p)	((p)->fds_bits[(n)/NFDBITS] & (1L << ((n) % NFDBITS)))
-#  define	FD_ZERO(p)	(__extension__ (void)({ \
-     size_t __i; \
-     char *__tmp = (char *)p; \
-     for (__i = 0; __i < sizeof (*(p)); ++__i) \
-       *__tmp++ = 0; \
-}))
-
-# endif	/* !(defined (_POSIX_SOURCE) || defined (_WINSOCK_H) || defined (__USE_W32_SOCKETS)) */
-
 #undef __MS_types__
 #undef _ST_INT32
 
