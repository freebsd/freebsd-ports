--- libsoup/soup-message.c.orig	Thu May  8 19:27:40 2003
+++ libsoup/soup-message.c	Thu May  8 19:28:56 2003
@@ -877,7 +877,7 @@
 
 	SoupHandlerKind   kind;
 	union {
-		guint             errorcode;
+		unsigned long     errorcode;
 		SoupErrorClass    errorclass;
 		const gchar      *header;
 	} data;
@@ -892,7 +892,7 @@
 		redirect_handler, 
 		NULL, 
 		RESPONSE_HEADER_HANDLER, 
-		{ (guint) "Location" }
+		{ (unsigned long) "Location" }
 	},
 	/* 
 	 * Handle authorization.
