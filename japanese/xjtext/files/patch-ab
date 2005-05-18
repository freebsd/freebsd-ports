--- xwindow.h.orig	Sat Sep  4 22:45:16 1999
+++ xwindow.h	Mon May 16 15:51:32 2005
@@ -1,12 +1,14 @@
 #ifndef _XWINDOW
 #define _XWINDOW
-#include <stream.h>
+#include <iostream>
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
 #include <X11/Xatom.h>
 #include <X11/extensions/shape.h>
 #include <Imlib.h>
 
+using namespace std;
+
 extern  Display*         TheDisplay;
 typedef unsigned long    ulong;
 typedef unsigned int     uint;
@@ -35,7 +37,7 @@
     XColor Exact; XColor NewColor;
     if(XAllocNamedColor(TheDisplay,CMap,ColorName,&Exact,&NewColor)==0)
     {
-      cerr<<form("Can't allocate the color specified by \"%s\".\n",ColorName);
+      cerr<<("Can't allocate the color specified by \"%s\".\n",ColorName);
       return BlackPixel(TheDisplay,TheScreen);
     }
     else return NewColor.pixel;
@@ -60,7 +62,7 @@
     XSetLineAttributes(TheDisplay,TheGC,1,LineSolid,CapButt,JoinMiter);
     XDrawLine(TheDisplay,TheWindow,TheGC,X1,Y1,X2,Y2);
   }
-  inline                mapRaised(void) {  XMapRaised(TheDisplay,TheWindow);}
+  inline void           mapRaised(void) {  XMapRaised(TheDisplay,TheWindow);}
 };
 
 #endif
