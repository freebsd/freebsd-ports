--- libfastcgi/fastcgi.hpp.orig	2025-09-03 18:54:33 UTC
+++ libfastcgi/fastcgi.hpp
@@ -155,7 +155,7 @@ class FCGIProtocolDriver (private)
   reqmap_t reqmap;
   std::queue<u_int16_t> new_request_queue;
 
-  std::basic_string<u_int8_t> InputBuffer;
+  std::vector<u_int8_t> InputBuffer;
   u_int8_t tmp_buf[64];
 };
 
