--- syscall.c.orig	2008-11-20 23:43:57.000000000 +0800
+++ syscall.c	2008-11-20 23:46:37.000000000 +0800
@@ -716,8 +716,10 @@
 	   )
 		return internal_exec(tcp);
 
-	if (   sys_waitpid == func
-	    || sys_wait4 == func
+	if (   sys_wait4 == func
+#if defined(LINUX)
+	    || sys_waitpid == func
+#endif
 #if defined(SVR4) || defined(FREEBSD) || defined(SUNOS4)
 	    || sys_wait == func
 #endif
