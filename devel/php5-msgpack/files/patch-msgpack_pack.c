--- ./msgpack_pack.c.orig	2011-10-31 10:07:38.000000000 +0400
+++ ./msgpack_pack.c	2012-05-28 15:06:00.764503031 +0400
@@ -439,7 +439,7 @@
             msgpack_pack_nil(buf);
             msgpack_pack_long(buf, MSGPACK_SERIALIZE_TYPE_CUSTOM_OBJECT);
 
-            msgpack_serialize_string(buf, ce->name, ce->name_length);
+            msgpack_serialize_string(buf, (char *)ce->name, ce->name_length);
             msgpack_pack_raw(buf, serialized_length);
             msgpack_pack_raw_body(buf, serialized_data, serialized_length);
         }
