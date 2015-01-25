--- meshlabplugins/decorate_base/colorhistogram.h.orig	2013-07-17 17:20:11.000000000 +0200
+++ meshlabplugins/decorate_base/colorhistogram.h	2015-01-24 18:01:12.000000000 +0100
@@ -39,10 +39,11 @@
   //ScalarType BinWidth(ScalarType v);
 
   //! Reset histogram data.
+  /* dead code
   void Clear() {
     Histogram<ScalarType>::Clear();
     CV.clear();
-  }
+  } */
   /*
   Note that the histogram holds <n> valid bins plus two semi-infinite bins.
 
