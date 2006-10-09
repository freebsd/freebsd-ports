--- src/engines/netlist.c.orig	Sat Sep 30 13:47:23 2006
+++ src/engines/netlist.c	Sat Sep 30 21:26:42 2006
@@ -628,9 +628,9 @@
 	GList *parts;
 	GList *p;
 	gchar *prop, *type, *ac;
-	parts = node_store_get_parts (store);
 	GString *out;
 	gchar *ret;
+	parts = node_store_get_parts (store);
 
 	out = g_string_new ("");
 
