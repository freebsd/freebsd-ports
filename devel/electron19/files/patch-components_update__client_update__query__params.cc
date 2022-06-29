--- components/update_client/update_query_params.cc.orig	2022-05-19 05:17:41 UTC
+++ components/update_client/update_query_params.cc
@@ -40,6 +40,8 @@ const char kOs[] =
     "fuchsia";
 #elif BUILDFLAG(IS_OPENBSD)
     "openbsd";
+#elif defined(OS_FREEBSD)
+    "freebsd";
 #else
 #error "unknown os"
 #endif
