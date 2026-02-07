--- test/src/sml_message_test.c.orig	2018-01-25 17:04:21 UTC
+++ test/src/sml_message_test.c
@@ -22,7 +22,7 @@
 
 TEST_GROUP(sml_message);
 
-sml_buffer *buf;
+extern sml_buffer *buf;
 
 TEST_SETUP(sml_message) {
 	buf = sml_buffer_init(512);
