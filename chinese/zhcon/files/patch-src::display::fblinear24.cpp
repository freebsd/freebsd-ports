--- src/display/fblinear24.cpp~	Sun Aug  1 17:22:19 2004
+++ src/display/fblinear24.cpp	Sun Aug  1 17:27:33 2004
@@ -203,11 +203,11 @@
             d1 = (-(*cdat >> 3 & 1) & eorx) ^ bgx;
             d2 = (-(*cdat >> 2 & 1) & eorx) ^ bgx;
             fb_writel(d1 | (d2<<24), dest32++);
-            fb_writew(d2>>8, ((__u16*)dest32)++);
+            fb_writew(d2>>8, ((__u16*)dest32) + 1);
         }
         if (pFont->w & 1) {
             d3 = (-(*cdat >> 1 & 1) & eorx) ^ bgx;
-            fb_writew(d3, ((__u16*)dest32)++);
+            fb_writew(d3, ((__u16*)dest32) + 1);
             fb_writeb(d3>>16, (__u8*)dest32);
         }
         cdat++;
