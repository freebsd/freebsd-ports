--- acelib/wh/mystdlib.h.orig	Mon Jul 16 23:04:45 2001
+++ acelib/wh/mystdlib.h	Mon Aug 13 12:42:25 2001
@@ -161,7 +161,8 @@
 #endif
 
 #if defined(POSIX) || defined(LINUX) || defined(SOLARIS) || defined(SGI) || \
-	defined(HP) || defined(WIN32) || defined(INTEL_SOLARIS)
+	defined(HP) || defined(WIN32) || defined(INTEL_SOLARIS) || \
+	defined(FREEBSD)
 
 #ifdef WIN32
 #include <mbctype.h>
