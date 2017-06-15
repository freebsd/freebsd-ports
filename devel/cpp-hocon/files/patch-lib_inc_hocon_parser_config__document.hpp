--- lib/inc/hocon/parser/config_document.hpp.orig	2016-09-23 20:45:10 UTC
+++ lib/inc/hocon/parser/config_document.hpp
@@ -23,7 +23,7 @@ namespace hocon {
      * Also, this interface is likely to grow new methods over time, so third-party
      * implementations will break.
      */
-    class LIBCPP_HOCON_EXPORT config_document {
+    class CPP_HOCON_EXPORT config_document {
     public:
         /**
          * Returns a new config_document that is a copy of the current config_document,
