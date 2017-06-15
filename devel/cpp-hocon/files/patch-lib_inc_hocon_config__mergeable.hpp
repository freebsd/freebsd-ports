--- lib/inc/hocon/config_mergeable.hpp.orig	2016-09-23 20:45:10 UTC
+++ lib/inc/hocon/config_mergeable.hpp
@@ -5,7 +5,7 @@
 
 namespace hocon {
 
-    class LIBCPP_HOCON_EXPORT config_mergeable {
+    class CPP_HOCON_EXPORT config_mergeable {
         friend class config_value;
     public:
         /**
