--- src/uuids.cpp.orig	2016-08-22 18:07:08 UTC
+++ src/uuids.cpp
@@ -121,7 +121,7 @@ CassError cass_uuid_from_string_n(const 
   const char* pos = str;
   char buf[16];
 
-  static const char hex_to_half_byte[256] = {
+  static const signed char hex_to_half_byte[256] = {
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
