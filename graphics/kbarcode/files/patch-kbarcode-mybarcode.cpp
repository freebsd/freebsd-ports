--- kbarcode/mybarcode.cpp.orig	Sat Aug 21 11:07:42 2004
+++ kbarcode/mybarcode.cpp	Sat Aug 21 11:07:50 2004
@@ -58,7 +58,7 @@
     b = b && colors ==  d.colors;
     
     return b;
-};
+}
 
 BarCode::BarCode( const barcodeData* data )
 {
