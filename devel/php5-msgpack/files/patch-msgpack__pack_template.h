--- ./msgpack/pack_template.h.orig	2011-10-06 05:03:16.000000000 +0400
+++ ./msgpack/pack_template.h	2012-05-28 15:06:00.762504244 +0400
@@ -728,7 +728,7 @@
 msgpack_pack_inline_func(_raw)(msgpack_pack_user x, size_t l)
 {
 	if(l < 32) {
-		unsigned char d = 0xa0 | (uint8_t)l;
+		unsigned char d = 0xa0 | l;
 		msgpack_pack_append_buffer(x, &TAKE8_8(d), 1);
 	} else if(l < 65536) {
 		unsigned char buf[3];
