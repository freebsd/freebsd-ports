--- cegui/src/IconvStringTranscoder.cpp.orig	2014-03-12 06:50:07.000000000 +0100
+++ cegui/src/IconvStringTranscoder.cpp	2014-03-12 06:51:56.000000000 +0100
@@ -64,12 +64,7 @@
     size_t iconv(const char** inbuf, size_t* inbytesleft,
                  char** outbuf, size_t* outbytesleft)
     {
-#ifdef CEGUI_ICONV_USES_CONST_INBUF
         return ::iconv(d_cd, inbuf, inbytesleft, outbuf, outbytesleft);
-#else
-        return ::iconv(d_cd, const_cast<char**>(inbuf), inbytesleft,
-                       outbuf, outbytesleft);
-#endif
     }
 
     //------------------------------------------------------------------------//
