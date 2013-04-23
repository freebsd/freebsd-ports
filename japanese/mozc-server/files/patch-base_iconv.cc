--- base/iconv.cc.orig	2013-04-21 03:48:45.174270168 +0900
+++ base/iconv.cc	2013-04-21 04:16:39.946269033 +0900
@@ -53,7 +53,11 @@
   size_t olen_org = olen;
   iconv(ic, 0, &ilen, 0, &olen);  // reset iconv state
   while (ilen != 0) {
+#ifdef __FreeBSD__
+    if (iconv(ic, (const char **)(&ibuf), &ilen, &obuf, &olen)
+#else
     if (iconv(ic, reinterpret_cast<char **>(&ibuf), &ilen, &obuf, &olen)
+#endif
         == static_cast<size_t>(-1)) {
       return false;
     }
