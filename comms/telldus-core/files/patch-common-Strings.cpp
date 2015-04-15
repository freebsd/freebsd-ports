--- common/Strings.cpp.orig	2014-03-31 10:30:09 UTC
+++ common/Strings.cpp
@@ -61,11 +61,7 @@ std::wstring TelldusCore::charToWstring(
 	char *outString = reinterpret_cast<char*>(new wchar_t[utf8Length+1]);
 	memset(outString, 0, sizeof(wchar_t)*(utf8Length+1));
 
-#ifdef _FREEBSD
-	const char *inPointer = inString;
-#else
 	char *inPointer = inString;
-#endif
 	char *outPointer = outString;
 
 	iconv_t convDesc = iconv_open(WCHAR_T_ENCODING, "UTF-8");
@@ -206,11 +202,7 @@ std::string TelldusCore::wideToString(co
 	char *outString = new char[outbytesLeft];
 	memset(outString, 0, sizeof(*outString)*(outbytesLeft));
 
-#ifdef _FREEBSD
-	const char *inPointer = inString;
-#else
 	char *inPointer = inString;
-#endif
 	char *outPointer = outString;
 
 	iconv_t convDesc = iconv_open("UTF-8", WCHAR_T_ENCODING);
