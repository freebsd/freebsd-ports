--- main.c.orig	Mon Mar 22 21:01:45 2004
+++ main.c	Mon Mar 22 21:02:10 2004
@@ -137,7 +137,7 @@
 	custfunc.listen = obexapp_transport_listen;
 	custfunc.write = obexapp_transport_write;
 	custfunc.handleinput = obexapp_transport_handle_input;
-	custfunc.userdata = &context;
+	custfunc.customdata = &context;
 
 	/* Process command line options */
 	service = 0;
