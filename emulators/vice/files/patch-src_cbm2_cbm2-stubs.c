--- src/cbm2/cbm2-stubs.c.orig	2024-12-24 19:12:44 UTC
+++ src/cbm2/cbm2-stubs.c
@@ -71,6 +71,7 @@ int parallel_cable_cpu_resources_init(void)
     return -1;
 }
 
+#if 0
 int rsuser_cmdline_options_init(void)
 {
     return -1;
@@ -79,3 +80,4 @@ int rsuser_resources_init(void)
 {
     return -1;
 }
+#endif
