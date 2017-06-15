--- lib/inc/hocon/config.hpp.orig	2016-09-23 20:45:10 UTC
+++ lib/inc/hocon/config.hpp
@@ -169,7 +169,7 @@ namespace hocon {
      * interface is likely to grow new methods over time, so third-party
      * implementations will break.
      */
-    class LIBCPP_HOCON_EXPORT config : public config_mergeable, public std::enable_shared_from_this<config> {
+    class CPP_HOCON_EXPORT config : public config_mergeable, public std::enable_shared_from_this<config> {
         friend class config_object;
         friend class config_value;
         friend class config_parseable;
