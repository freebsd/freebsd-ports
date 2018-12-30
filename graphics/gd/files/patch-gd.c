index d8eaf43..d852068 100644
--- src/gd.c
+++ src/gd.c
@@ -66,6 +66,9 @@ static const unsigned char gd_toascii[256] = {
 };
 #endif /*CHARSET_EBCDIC */
 
+/* 2.0.10: cast instead of floor() yields 35% performance improvement. Thanks to John Buckman. */
+#define floor_cast(exp) ((long) exp)
+
 extern const int gdCosT[];
 extern const int gdSinT[];
 
@@ -3452,50 +3455,51 @@ BGD_DECLARE(void) gdImageCopyResampled (gdImagePtr dst,
 										int dstW, int dstH, int srcW, int srcH)
 {
 	int x, y;
+	double sy1, sy2, sx1, sx2;
+
 	if (!dst->trueColor) {
 		gdImageCopyResized (dst, src, dstX, dstY, srcX, srcY, dstW, dstH, srcW, srcH);
 		return;
 	}
 	for (y = dstY; (y < dstY + dstH); y++) {
+		sy1 = ((double) y - (double) dstY) * (double) srcH / (double) dstH;
+		sy2 = ((double) (y + 1) - (double) dstY) * (double) srcH / (double) dstH;
 		for (x = dstX; (x < dstX + dstW); x++) {
-			float sy1, sy2, sx1, sx2;
-			float sx, sy;
-			float spixels = 0.0;
-			float red = 0.0, green = 0.0, blue = 0.0, alpha = 0.0;
-			float alpha_factor, alpha_sum = 0.0, contrib_sum = 0.0;
-			sy1 = ((float)(y - dstY)) * (float)srcH / (float)dstH;
-			sy2 = ((float)(y + 1 - dstY)) * (float) srcH / (float) dstH;
+			double sx, sy;
+			double spixels = 0;
+			double red = 0.0, green = 0.0, blue = 0.0, alpha = 0.0;
+			double alpha_factor, alpha_sum = 0.0, contrib_sum = 0.0;
+			sx1 = ((double) x - (double) dstX) * (double) srcW / dstW;
+			sx2 = ((double) (x + 1) - (double) dstX) * (double) srcW / dstW;
 			sy = sy1;
 			do {
-				float yportion;
-				if (floorf(sy) == floorf(sy1)) {
-					yportion = 1.0 - (sy - floorf(sy));
+				double yportion;
+				if (floor_cast(sy) == floor_cast(sy1)) {
+					yportion = 1.0f - (sy - floor_cast(sy));
 					if (yportion > sy2 - sy1) {
 						yportion = sy2 - sy1;
 					}
-					sy = floorf(sy);
+					sy = floor_cast(sy);
 				} else if (sy == floorf(sy2)) {
-					yportion = sy2 - floorf(sy2);
+					yportion = sy2 - floor_cast(sy2);
 				} else {
-					yportion = 1.0;
+					yportion = 1.0f;
 				}
-				sx1 = ((float)(x - dstX)) * (float) srcW / dstW;
-				sx2 = ((float)(x + 1 - dstX)) * (float) srcW / dstW;
 				sx = sx1;
 				do {
-					float xportion;
-					float pcontribution;
+					double xportion;
+					double pcontribution;
 					int p;
-					if (floorf(sx) == floorf(sx1)) {
-						xportion = 1.0 - (sx - floorf(sx));
+					if (floorf(sx) == floor_cast(sx1)) {
+						xportion = 1.0f - (sx - floor_cast(sx));
 						if (xportion > sx2 - sx1) {
 							xportion = sx2 - sx1;
 						}
-						sx = floorf(sx);
+						sx = floor_cast(sx);
 					} else if (sx == floorf(sx2)) {
-						xportion = sx2 - floorf(sx2);
+						xportion = sx2 - floor_cast(sx2);
 					} else {
-						xportion = 1.0;
+						xportion = 1.0f;
 					}
 					pcontribution = xportion * yportion;
 					p = gdImageGetTrueColorPixel(src, (int) sx + srcX, (int) sy + srcY);
@@ -3508,21 +3512,24 @@ BGD_DECLARE(void) gdImageCopyResampled (gdImagePtr dst,
 					alpha_sum += alpha_factor;
 					contrib_sum += pcontribution;
 					spixels += xportion * yportion;
-					sx += 1.0;
+					sx += 1.0f;
 				}
 				while (sx < sx2);
+
 				sy += 1.0f;
 			}
+
 			while (sy < sy2);
 
-			if (spixels != 0.0) {
+			if (spixels != 0.0f) {
 				red /= spixels;
 				green /= spixels;
 				blue /= spixels;
 				alpha /= spixels;
+				alpha += 0.5;
 			}
-			if ( alpha_sum != 0.0) {
-				if( contrib_sum != 0.0) {
+			if ( alpha_sum != 0.0f) {
+				if( contrib_sum != 0.0f) {
 					alpha_sum /= contrib_sum;
 				}
 				red /= alpha_sum;
@@ -3530,14 +3537,14 @@ BGD_DECLARE(void) gdImageCopyResampled (gdImagePtr dst,
 				blue /= alpha_sum;
 			}
 			/* Clamping to allow for rounding errors above */
-			if (red > 255.0) {
-				red = 255.0;
+			if (red > 255.0f) {
+				red = 255.0f;
 			}
-			if (green > 255.0) {
-				green = 255.0;
+			if (green > 255.0f) {
+				green = 255.0f;
 			}
 			if (blue > 255.0f) {
-				blue = 255.0;
+				blue = 255.0f;
 			}
 			if (alpha > gdAlphaMax) {
 				alpha = gdAlphaMax;
