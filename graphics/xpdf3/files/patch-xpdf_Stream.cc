--- xpdf/Stream.cc.orig	2007-09-03 00:17:03.000000000 +0900
+++ xpdf/Stream.cc	2007-09-03 00:17:45.000000000 +0900
@@ -4479,6 +4479,7 @@
 	n = 3;
 	t = (c0 << 24) | (c1 << 16) | (c2 << 8);
       }
+      t &= 0xffffffff;
       for (i = 4; i >= 0; --i) {
 	buf1[i] = (char)(t % 85 + 0x21);
 	t /= 85;
@@ -4496,6 +4497,7 @@
     eof = gTrue;
   } else {
     t = (c0 << 24) | (c1 << 16) | (c2 << 8) | c3;
+    t &= 0xffffffff;
     if (t == 0) {
       *bufEnd++ = 'z';
       if (++lineLen == 65) {
