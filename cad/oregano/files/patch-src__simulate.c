--- src/simulate.c.orig	Wed May 24 14:16:30 2006
+++ src/simulate.c	Wed May 24 21:39:29 2006
@@ -188,10 +188,10 @@
 	GList *parts;
 	GList *p;
 	gchar *prop, *type, *ac;
-	parts = node_store_get_parts (store);
 	GString *out;
 	gchar *ret;
 
+	parts = node_store_get_parts (store);
 	out = g_string_new ("");
 
 	for(p=parts; p; p = p->next) {
