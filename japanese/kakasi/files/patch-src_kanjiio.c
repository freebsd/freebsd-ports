--- src/kanjiio.c.orig	2013-02-07 07:26:18 UTC
+++ src/kanjiio.c
@@ -1080,11 +1080,11 @@ close_iconv()
 {
     if (fromutf8 != -1) {
 	iconv_close(fromutf8);
-	fromutf8 = -1;
+	fromutf8 = (iconv_t) -1;
     }
     if (toutf8 != -1) {
 	iconv_close(toutf8);
-	toutf8 = -1;
+	toutf8 = (iconv_t) -1;
     }
 }
 #endif /* KAKASI_SUPPORT_UTF8 */
