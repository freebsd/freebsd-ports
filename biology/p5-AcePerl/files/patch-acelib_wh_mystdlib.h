--- acelib/wh/mystdlib.h.orig	2002-11-14 20:00:06 UTC
+++ acelib/wh/mystdlib.h
@@ -161,7 +161,8 @@ char *DosToPosix(char *path) ; /* define
 #endif
 
 #if defined(POSIX) || defined(LINUX) || defined(SOLARIS) || defined(SGI) || \
-	defined(HP) || defined(WIN32) || defined(INTEL_SOLARIS)
+	defined(HP) || defined(WIN32) || defined(INTEL_SOLARIS) || \
+	defined(FREEBSD)
 
 #ifdef WIN32
 #include <mbctype.h>
