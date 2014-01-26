--- src/gtk/glx_3Demu.cpp.orig	2013-11-28 01:36:53.712615000 +0100
+++ src/gtk/glx_3Demu.cpp	2013-12-14 20:08:01.000000000 +0100
@@ -41,11 +41,7 @@
         glXDestroyContext(dpy, ctx);
 
         XCloseDisplay(dpy);
-
-        return true;
     }
-
-    return false;
 }
 
 int init_glx_3Demu(void) 
