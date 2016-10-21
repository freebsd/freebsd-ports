LibGD Issue: https://github.com/libgd/libgd/issues/308
Commit: https://github.com/libgd/libgd/commit/40bec0f38f50e8510f5bb71a82f516d46facde03

Fix integer overflow in gdImageWebpCtx

Integer overflow can be happened in expression gdImageSX(im) * 4 *
gdImageSY(im). It could lead to heap buffer overflow in the following
code. This issue has been reported to the PHP Bug Tracking System. The
proof-of-concept file will be supplied some days later. This issue was
discovered by Ke Liu of Tencent's Xuanwu LAB.
--- src/gd_webp.c.orig	2016-07-21 10:06:42.000000000 +0200
+++ src/gd_webp.c	2016-10-16 20:27:17.150066000 +0200
@@ -126,6 +126,14 @@
 		quantization = 80;
 	}
 
+	if (overflow2(gdImageSX(im), 4)) {
+		return;
+	}
+
+	if (overflow2(gdImageSX(im) * 4, gdImageSY(im))) {
+		return;
+	}
+
 	argb = (uint8_t *)gdMalloc(gdImageSX(im) * 4 * gdImageSY(im));
 	if (!argb) {
 		return;
