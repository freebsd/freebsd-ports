--- client/runprog.c.orig	Fri Dec 15 18:30:10 1989
+++ client/runprog.c	Fri Aug  8 12:26:10 2003
@@ -133,7 +133,11 @@
 
 sigchld ()
 {
+#ifdef __FreeBSD__
+  int status;
+#else
 	union  wait status;
+#endif
 
 	if (childpid == 0)
 		return;
