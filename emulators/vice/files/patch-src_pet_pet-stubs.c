--- src/pet/pet-stubs.c.orig	2024-12-24 19:12:44 UTC
+++ src/pet/pet-stubs.c
@@ -163,6 +163,8 @@ int parallel_cable_cpu_resources_init(void)
 {
     return -1;
 }
+
+#if 0
 int rsuser_cmdline_options_init(void)
 {
     return -1;
@@ -171,3 +173,4 @@ int rsuser_resources_init(void)
 {
     return -1;
 }
+#endif
