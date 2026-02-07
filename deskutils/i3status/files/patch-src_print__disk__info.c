--- src/print_disk_info.c.orig	2024-08-19 16:28:44 UTC
+++ src/print_disk_info.c
@@ -73,13 +73,13 @@ static bool below_threshold(struct statvfs buf, const 
     } else if (strcasecmp(threshold_type, "percentage_avail") == 0) {
         return 100.0 * (double)buf.f_bavail / (double)buf.f_blocks < low_threshold;
     } else if (strcasecmp(threshold_type, "bytes_free") == 0) {
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__APPLE__)
+#if defined(__OpenBSD__) || defined(__DragonFly__) || defined(__APPLE__)
         return (double)buf.f_bsize * (double)buf.f_bfree < low_threshold;
 #else
         return (double)buf.f_frsize * (double)buf.f_bfree < low_threshold;
 #endif
     } else if (strcasecmp(threshold_type, "bytes_avail") == 0) {
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__APPLE__)
+#if defined(__OpenBSD__) || defined(__DragonFly__) || defined(__APPLE__)
         return (double)buf.f_bsize * (double)buf.f_bavail < low_threshold;
 #else
         return (double)buf.f_frsize * (double)buf.f_bavail < low_threshold;
@@ -198,7 +198,7 @@ void print_disk_info(disk_info_ctx_t *ctx) {
     char string_percentage_used[STRING_SIZE];
     char string_percentage_avail[STRING_SIZE];
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__APPLE__)
+#if defined(__OpenBSD__) || defined(__DragonFly__) || defined(__APPLE__)
     print_bytes_human(string_free, (uint64_t)buf.f_bsize * (uint64_t)buf.f_bfree, ctx->prefix_type);
     print_bytes_human(string_used, (uint64_t)buf.f_bsize * ((uint64_t)buf.f_blocks - (uint64_t)buf.f_bfree), ctx->prefix_type);
     print_bytes_human(string_total, (uint64_t)buf.f_bsize * (uint64_t)buf.f_blocks, ctx->prefix_type);
