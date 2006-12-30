--- src/unix/sys_unix.c.orig	Fri Jun  2 12:50:26 2006
+++ src/unix/sys_unix.c	Sat Dec 30 10:57:29 2006
@@ -89,7 +89,7 @@
 	CL_Shutdown();
 	Qcommon_Shutdown();
 	fcntl(0, F_SETFL, fcntl(0, F_GETFL, 0) & ~FNDELAY);
-	exit(0);
+	_exit(0);
 }
 
 void
@@ -117,7 +117,7 @@
 	va_end(argptr);
 	fprintf(stderr, "Error: %s\n", string);
 
-	exit(1);
+	_exit(1);
 
 }
 
