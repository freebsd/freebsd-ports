--- src/af/util/xp/ut_iconv.cpp.orig	Thu Jul 17 15:12:55 2003
+++ src/af/util/xp/ut_iconv.cpp	Thu Jul 17 15:16:40 2003
@@ -295,8 +295,8 @@
     return (size_t)-1;
 
 
-  ICONV_CONST char ** buf = const_cast<ICONV_CONST char**>(inbuf);
-  return iconv( cd, buf, inbytesleft, outbuf, outbytesleft );
+  //ICONV_CONST char ** buf = const_cast<ICONV_CONST char**>(inbuf);
+  return iconv( cd, inbuf, inbytesleft, outbuf, outbytesleft );
 }
 
 int  UT_iconv_close( UT_iconv_t cd )
