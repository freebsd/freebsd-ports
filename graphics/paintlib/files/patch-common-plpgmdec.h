--- common/plpgmdec.h.orig	Fri Dec 22 17:54:22 2006
+++ common/plpgmdec.h	Fri Dec 22 18:00:19 2006
@@ -72,7 +72,7 @@
       PLDataSource * pDataSrc
     );
 
-  PLBYTE PLPGMDecoder::readASCIIPixel8
+  PLBYTE readASCIIPixel8
     ( int MaxGrayValue,
       PLDataSource * pDataSrc
     );
