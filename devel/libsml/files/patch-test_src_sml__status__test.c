--- test/src/sml_status_test.c.orig	2018-01-25 17:04:21 UTC
+++ test/src/sml_status_test.c
@@ -22,7 +22,7 @@
 
 TEST_GROUP(sml_status);
 
-sml_buffer *buf;
+extern sml_buffer *buf;
 
 TEST_SETUP(sml_status) {
 	buf = sml_buffer_init(512);
