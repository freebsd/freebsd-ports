--- lib/inc/hocon/config_list.hpp.orig	2016-09-23 20:45:10 UTC
+++ lib/inc/hocon/config_list.hpp
@@ -34,7 +34,7 @@ namespace hocon {
      *
      */
 
-    class LIBCPP_HOCON_EXPORT config_list : public config_value {
+    class CPP_HOCON_EXPORT config_list : public config_value {
     public:
         config_list(shared_origin origin) : config_value(move(origin)) {}
 
