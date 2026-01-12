--- Source/MACLib/Prepare.cpp.orig	2026-01-12 09:35:06 UTC
+++ Source/MACLib/Prepare.cpp
@@ -1,6 +1,9 @@
 #include "All.h"
 #include "Prepare.h"
 #include "CRC.h"
+#if APE_BYTE_ORDER == APE_BIG_ENDIAN
+#include "GlobalFunctions.h"
+#endif
 
 #if APE_BYTE_ORDER == APE_LITTLE_ENDIAN
     #define APE_24_SHIFT_1ST 0
