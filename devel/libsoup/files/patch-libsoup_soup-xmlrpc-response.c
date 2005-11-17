--- libsoup/soup-xmlrpc-response.c.orig	Tue Nov  1 10:04:23 2005
+++ libsoup/soup-xmlrpc-response.c	Thu Nov 17 17:45:27 2005
@@ -612,9 +612,9 @@
 			if (!soup_xmlrpc_value_array_get_iterator (value, &iter))
 				g_printerr ("BAD ARRAY\n");
 			else {
+				g_printerr ("ARRAY\n");
 				SoupXmlrpcValue *evalue;
 				int i = 0;
-				g_printerr ("ARRAY\n");
 				while (iter != NULL) {
 					soup_xmlrpc_value_array_iterator_get_value (iter, &evalue);
 					soup_xmlrpc_value_dump_array_element (i, evalue, GINT_TO_POINTER (d+1));
