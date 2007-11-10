--- texture.c	2007-11-07 17:32:05.000000000 -0500
+++ texture.c	2007-11-07 17:36:25.000000000 -0500
@@ -3172,6 +3172,7 @@
 	_s32 x, y;
 	_u8 *dest = i_dst;
     _u8 *src = i_src;
+    _u32 src_tmp;
 
     int xc, yc;
     int xl, yl;
@@ -3193,6 +3194,7 @@
 	{
 		x = sx;
    		src = i_src + tstart + ((y * twidth + x) << 2);
+		src_tmp = (_u32)src;
 
 	    if ((y & 1) && (swapped))
 			flip = 0x04; 
@@ -3201,13 +3203,13 @@
 
 		for(xc = 0; xc <= xl; xc++)
 		{
-			(_u32)src ^= flip; // wtf am I doing here?
-			src += 3;
-            *dest = *(_u8*)((_u32)src ^ flip); src--; dest++;
-            *dest = *(_u8*)((_u32)src ^ flip); src--; dest++;
-            *dest = *(_u8*)((_u32)src ^ flip); src--; dest++;
-            *dest = *(_u8*)((_u32)src ^ flip); dest++;
-            src += 4;
+			src_tmp ^= flip; // wtf am I doing here?
+			src_tmp += 3;
+            *dest = *(_u8*)(src_tmp ^ flip); src_tmp--; dest++;
+            *dest = *(_u8*)(src_tmp ^ flip); src_tmp--; dest++;
+            *dest = *(_u8*)(src_tmp ^ flip); src_tmp--; dest++;
+            *dest = *(_u8*)(src_tmp ^ flip); dest++;
+            src_tmp += 4;
 			//x += dx;
         }
 		y += dy;
