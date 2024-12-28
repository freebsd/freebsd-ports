--- src/c64dtv/c64dtv-stubs.c.orig	2024-12-24 19:12:44 UTC
+++ src/c64dtv/c64dtv-stubs.c
@@ -313,6 +313,7 @@ void rtc58321a_start_clock(rtc_58321a_t *context)
 {
 }
 
+#if 0
 int rsuser_resources_init(void)
 {
     return -1;
@@ -325,3 +326,4 @@ int parallel_cable_cpu_resources_init(void)
 {
     return -1;
 }
+#endif
