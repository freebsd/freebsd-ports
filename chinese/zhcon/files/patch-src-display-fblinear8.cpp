--- src/display/fblinear8.cpp~	Sun Aug  1 17:29:43 2004
+++ src/display/fblinear8.cpp	Sun Aug  1 17:39:12 2004
@@ -102,7 +102,7 @@
             fb_writel((nibbletab_cfb8[*cdat >> 4] & eorx) ^ bgx, dest32++);
         }
         if (pFont->w & 2) {
-            fb_writew((nibbletab_cfb8[*cdat & 0xc] & eorx) ^ bgx, ((__u16*)dest32)++);
+            fb_writew((nibbletab_cfb8[*cdat & 0xc] & eorx) ^ bgx, ((__u16*)dest32) + 1);
         }
         if (pFont->w & 1) {
             fb_writeb((*cdat & 2) ? fg : bg, (__u8*)dest32);
