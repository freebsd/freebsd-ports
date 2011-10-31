--- src/calibre/ebooks/pdf/reflow.cpp.orig	2011-10-26 01:52:43.000000000 +0000
+++ src/calibre/ebooks/pdf/reflow.cpp	2011-10-26 12:02:17.000000000 +0000
@@ -625,11 +625,7 @@ static string get_link_dest(LinkAction *
   return oss.str();
 }
 
-#if (POPPLER_MAJOR_VERSION == 0) && (POPPLER_MINOR_VERSION < 17)
-void XMLOutputDev::process_link(Link* link){
-#else
 void XMLOutputDev::process_link(AnnotLink* link){
-#endif
 
   double _x1, _y1, _x2, _y2;
   int x1, y1, x2, y2;
