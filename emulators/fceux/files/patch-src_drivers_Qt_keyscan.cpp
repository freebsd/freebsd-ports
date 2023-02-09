--- src/drivers/Qt/keyscan.cpp.orig	2023-02-13 00:05:10 UTC
+++ src/drivers/Qt/keyscan.cpp
@@ -46,7 +46,7 @@ static uint32_t AltKeyCodeR   = VK_RMENU;
 static uint32_t MetaKeyCodeR  = VK_RWIN;
 static BYTE keyBuf[256];
 
-#elif  defined(__linux__)
+#elif  defined(__linux__) || defined(__FreeBSD__)
 
    #if  defined(_HAS_XKB)
 	#include <xkbcommon/xkbcommon.h>
