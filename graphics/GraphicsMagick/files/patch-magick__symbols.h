--- ./magick/symbols.h.orig	2004-04-14 18:45:07.000000000 -0400
+++ ./magick/symbols.h	2008-09-02 08:05:29.000000000 -0400
@@ -17,6 +17,8 @@
 #if !defined(_MAGICK_SYMBOLS_H)
 #define _MAGICK_SYMBOLS_H
 
+#define GetToken GmGetToken
+
 #if defined(PREFIX_MAGICK_SYMBOLS)
 #define AccessDefinition GmAccessDefinition
 #define AcquireCacheNexus GmAcquireCacheNexus
@@ -386,7 +388,6 @@
 #define GetQuantizeInfo GmGetQuantizeInfo
 #define GetSignatureInfo GmGetSignatureInfo
 #define GetTimerInfo GmGetTimerInfo
-#define GetToken GmGetToken
 #define GetTypeInfo GmGetTypeInfo
 #define GetTypeInfoByFamily GmGetTypeInfoByFamily
 #define GetTypeList GmGetTypeList
