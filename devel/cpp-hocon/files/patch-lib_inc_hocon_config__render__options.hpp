--- lib/inc/hocon/config_render_options.hpp.orig	2016-09-23 20:45:10 UTC
+++ lib/inc/hocon/config_render_options.hpp
@@ -17,7 +17,7 @@ namespace hocon {
      *         config_render_options().set_comments(false)
      * </pre>
      */
-    class LIBCPP_HOCON_EXPORT config_render_options {
+    class CPP_HOCON_EXPORT config_render_options {
     public:
         /** Leaving the default arguments will result in a verbose rendering,
          * which contains comments and therefore is not valid JSON.
