--- src/plugin-website.c.orig	Sun May 25 11:59:33 2003
+++ src/plugin-website.c	Mon Jun 30 16:28:24 2003
@@ -390,12 +390,12 @@
 {
 	const CongXMLChar* dtd_public_id = cong_document_get_dtd_public_identifier(doc);
 	
-	g_message(dtd_public_id);
-
 	if (NULL==dtd_public_id) {
 		return FALSE;
 	}
 	
+	g_message(dtd_public_id);
+
 	/* Only relevant for Doctype with public ID = "" */
 	if (0==strcmp(dtd_public_id,"-//Norman Walsh//DTD Website Layout V2.4.0//EN")) {
 		return TRUE;
