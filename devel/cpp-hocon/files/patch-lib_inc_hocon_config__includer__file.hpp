--- lib/inc/hocon/config_includer_file.hpp.orig	2016-09-23 20:45:10 UTC
+++ lib/inc/hocon/config_includer_file.hpp
@@ -11,7 +11,7 @@ namespace hocon {
      * If you do not implement this but do implement {@link config_includer},
      * attempts to load files will use the default includer.
      */
-    class LIBCPP_HOCON_EXPORT config_includer_file {
+    class CPP_HOCON_EXPORT config_includer_file {
     public:
         /**
          * Parses another item to be included. The returned object typically would
