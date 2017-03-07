--- lib/inc/hocon/config_value.hpp.orig	2016-09-23 20:45:10 UTC
+++ lib/inc/hocon/config_value.hpp
@@ -36,7 +36,7 @@ namespace hocon {
      * Also, this interface is likely to grow new methods over time, so third-party
      * implementations will break.
      */
-    class LIBCPP_HOCON_EXPORT config_value : public config_mergeable, public std::enable_shared_from_this<config_value> {
+    class CPP_HOCON_EXPORT config_value : public config_mergeable, public std::enable_shared_from_this<config_value> {
         friend class token;
         friend class value;
         friend class default_transformer;
