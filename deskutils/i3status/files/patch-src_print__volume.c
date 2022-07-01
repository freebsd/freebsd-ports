--- src/print_volume.c.orig	2021-11-09 07:27:11 UTC
+++ src/print_volume.c
@@ -250,8 +250,8 @@ void print_volume(volume_ctx_t *ctx) {
     const char *devicename = "UNSUPPORTED"; /* TODO: implement support for this */
     pbval = 1;
 
-    if (mixer_idx > 0)
-        asprintf(&mixerpath, "/dev/mixer%d", mixer_idx);
+    if (ctx->mixer_idx > 0)
+        asprintf(&mixerpath, "/dev/mixer%d", ctx->mixer_idx);
     else
         mixerpath = defaultmixer;
 
@@ -264,7 +264,7 @@ void print_volume(volume_ctx_t *ctx) {
         goto out;
     }
 
-    if (mixer_idx > 0)
+    if (ctx->mixer_idx > 0)
         free(mixerpath);
 
 #if defined(__NetBSD__) || defined(__OpenBSD__)
@@ -351,7 +351,7 @@ void print_volume(volume_ctx_t *ctx) {
     }
 
 #endif
-    buffer = apply_volume_format(fmt, buffer, vol & 0x7f, devicename);
+    ctx->buf = apply_volume_format(ctx->fmt, vol & 0x7f, devicename);
     close(mixfd);
     goto out_with_format;
 #endif
