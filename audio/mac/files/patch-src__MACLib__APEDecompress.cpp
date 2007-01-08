--- ./src/MACLib/APEDecompress.cpp.orig	Tue Jan  9 01:08:49 2007
+++ ./src/MACLib/APEDecompress.cpp	Tue Jan  9 01:09:55 2007
@@ -369,7 +369,7 @@
 *****************************************************************************************/
 intptr_t CAPEDecompress::GetInfo(APE_DECOMPRESS_FIELDS Field, intptr_t nParam1, intptr_t nParam2)
 {
-    int nRetVal = 0;
+    intptr_t nRetVal = 0;
     BOOL bHandled = TRUE;
 
     switch (Field)
