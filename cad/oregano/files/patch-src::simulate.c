--- src/simulate.c.orig	Tue Nov 23 04:20:05 2004
+++ src/simulate.c	Fri Nov 26 18:10:37 2004
@@ -200,10 +200,10 @@
 	GList *parts;
 	GList *p;
 	gchar *prop, *type, *ac;
-	parts = node_store_get_parts (store);
 	GString *out;
 	gchar *ret;
 
+	parts = node_store_get_parts (store);
 	out = g_string_new ("");
 
 	for(p=parts; p; p = p->next) {
