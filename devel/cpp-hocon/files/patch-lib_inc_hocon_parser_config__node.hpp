--- lib/inc/hocon/parser/config_node.hpp.orig	2016-09-23 20:45:10 UTC
+++ lib/inc/hocon/parser/config_node.hpp
@@ -18,7 +18,7 @@ namespace hocon {
      * Also, this interface is likely to grow new methods over time, so third-party
      * implementations will break.
      */
-    class LIBCPP_HOCON_EXPORT config_node {
+    class CPP_HOCON_EXPORT config_node {
     public:
         /**
          * The original text of the input which was used to form this particular
