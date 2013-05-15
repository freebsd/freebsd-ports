--- busybee_utils.cc.orig	2013-05-14 11:01:48.938913816 +0000
+++ busybee_utils.cc	2013-05-14 11:02:14.734910166 +0000
@@ -27,6 +27,9 @@
 
 // POSIX
 #ifndef _MSC_VER
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
 #include <ifaddrs.h>
 #endif
 
