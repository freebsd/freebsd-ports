--- lib/inc/hocon/config_resolve_options.hpp.orig	2016-09-23 20:45:10 UTC
+++ lib/inc/hocon/config_resolve_options.hpp
@@ -27,7 +27,7 @@ namespace hocon {
      * environment variables or other external system information. (Right now,
      * environment variables are the only example.)
      */
-    class LIBCPP_HOCON_EXPORT config_resolve_options {
+    class CPP_HOCON_EXPORT config_resolve_options {
     public:
         /**
          * Returns the default resolve options. By default the system environment
