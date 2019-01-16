--- libs/locale/src/encoding/iconv_codepage.ipp.orig	2017-09-02 09:56:14 UTC
+++ libs/locale/src/encoding/iconv_codepage.ipp
@@ -43,7 +43,7 @@ class iconverter_base { (public)
     bool open(char const *to,char const *from,method_type how)
     {
         close();
-        cvt_ = iconv_open(to,from);
+        cvt_ = call_iconv_open(to,from);
         how_ = how;
         return cvt_ != (iconv_t)(-1);
     }
