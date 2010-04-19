--- src/libmonkeyaudio/APEDecompress.cpp.orig	2010-04-18 21:28:34.000000000 +0200
+++ src/libmonkeyaudio/APEDecompress.cpp	2010-04-18 21:28:51.000000000 +0200
@@ -369,7 +369,7 @@
 *****************************************************************************************/
 intptr_t CAPEDecompress::GetInfo(APE_DECOMPRESS_FIELDS Field, intptr_t nParam1, intptr_t nParam2)
 {
-    int nRetVal = 0;
+    intptr_t nRetVal = 0;
     BOOL bHandled = TRUE;
 
     switch (Field)
