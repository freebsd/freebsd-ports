--- main.c.orig	Tue Jun  4 21:56:28 2002
+++ main.c	Tue Jun  4 21:59:33 2002
@@ -264,7 +264,7 @@
 static SIGNAL_T
 finish()
 {
-#if defined(SYSV) || defined(POSIX)
+#if defined(BSD) || defined(SYSV) || defined(POSIX)
 	int status;
 #else
 	union wait status;
@@ -272,7 +272,7 @@
 	register int pid;
 	register int die = 0;
 
-#if defined(SYSV) || defined(POSIX)
+#if defined(BSD) || defined(SYSV) || defined(POSIX)
 	while ((pid = waitpid(-1, &status, WNOHANG|WUNTRACED)) > 0)
 #else
 	while ((pid = wait3(&status, WNOHANG|WUNTRACED, (struct rusage *)0))>0)
