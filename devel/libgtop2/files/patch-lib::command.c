--- lib/command.c.orig	Tue Sep  9 09:47:58 2003
+++ lib/command.c	Tue Sep  9 08:14:33 2003
@@ -38,6 +38,7 @@
 	glibtop_init_r (&server, 0, 0);
 
 	memset (&cmnd, 0, sizeof (glibtop_command));
+	memset (&response, 0, sizeof (glibtop_response));
 
 	cmnd.command = command;
 
