--- response.c.orig	2009-03-06 13:02:27.000000000 -0300
+++ response.c	2009-03-06 13:03:03.000000000 -0300
@@ -34,7 +34,7 @@
         uint16_pack_big(buf,49152 + name_ptr[i]);
         return response_addbytes(buf,2);
       }
-    if (dlen <= 128)
+    if ((dlen <= 128) && (response_len < 16384))
       if (name_num < NAMES) {
 	byte_copy(name[name_num],dlen,d);
 	name_ptr[name_num] = response_len;
