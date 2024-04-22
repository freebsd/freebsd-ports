--- src/decoder/dec_mac.cpp.orig	2024-03-05 17:20:36 UTC
+++ src/decoder/dec_mac.cpp
@@ -178,7 +178,7 @@
 #ifdef __OpenBSD__
         wchar_t * pUTF16 = GetUTF16FromANSI(filename);
 #else
-        wchar_t * pUTF16 = CAPECharacterHelper::GetUTF16FromANSI(filename);
+        wchar_t * pUTF16 = GetUTF16FromANSI(filename);
 #endif
         pdecompress = CreateIAPEDecompress(pUTF16, &ret);
         free(pUTF16);
