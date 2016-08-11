--- src/decoder/dec_mac.cpp.orig	2015-04-19 12:49:49 UTC
+++ src/decoder/dec_mac.cpp
@@ -174,7 +174,7 @@ mac_decoder_open(decoder_t * dec, char *
 
 
 	int ret = 0;
-        wchar_t * pUTF16 = CAPECharacterHelper::GetUTF16FromANSI(filename);
+        wchar_t * pUTF16 = GetUTF16FromANSI(filename);
         pdecompress = CreateIAPEDecompress(pUTF16, &ret);
         free(pUTF16);
 
