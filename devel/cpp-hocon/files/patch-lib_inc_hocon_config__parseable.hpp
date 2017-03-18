--- lib/inc/hocon/config_parseable.hpp.orig	2016-09-23 20:45:10 UTC
+++ lib/inc/hocon/config_parseable.hpp
@@ -16,7 +16,7 @@ namespace hocon {
      * interface is likely to grow new methods over time, so third-party
      * implementations will break.
      */
-    class LIBCPP_HOCON_EXPORT config_parseable {
+    class CPP_HOCON_EXPORT config_parseable {
     public:
         /**
          * Parse whatever it is. The options should come from
