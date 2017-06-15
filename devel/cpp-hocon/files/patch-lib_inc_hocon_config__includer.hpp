--- lib/inc/hocon/config_includer.hpp.orig	2016-09-23 20:45:10 UTC
+++ lib/inc/hocon/config_includer.hpp
@@ -12,7 +12,7 @@ namespace hocon {
      * customize handling of {@code include} statements in config files. You may
      * also want to implement {@link config_includer_file} and {@link config_includer_URL}, or not.
      */
-    class LIBCPP_HOCON_EXPORT config_includer {
+    class CPP_HOCON_EXPORT config_includer {
     public:
         /**
          * Returns a new includer that falls back to the given includer. This is how
