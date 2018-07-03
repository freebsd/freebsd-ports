--- src/loadimag.cpp.orig	2009-02-15 14:06:42 UTC
+++ src/loadimag.cpp
@@ -65,7 +65,7 @@ SDL_Surface *load_image(const std::strin
     DBG_WHINE("Unknown image extension: "+extension);
   }
 
-  return false;
+  return NULL;
 }
 
 //should this be extern "C"?
