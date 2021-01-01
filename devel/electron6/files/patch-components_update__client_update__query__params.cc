--- components/update_client/update_query_params.cc.orig	2019-09-10 11:14:00 UTC
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
