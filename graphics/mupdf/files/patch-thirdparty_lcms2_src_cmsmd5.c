--- thirdparty/lcms2/src/cmsmd5.c.orig	2018-01-23 19:37:31 UTC
+++ thirdparty/lcms2/src/cmsmd5.c
@@ -29,7 +29,7 @@
 #ifdef CMS_USE_BIG_ENDIAN
 
 static
-void byteReverse(cmsUInt8Number * buf, cmsUInt32Number longs)
+void byteReverse(cmsContext ContextID, cmsUInt8Number * buf, cmsUInt32Number longs)
 {
     do {
 
@@ -42,7 +42,7 @@ void byteReverse(cmsUInt8Number * buf, cmsUInt32Number
 }
 
 #else
-#define byteReverse(buf, len)
+#define byteReverse(ContextID, buf, len)
 #endif
 
 
@@ -196,7 +196,7 @@ void MD5add(cmsHANDLE Handle, cmsUInt8Number* buf, cms
         }
 
         memmove(p, buf, t);
-        byteReverse(ctx->in, 16);
+        byteReverse(ctx->ContextID, ctx->in, 16);
 
         MD5_Transform(ctx->buf, (cmsUInt32Number *) ctx->in);
         buf += t;
@@ -205,7 +205,7 @@ void MD5add(cmsHANDLE Handle, cmsUInt8Number* buf, cms
 
     while (len >= 64) {
         memmove(ctx->in, buf, 64);
-        byteReverse(ctx->in, 16);
+        byteReverse(ctx->ContextID, ctx->in, 16);
         MD5_Transform(ctx->buf, (cmsUInt32Number *) ctx->in);
         buf += 64;
         len -= 64;
@@ -232,21 +232,21 @@ void MD5finish(cmsProfileID* ProfileID,  cmsHANDLE Han
     if (count < 8) {
 
         memset(p, 0, count);
-        byteReverse(ctx->in, 16);
+        byteReverse(ctx->ContextID, ctx->in, 16);
         MD5_Transform(ctx->buf, (cmsUInt32Number *) ctx->in);
 
         memset(ctx->in, 0, 56);
     } else {
         memset(p, 0, count - 8);
     }
-    byteReverse(ctx->in, 14);
+    byteReverse(ctx->ContextID, ctx->in, 14);
 
     ((cmsUInt32Number *) ctx->in)[14] = ctx->bits[0];
     ((cmsUInt32Number *) ctx->in)[15] = ctx->bits[1];
 
     MD5_Transform(ctx->buf, (cmsUInt32Number *) ctx->in);
 
-    byteReverse((cmsUInt8Number *) ctx->buf, 4);
+    byteReverse(ctx->ContextID, (cmsUInt8Number *) ctx->buf, 4);
     memmove(ProfileID ->ID8, ctx->buf, 16);
 
     _cmsFree(ctx ->ContextID, ctx);
