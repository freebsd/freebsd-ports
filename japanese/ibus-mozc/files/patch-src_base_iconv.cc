--- base/iconv.cc.org	2010-06-11 18:01:03.000000000 +0900
+++ base/iconv.cc	2010-06-12 10:02:20.315839057 +0900
@@ -52,7 +52,7 @@
   size_t olen_org = olen;
   iconv(ic, 0, &ilen, 0, &olen);  // reset iconv state
   while (ilen != 0) {
-    if (iconv(ic, reinterpret_cast<char **>(&ibuf), &ilen, &obuf, &olen)
+    if (iconv(ic, (const char **)(&ibuf), &ilen, &obuf, &olen)
         == static_cast<size_t>(-1)) {
       return;
     }
