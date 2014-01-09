--- ../../meshlab/src/meshlabplugins/decorate_base/colorhistogram.h.orig	2013-11-16 22:04:41.000000000 +0100
+++ ../../meshlab/src/meshlabplugins/decorate_base/colorhistogram.h	2013-11-16 22:04:56.000000000 +0100
@@ -39,10 +39,11 @@
   //ScalarType BinWidth(ScalarType v);
 
   //! Reset histogram data.
+  /* dead code
   void Clear() {
     this->::Clear();
     CV.clear();
-  }
+  } */
   /*
   Note that the histogram holds <n> valid bins plus two semi-infinite bins.
 
