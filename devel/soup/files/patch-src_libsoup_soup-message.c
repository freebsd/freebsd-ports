--- src/libsoup/soup-message.c.orig	Wed Apr 10 12:33:17 2002
+++ src/libsoup/soup-message.c	Tue Nov 12 02:52:40 2002
@@ -907,7 +907,7 @@
 
 	SoupHandlerKind   kind;
 	union {
-		guint             errorcode;
+		unsigned long             errorcode;
 		SoupErrorClass    errorclass;
 		const gchar      *header;
 	} data;
@@ -922,8 +922,9 @@
 		redirect_handler, 
 		NULL, 
 		RESPONSE_HEADER_HANDLER, 
-		{ (guint) "Location" }
+		{ (unsigned long) "Location" }
 	},
+
 	/* 
 	 * Handle authorization.
 	 */
