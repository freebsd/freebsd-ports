*** compat/bsd/stdlib/arc4random.h.orig Sun Nov 29 00:02:28 2009
--- compat/bsd/stdlib/arc4random.h      Mon Nov 30 15:22:29 2009
***************
*** 379,389 ****


   #ifndef HAVE_ARC4RANDOM_BUF
! #if defined __OpenBSD__

! #include <sys/param.h>        /* OpenBSD */

! #if OpenBSD >= 200811
   #define HAVE_ARC4RANDOM_BUF   1
   #else
   #define HAVE_ARC4RANDOM_BUF   0
--- 379,389 ----


   #ifndef HAVE_ARC4RANDOM_BUF
! #if defined __OpenBSD__ || defined __FreeBSD__

! #include <sys/param.h>        /* OpenBSD, FreeBSD */

! #if OpenBSD >= 200811 || __FreeBSD_version >= 800107
   #define HAVE_ARC4RANDOM_BUF   1
   #else
   #define HAVE_ARC4RANDOM_BUF   0
