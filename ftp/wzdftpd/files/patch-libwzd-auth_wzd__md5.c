--- libwzd-auth/wzd_md5.c.orig	2023-02-11 10:36:30 UTC
+++ libwzd-auth/wzd_md5.c
@@ -158,7 +158,7 @@ void MD5Name(MD5Final)(unsigned char digest[16], struc
     MD5Name(MD5Transform)(ctx->buf, (uint32 *) ctx->in);
     byteReverse((unsigned char *) ctx->buf, 4);
     memcpy(digest, ctx->buf, 16);
-    memset(ctx, 0, sizeof(ctx));	/* In case it's sensitive */
+    explicit_bzero(ctx, sizeof *ctx);  /* In case it's sensitive */
 }
 
 #ifndef ASM_MD5
