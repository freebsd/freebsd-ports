--- cegui/src/IconvStringTranscoder.cpp.orig	2013-05-30 15:28:09.000000000 +0200
+++ cegui/src/IconvStringTranscoder.cpp	2013-05-30 15:28:40.000000000 +0200
@@ -64,7 +64,7 @@
     size_t iconv(const char** inbuf, size_t* inbytesleft,
                  char** outbuf, size_t* outbytesleft)
     {
-        return ::iconv(d_cd, const_cast<char**>(inbuf), inbytesleft,
+        return ::iconv(d_cd, inbuf, inbytesleft,
                        outbuf, outbytesleft);
     }
 
