--- ./radiant/qgl.cpp.orig	Thu Mar 16 16:09:46 2006
+++ ./radiant/qgl.cpp	Thu Mar 16 16:09:46 2006
@@ -654,7 +654,7 @@
   qglXWaitX                    = glXWaitX;
   qglXUseXFont                 = glXUseXFont;
 //  qglXGetProcAddressARB        = glXGetProcAddressARB; // Utah-GLX fix
-  qglXGetProcAddressARB = (glXGetProcAddressARBProc)dlsym(NULL, "glXGetProcAddressARB"); 
+  qglXGetProcAddressARB = (glXGetProcAddressARBProc)dlsym(RTLD_DEFAULT, "glXGetProcAddressARB"); 
 #endif
 
 #if defined (__linux__) || defined (__APPLE__) || defined (__FreeBSD__)
