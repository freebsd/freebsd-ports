--- src/libsoup/soup-message.c.orig	Sun Sep 29 23:50:30 2002
+++ src/libsoup/soup-message.c	Sun Sep 29 23:59:10 2002
@@ -922,7 +922,7 @@
 		redirect_handler, 
 		NULL, 
 		RESPONSE_HEADER_HANDLER, 
-		{ (guint) "Location" }
+		{ (guint) 0 }
 	},
 	/* 
 	 * Handle authorization.
