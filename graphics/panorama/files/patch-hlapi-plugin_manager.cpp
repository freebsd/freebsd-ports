--- hlapi/plugin_manager.cpp.orig	Thu Nov 21 01:54:16 2002
+++ hlapi/plugin_manager.cpp	Wed Feb  2 18:54:59 2005
@@ -48,6 +48,12 @@
   void*                pvHandle      = NULL;
   bool                 gAbsolutePath = ( rktNAME[0] == '/' );
 
+  /*
+   * Reset dlerror() since it can contain error from previous
+   * call to dlopen()/dlsym().
+   */
+  dlerror();
+
   if ( gAbsolutePath )
   {
     pvHandle = dlopen (rktNAME.c_str(), RTLD_NOW | RTLD_GLOBAL);
