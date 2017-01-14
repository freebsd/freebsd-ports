--- rtengine/dcraw.cc.orig	2017-01-14 17:35:19 UTC
+++ rtengine/dcraw.cc
@@ -8726,7 +8726,8 @@ static void decodeFPDeltaRow(Bytef * src
       dst[col*3 + 2] = src[col + realTileWidth*2];
     }
   } else {
-    if (((union { uint32_t x; uint8_t c; }){1}).c) {
+    union X { uint32_t x; uint8_t c; };
+    if (((union X){1}).c) {
 		for (size_t col = 0; col < tileWidth; ++col) {
 			for (size_t byte = 0; byte < bytesps; ++byte)
 				dst[col*bytesps + byte] = src[col + realTileWidth*(bytesps-byte-1)];  // Little endian
