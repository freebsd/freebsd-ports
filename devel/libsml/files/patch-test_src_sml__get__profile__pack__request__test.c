--- test/src/sml_get_profile_pack_request_test.c.orig	2018-01-25 17:04:21 UTC
+++ test/src/sml_get_profile_pack_request_test.c
@@ -22,7 +22,7 @@
 
 TEST_GROUP(sml_get_profile_pack_request);
 
-sml_buffer *buf;
+extern sml_buffer *buf;
 
 TEST_SETUP(sml_get_profile_pack_request) {
 	buf = sml_buffer_init(512);
