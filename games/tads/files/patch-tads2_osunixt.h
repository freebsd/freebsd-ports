--- osunixt.h.orig	2004-02-17 02:20:41 UTC
+++ osunixt.h
@@ -84,7 +84,7 @@ Tue Nov 22 15:16:10 EST 1994    Dave Bag
  * Define the following to use sgtty.h instead of termios or direct
  * ioctl hacking.
  */
-#if defined(NEXT) || defined(IBM_RT) || defined(FREEBSD_386) || defined(IBM_AIX) || defined(NETBSD) || defined(OPENBSD) || defined(DARWIN)
+#if defined(NEXT) || defined(IBM_RT) || defined(IBM_AIX) || defined(NETBSD) || defined(OPENBSD) || defined(DARWIN)
 #define USE_IOCTL_INSTEAD_OF_TERMIOS
 #define USE_SGTTY
 #endif
