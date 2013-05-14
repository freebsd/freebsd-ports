--- base/iconv.cc.orig	2013-03-29 13:33:43.000000000 +0900
+++ base/iconv.cc	2013-04-27 15:36:30.000000000 +0900
@@ -53,7 +53,11 @@
   size_t olen_org = olen;
   iconv(ic, 0, &ilen, 0, &olen);  // reset iconv state
   while (ilen != 0) {
+#ifdef OS_FREEBSD
+    if (iconv(ic, (const char **)(&ibuf), &ilen, &obuf, &olen)
+#else
     if (iconv(ic, reinterpret_cast<char **>(&ibuf), &ilen, &obuf, &olen)
+#endif
         == static_cast<size_t>(-1)) {
       return false;
     }
