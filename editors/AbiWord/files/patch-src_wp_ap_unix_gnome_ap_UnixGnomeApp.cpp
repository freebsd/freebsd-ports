--- src/wp/ap/unix/gnome/ap_UnixGnomeApp.cpp.orig	Mon Mar 24 16:09:59 2003
+++ src/wp/ap/unix/gnome/ap_UnixGnomeApp.cpp	Mon Mar 24 16:10:31 2003
@@ -933,7 +933,7 @@
   // actually print
   s_actuallyPrint ( pDoc, pGraphics,
 		    pPrintView, "bonobo_printed_document",
-		    1, false,
+		    1, false, false,
 		    width, height,
 		    1, iPagesToPrint ) ;
   
