--- test/src/sml_tree_test.c.orig	2018-01-25 17:04:21 UTC
+++ test/src/sml_tree_test.c
@@ -23,7 +23,7 @@
 
 TEST_GROUP(sml_tree);
 
-sml_buffer *buf;
+extern sml_buffer *buf;
 
 TEST_SETUP(sml_tree) {
 	buf = sml_buffer_init(512);
