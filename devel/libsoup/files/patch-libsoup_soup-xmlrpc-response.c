--- libsoup/soup-xmlrpc-response.c.orig	Sat Aug 20 17:33:02 2005
+++ libsoup/soup-xmlrpc-response.c	Sat Aug 20 17:33:11 2005
@@ -612,9 +612,9 @@ soup_xmlrpc_value_dump_internal (SoupXml
 			if (!soup_xmlrpc_value_array_get_iterator (value, &iter))
 				g_printerr ("BAD ARRAY\n");
 			else {
-				g_printerr ("ARRAY\n");
 				SoupXmlrpcValue *evalue;
 				int i = 0;
+				g_printerr ("ARRAY\n");
 				while (iter != NULL) {
 					soup_xmlrpc_value_array_iterator_get_value (iter, &evalue);
 					soup_xmlrpc_value_dump_array_element (i, evalue, GINT_TO_POINTER (d+1));
