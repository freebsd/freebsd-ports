--- signals.c.orig	Fri Sep  6 22:52:25 2002
+++ signals.c	Fri Sep  6 22:52:56 2002
@@ -93,7 +93,7 @@
 static void quit_handler(int sig)
 {
 	int pid;
-#ifdef SYSV 
+#if defined(SYSV) || defined(__FreeBSD__) 
     int status;
 #else
     union wait status;
@@ -102,7 +102,7 @@
     /*  wait for the child to report its status; if the child has died, 
      *  exit gracefully.
      */
-#ifdef SYSV 
+#if defined(SYSV) || defined(__FreeBSD__) 
 #if 1  /* instead of ifdef SVR4 */
 	pid = waitpid((pid_t)0, &status, WNOHANG|WUNTRACED);	/* (MJH) */
 #else
