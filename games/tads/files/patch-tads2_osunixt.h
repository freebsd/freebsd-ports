Index: osunixt.h
@@ -84,7 +84,7 @@
  * Define the following to use sgtty.h instead of termios or direct
  * ioctl hacking.
  */
-#if defined(NEXT) || defined(IBM_RT) || defined(FREEBSD_386) || defined(IBM_AIX) || defined(NETBSD) || defined(OPENBSD) || defined(DARWIN)
+#if defined(NEXT) || defined(IBM_RT) || defined(IBM_AIX) || defined(NETBSD) || defined(OPENBSD) || defined(DARWIN)
 #define USE_IOCTL_INSTEAD_OF_TERMIOS
 #define USE_SGTTY
 #endif
