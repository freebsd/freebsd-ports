--- jsonnet.c.orig	2015-06-05 23:08:06 UTC
+++ jsonnet.c
@@ -128,7 +128,7 @@ PHP_MINFO_FUNCTION(jsonnet)
 {
     php_info_print_table_start();
     php_info_print_table_header(2, "JsonNet support", "Enabled");
-    php_info_print_table_row(2, "jsonnet Information", JSONNET_VERSION);
+    php_info_print_table_row(2, "jsonnet Information", jsonnet_version());
     php_info_print_table_row(2, "Version", JSONNET_PHP_VERSION);
     php_info_print_table_row(2, "Author", JSONNET_PHP_AUTHOR);
     php_info_print_table_row(2,"Supports", "https://github.com/Neeke/JsonNet");
