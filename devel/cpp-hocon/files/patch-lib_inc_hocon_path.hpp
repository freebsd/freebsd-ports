--- lib/inc/hocon/path.hpp.orig	2016-09-23 20:45:10 UTC
+++ lib/inc/hocon/path.hpp
@@ -10,7 +10,7 @@
 
 namespace hocon {
 
-    class LIBCPP_HOCON_EXPORT path {
+    class CPP_HOCON_EXPORT path {
     public:
         path();
         explicit path(std::string first, path const& remainder);
