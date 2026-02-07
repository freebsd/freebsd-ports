--- signals.c.orig	1995-04-06 16:25:04 UTC
+++ signals.c
@@ -93,7 +93,7 @@ kill_handler(sig)
 static void quit_handler(int sig)
 {
 	int pid;
-#ifdef SYSV 
+#if defined(SYSV) || defined(__FreeBSD__) 
     int status;
 #else
     union wait status;
@@ -102,7 +102,7 @@ static void quit_handler(int sig)
     /*  wait for the child to report its status; if the child has died, 
      *  exit gracefully.
      */
-#ifdef SYSV 
+#if defined(SYSV) || defined(__FreeBSD__) 
 #if 1  /* instead of ifdef SVR4 */
 	pid = waitpid((pid_t)0, &status, WNOHANG|WUNTRACED);	/* (MJH) */
 #else
