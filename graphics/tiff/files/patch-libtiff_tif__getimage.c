--- libtiff/tif_getimage.c.orig	2025-06-25 17:20:35 UTC
+++ libtiff/tif_getimage.c
@@ -2216,7 +2216,7 @@ DECLAREContigPutFunc(putcontig8bitYCbCr44tile)
     uint32_t *cp1 = cp + w + toskew;
     uint32_t *cp2 = cp1 + w + toskew;
     uint32_t *cp3 = cp2 + w + toskew;
-    int32_t incr = 3 * w + 4 * toskew;
+    const tmsize_t incr = 3 * (tmsize_t)w + 4 * (tmsize_t)toskew;
 
     (void)y;
     /* adjust fromskew */
@@ -2356,7 +2356,7 @@ DECLAREContigPutFunc(putcontig8bitYCbCr42tile)
 DECLAREContigPutFunc(putcontig8bitYCbCr42tile)
 {
     uint32_t *cp1 = cp + w + toskew;
-    int32_t incr = 2 * toskew + w;
+    const tmsize_t incr = 2 * (tmsize_t)toskew + w;
 
     (void)y;
     fromskew = (fromskew / 4) * (4 * 2 + 2);
@@ -2512,7 +2512,7 @@ DECLAREContigPutFunc(putcontig8bitYCbCr22tile)
 DECLAREContigPutFunc(putcontig8bitYCbCr22tile)
 {
     uint32_t *cp2;
-    int32_t incr = 2 * toskew + w;
+    const tmsize_t incr = 2 * (tmsize_t)toskew + w;
     (void)y;
     fromskew = (fromskew / 2) * (2 * 2 + 2);
     cp2 = cp + w + toskew;
@@ -2615,7 +2615,7 @@ DECLAREContigPutFunc(putcontig8bitYCbCr12tile)
 DECLAREContigPutFunc(putcontig8bitYCbCr12tile)
 {
     uint32_t *cp2;
-    int32_t incr = 2 * toskew + w;
+    const tmsize_t incr = 2 * (tmsize_t)toskew + w;
     (void)y;
     fromskew = (fromskew / 1) * (1 * 2 + 2);
     cp2 = cp + w + toskew;
