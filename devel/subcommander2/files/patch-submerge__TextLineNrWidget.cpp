--- submerge/TextLineNrWidget.cpp.orig	2010-06-20 22:28:45.000000000 +0900
+++ submerge/TextLineNrWidget.cpp	2012-10-02 17:09:22.000000000 +0900
@@ -71,7 +71,7 @@
   sc::Size lines = _model->getLineCnt();
 
   char buf[16] = "";
-  _lnColumns   = sprintf( buf, "%lu", lines );
+  _lnColumns   = sprintf( buf, "%lu", static_cast<unsigned long>(lines) );
 
   updateGeometry();
 }
