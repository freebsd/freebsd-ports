--- simgear/screen/extensions.cxx.orig	Tue Nov  9 13:31:54 2004
+++ simgear/screen/extensions.cxx	Tue Nov  9 13:32:10 2004
@@ -113,7 +113,7 @@
     if (libHandle != NULL) {
         fptr = dlsym(libHandle, func);
 
-        char *error = dlerror();
+        const char *error = dlerror();
         if (error)
             SG_LOG(SG_GENERAL, SG_INFO, error);
     }
