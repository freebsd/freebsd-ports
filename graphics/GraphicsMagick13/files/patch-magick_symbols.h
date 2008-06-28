--- magick/symbols.h.orig	Mon Jul 16 21:55:06 2007
+++ magick/symbols.h	Mon Jul 16 21:56:04 2007
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
