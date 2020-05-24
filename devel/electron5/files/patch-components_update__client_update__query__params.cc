--- components/update_client/update_query_params.cc.orig	2019-04-08 08:32:52 UTC
+++ components/update_client/update_query_params.cc
@@ -38,6 +38,8 @@ const char kOs[] =
     "fuchsia";
 #elif defined(OS_OPENBSD)
     "openbsd";
+#elif defined(OS_FREEBSD)
+    "freebsd";
 #else
 #error "unknown os"
 #endif
