Work around an iconv(3) portability issue that trips up sparse07.at.
https://lists.gnu.org/archive/html/bug-tar/2018-04/threads.html

--- src/utf8.c.orig	2018-04-30 17:25:34 UTC
+++ src/utf8.c
@@ -85,7 +85,7 @@ utf8_convert (bool to_utf, char const *i
   ib = (char ICONV_CONST *) input;
   rc = iconv (cd, &ib, &inlen, &ob, &outlen);
   *ob = 0;
-  return rc != -1;
+  return rc == 0;
 }
 
 
