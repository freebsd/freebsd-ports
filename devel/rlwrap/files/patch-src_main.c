--- src/main.c.orig	2014-11-14 14:48:11 UTC
+++ src/main.c
@@ -52,7 +52,7 @@ char *filter_command = NULL;                 /* -z opt
 
 /* variables for global bookkeeping */
 int master_pty_fd;		     /* master pty (rlwrap uses this to communicate with client) */
-int slave_pty_sensing_fd;		     /* slave pty (client uses this to communicate with rlwrap,
+extern int slave_pty_sensing_fd;     /* slave pty (client uses this to communicate with rlwrap,
 				      * we keep it open after forking in order to keep track of
 				      * client's terminal settings */
 FILE *debug_fp = NULL;  	     /* filehandle of debugging log */
