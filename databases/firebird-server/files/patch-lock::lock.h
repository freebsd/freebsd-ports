--- lock/lock.h.orig	Wed Jun  6 05:43:58 2001
+++ lock/lock.h	Sat Jul  6 18:08:56 2002
@@ -65,8 +65,10 @@
 #ifndef SOLARIS_MT
 #if !(defined(HP10) && defined(SUPERSERVER))
 #if !(defined(LINUX) && defined(SUPERSERVER))
+#if !(defined(FREEBSD) && defined(SUPERSERVER))
 #ifndef DARWIN
 #define MANAGER_PROCESS
+#endif
 #endif
 #endif
 #endif
