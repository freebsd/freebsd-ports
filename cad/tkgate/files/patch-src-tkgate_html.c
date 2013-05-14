--- src/tkgate/html.c.orig	2013-05-14 14:43:09.000000000 +0200
+++ src/tkgate/html.c	2013-05-14 14:43:39.000000000 +0200
@@ -894,7 +894,7 @@
   ob_touch(hc);
 
   DoTcl("gifI %s",gifFile);
-  hu->hu_image = Tk_GetImage(TkGate.tcl, Tk_MainWindow(TkGate.tcl), TkGate.tcl->result, 0, 0);
+  hu->hu_image = Tk_GetImage(TkGate.tcl, Tk_MainWindow(TkGate.tcl), Tcl_GetStringResult(TkGate.tcl), 0, 0);
   if (hu->hu_image)
     Tk_SizeOfImage(hu->hu_image, &width, &height);
 
