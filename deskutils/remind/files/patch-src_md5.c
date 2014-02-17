--- src/md5.c.orig	2014-02-14 17:34:29.000000000 +0100
+++ src/md5.c	2014-02-14 17:34:37.000000000 +0100
@@ -141,7 +141,7 @@
     MD5Transform(ctx->buf, (uint32 *) ctx->in);
     byteReverse((unsigned char *) ctx->buf, 4);
     memcpy(digest, ctx->buf, 16);
-    memset(ctx, 0, sizeof(ctx));	/* In case it's sensitive */
+    memset(ctx, 0, sizeof(*ctx));	/* In case it's sensitive */
 }
 
 #ifndef ASM_MD5
