--- lefty/ws/x11/libfilereq/Dir.c.orig	Tue Apr 18 05:56:34 2000
+++ lefty/ws/x11/libfilereq/Dir.c	Tue Oct 17 18:29:35 2000
@@ -32,7 +32,7 @@
 
 #include "SFinternal.h"
 
-#if defined(SVR4) || defined(SYSV) || defined(USG) || defined(__osf__) || defined (__svr4__)
+#if defined(SVR4) || defined(SYSV) || defined(USG) || defined(__osf__) || defined (__svr4__) || defined (__FreeBSD__)
 #include <dirent.h>
 #else /* defined(SVR4) || defined(SYSV) || defined(USG) */
 #include <sys/dir.h>
