--- src/base/iconv.cc.org	2010-05-29 11:06:10.667672161 +0900
+++ src/base/iconv.cc	2010-05-29 11:22:12.794853968 +0900
@@ -52,7 +52,7 @@
   size_t olen_org = olen;
   iconv(ic, 0, &ilen, 0, &olen);  // reset iconv state
   while (ilen != 0) {
-    if (iconv(ic, reinterpret_cast<char **>(&ibuf), &ilen, &obuf, &olen)
+    if (iconv(ic, (const char **)(&ibuf), &ilen, &obuf, &olen)
         == static_cast<size_t>(-1)) {
       return;
     }
