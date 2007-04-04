--- ./frmts/fit/fitdataset.cpp.orig	Wed Apr  4 16:33:12 2007
+++ ./frmts/fit/fitdataset.cpp	Wed Apr  4 16:33:23 2007
@@ -174,7 +174,7 @@
 
 public:
 
-    FITRasterBand::FITRasterBand( FITDataset *, int );
+    FITRasterBand( FITDataset *, int );
 	~FITRasterBand();
     
     // should override RasterIO eventually.
