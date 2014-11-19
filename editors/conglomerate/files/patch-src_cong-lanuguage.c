--- src/cong-language.c.orig	2014-11-06 23:32:03.335372300 +0100
+++ src/cong-language.c	2014-11-06 23:32:19.222359298 +0100
@@ -97,9 +97,10 @@
 {
 	g_return_if_fail (per_language);
 
-	return g_hash_table_insert (per_language->hash_table,
+	g_hash_table_insert (per_language->hash_table,
 				    g_strdup (language),
 				    data);
+	return;
 }
 
 void
