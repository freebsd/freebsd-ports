--- src/base/iconv.cc.org	2010-05-23 14:02:48.371949634 +0900
+++ src/base/iconv.cc	2010-05-23 13:58:38.727786479 +0900
@@ -52,7 +52,7 @@
   size_t olen_org = olen;
   iconv(ic, 0, &ilen, 0, &olen);  // reset iconv state
   while (ilen != 0) {
-    if (iconv(ic, reinterpret_cast<char **>(&ibuf), &ilen, &obuf, &olen)
+    if (iconv(ic, (const char **)(&ibuf), &ilen, &obuf, &olen)
         == static_cast<size_t>(-1)) {
       return;
     }
