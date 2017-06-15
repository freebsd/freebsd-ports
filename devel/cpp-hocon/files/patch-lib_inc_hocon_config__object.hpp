--- lib/inc/hocon/config_object.hpp.orig	2016-09-23 20:45:10 UTC
+++ lib/inc/hocon/config_object.hpp
@@ -8,7 +8,7 @@
 
 namespace hocon {
 
-    class LIBCPP_HOCON_EXPORT config_object : public config_value {
+    class CPP_HOCON_EXPORT config_object : public config_value {
         friend class config;
         friend class config_value;
         friend class simple_config_object;
