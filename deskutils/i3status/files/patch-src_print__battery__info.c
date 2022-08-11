--- src/print_battery_info.c.orig	2021-11-09 07:27:11 UTC
+++ src/print_battery_info.c
@@ -595,7 +595,7 @@ void print_battery_info(battery_info_ctx_t *ctx) {
 #endif
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__OpenBSD__)
     /* These OSes report battery time in minutes. */
-    hide_seconds = true;
+    ctx->hide_seconds = true;
 #endif
 
     if (ctx->number < 0) {
