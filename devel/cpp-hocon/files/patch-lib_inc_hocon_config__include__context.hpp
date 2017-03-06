--- lib/inc/hocon/config_include_context.hpp.orig	2016-09-23 20:45:10 UTC
+++ lib/inc/hocon/config_include_context.hpp
@@ -18,7 +18,7 @@ namespace hocon {
      * interface is likely to grow new methods over time, so third-party
      * implementations will break.
      */
-    class LIBCPP_HOCON_EXPORT config_include_context {
+    class CPP_HOCON_EXPORT config_include_context {
     public:
         /**
          * Tries to find a name relative to whatever is doing the including, for
