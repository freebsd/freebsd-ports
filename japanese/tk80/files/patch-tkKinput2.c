--- tkKinput2.c.orig	Mon Dec 18 21:46:48 2006
+++ tkKinput2.c	Mon Dec 18 22:14:27 2006
@@ -552,6 +552,8 @@
 						      XEvent *event));
 static int		stopForwarding _ANSI_ARGS_ ((ClientData clientdata,
 						     XErrorEvent *errEvent));
+static int              checkProtocols _ANSI_ARGS_ ((Display *dpy,
+			    Window window, ConversionAtoms *cap));
 
 /*
  *--------------------------------------------------------------
@@ -585,8 +587,10 @@
     ConversionAtoms *cap;
     ConversionContext *context;
     int anyattr = False;
+    /* for gcc41
     static int checkProtocols _ANSI_ARGS_ ((Display *dpy,
 		       Window window, ConversionAtoms *cap));
+    */
 
     cap = getAtoms(tkwin);
 
