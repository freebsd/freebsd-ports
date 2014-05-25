--- gnatlib/src/iconv/with_iconv/iconv_support.c.orig	2013-08-21 12:16:12.000000000 +0000
+++ gnatlib/src/iconv/with_iconv/iconv_support.c
@@ -25,7 +25,7 @@ int gnatcoll_iconv_close(iconv_t cd) {
    return iconv_close (cd);
 }
 
-#if _LIBICONV_VERSION >= 0x010D
+#if defined (__FreeBSD__) || defined (__DragonFly__)
 size_t gnatcoll_iconv
    (iconv_t cd,  const char** inbuf, size_t *inbytesleft, char** outbuf,
     size_t *outbytesleft)
