--- src/print_disk_info.c.orig	2021-11-10 16:46:42 UTC
+++ src/print_disk_info.c
@@ -63,7 +63,7 @@ static int print_bytes_human(char *outwalk, uint64_t b
  * Determines whether remaining bytes are below given threshold.
  *
  */
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__APPLE__)
+#if defined(__OpenBSD__) || defined(__DragonFly__) || defined(__APPLE__)
 static bool below_threshold(struct statfs buf, const char *prefix_type, const char *threshold_type, const double low_threshold) {
 #else
 static bool below_threshold(struct statvfs buf, const char *prefix_type, const char *threshold_type, const double low_threshold) {
@@ -124,17 +124,17 @@ void print_disk_info(disk_info_ctx_t *ctx) {
 
     INSTANCE(ctx->path);
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__APPLE__)
+#if defined(__OpenBSD__) || defined(__DragonFly__) || defined(__APPLE__)
     struct statfs buf;
 
     if (statfs(path, &buf) == -1)
         return;
 
     mounted = true;
-#elif defined(__NetBSD__)
+#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
     struct statvfs buf;
 
-    if (statvfs(path, &buf) == -1)
+    if (statvfs(ctx->path, &buf) == -1)
         return;
 
     mounted = true;
