--- ./printwizard/tphoto.cpp.orig	Sat Sep  4 11:43:00 2004
+++ ./printwizard/tphoto.cpp	Sat Sep  4 11:43:12 2004
@@ -86,12 +86,12 @@
 int TPhoto::width()
 {
   return size().width();
-};
+}
 
 int TPhoto::height()
 {
   return size().height();
-};
+}
 
 
 bool paintOnePage(QPainter &p, QPtrList<TPhoto> photos, QPtrList<QRect> layouts,
