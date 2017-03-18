--- lib/inc/hocon/config_parse_options.hpp.orig	2016-09-23 20:45:10 UTC
+++ lib/inc/hocon/config_parse_options.hpp
@@ -22,7 +22,7 @@ namespace hocon {
      *
      * ClassLoader is Java-specific, so it was not ported to C++.
      */
-    class LIBCPP_HOCON_EXPORT config_parse_options {
+    class CPP_HOCON_EXPORT config_parse_options {
     public:
         /**
          * Gets an instance of <code>config_parse_options</code> with all fields
