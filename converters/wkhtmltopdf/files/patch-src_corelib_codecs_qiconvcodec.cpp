--- src/corelib/codecs/qiconvcodec.cpp.orig	2015-01-03 18:06:52 UTC
+++ src/corelib/codecs/qiconvcodec.cpp
@@ -219,12 +219,7 @@ QString QIconvCodec::convertToUnicode(co
     IconvState *state = *pstate;
     size_t inBytesLeft = len;
     // best case assumption, each byte is converted into one UTF-16 character, plus 2 bytes for the BOM
-#ifdef GNU_LIBICONV
-    // GNU doesn't disagree with POSIX :/
-    const char *inBytes = chars;
-#else
     char *inBytes = const_cast<char *>(chars);
-#endif
 
     QByteArray in;
     if (remainingCount) {
@@ -318,11 +313,7 @@ static bool setByteOrder(iconv_t cd)
     size_t outBytesLeft = sizeof buf;
     size_t inBytesLeft = sizeof bom;
 
-#if defined(GNU_LIBICONV)
-    const char **inBytesPtr = const_cast<const char **>(&inBytes);
-#else
     char **inBytesPtr = &inBytes;
-#endif
 
     if (iconv(cd, inBytesPtr, &inBytesLeft, &outBytes, &outBytesLeft) == (size_t) -1) {
         return false;
@@ -338,11 +329,7 @@ QByteArray QIconvCodec::convertFromUnico
     char *outBytes;
     size_t inBytesLeft;
 
-#if defined(GNU_LIBICONV)
-    const char **inBytesPtr = const_cast<const char **>(&inBytes);
-#else
     char **inBytesPtr = &inBytes;
-#endif
 
     IconvState *temporaryState = 0;
     QThreadStorage<QIconvCodec::IconvState *> *ts = fromUnicodeState();
