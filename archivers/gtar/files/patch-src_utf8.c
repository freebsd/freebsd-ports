Work around an iconv(3) portability issue that trips up sparse07.at.
https://lists.gnu.org/archive/html/bug-tar/2018-04/msg00019.html

--- src/utf8.c.orig	2019-01-11 17:46:41 UTC
+++ src/utf8.c
@@ -81,7 +81,7 @@ utf8_convert (bool to_utf, char const *input, char **o
   outlen = inlen * MB_LEN_MAX + 1;
   ob = ret = xmalloc (outlen);
   ib = (char ICONV_CONST *) input;
-  if (iconv (cd, &ib, &inlen, &ob, &outlen) == -1)
+  if (iconv (cd, &ib, &inlen, &ob, &outlen) != 0)
     {
       free (ret);
       return false;
