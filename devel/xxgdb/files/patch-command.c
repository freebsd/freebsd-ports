--- command.c.orig	1994-11-23 00:27:05 UTC
+++ command.c
@@ -383,7 +383,7 @@ void Quit(w, client_data, call_data)
     XtPointer client_data;
     XtPointer call_data;
 {
-#ifdef SYSV 
+#if defined(SYSV) || defined(__FreeBSD__)
     int status;
 #else
     union wait status;
@@ -392,7 +392,7 @@ void Quit(w, client_data, call_data)
     write_dbx("quit\n");
     XtDestroyApplicationContext(app_context);
     kill(dbxpid, SIGKILL);
-#ifdef SYSV
+#if defined(SYSV) || defined(__FreeBSD__)
 #if 1 /* instead of ifdef SVR4 */
 	status = waitpid(dbxpid, (int *)0, WNOHANG);	/* (MJH) */
 #else
