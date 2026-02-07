--- test/src/sml_number_test.c.orig	2018-01-25 17:04:21 UTC
+++ test/src/sml_number_test.c
@@ -23,7 +23,7 @@
 
 TEST_GROUP(sml_number);
 
-sml_buffer *buf;
+extern sml_buffer *buf;
 
 TEST_SETUP(sml_number) {
 	buf = sml_buffer_init(512);
