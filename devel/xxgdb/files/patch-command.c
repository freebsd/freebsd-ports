--- command.c.orig	Fri Sep  6 22:46:19 2002
+++ command.c	Fri Sep  6 22:49:30 2002
@@ -383,7 +383,7 @@
     XtPointer client_data;
     XtPointer call_data;
 {
-#ifdef SYSV 
+#if defined(SYSV) || defined(__FreeBSD__)
     int status;
 #else
     union wait status;
@@ -392,7 +392,7 @@
     write_dbx("quit\n");
     XtDestroyApplicationContext(app_context);
     kill(dbxpid, SIGKILL);
-#ifdef SYSV
+#if defined(SYSV) || defined(__FreeBSD__)
 #if 1 /* instead of ifdef SVR4 */
 	status = waitpid(dbxpid, (int *)0, WNOHANG);	/* (MJH) */
 #else
