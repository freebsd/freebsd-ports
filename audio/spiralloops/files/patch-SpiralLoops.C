$FreeBSD$

--- SpiralLoops.C.orig	Thu Apr 19 13:48:11 2001
+++ SpiralLoops.C	Thu May 23 02:16:36 2002
@@ -308,7 +308,7 @@
         Run     = (Sample *(*)()) dlsym(handle, "Run__Fv");
         
                 
-        if ((error = dlerror()) != NULL)
+        if ((error = (char *)dlerror()) != NULL)
         {
         	cerr<<"Error linking to plugin:"<<endl;
 		    fputs(error, stderr);
