CVE-2017-14160: fix bounds check on very low sample rates.
https://gitlab.xiph.org/xiph/vorbis/-/commit/018ca26dece618457dd13585cad52941193c4a25
--- lib/psy.c.orig	2020-06-28 19:37:27 UTC
+++ lib/psy.c
@@ -602,8 +602,9 @@ static void bark_noise_hybridmp(int n,const long *b,
   for (i = 0, x = 0.f;; i++, x += 1.f) {
 
     lo = b[i] >> 16;
-    if( lo>=0 ) break;
     hi = b[i] & 0xffff;
+    if( lo>=0 ) break;
+    if( hi>=n ) break;
 
     tN = N[hi] + N[-lo];
     tX = X[hi] - X[-lo];
