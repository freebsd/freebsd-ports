--- common/plppmdec.h.orig	Fri Dec 22 17:54:44 2006
+++ common/plppmdec.h	Fri Dec 22 18:01:20 2006
@@ -78,7 +78,7 @@
     );
 
 
-  PLPixel32 PLPPMDecoder::readASCIIPixel32
+  PLPixel32 readASCIIPixel32
     ( int MaxGrayValue,
       PLDataSource * pDataSrc
     );
