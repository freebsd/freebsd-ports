--- FILTERS/cso/importer.C.orig	Wed Mar 14 20:30:21 2001
+++ FILTERS/cso/importer.C	Fri Jan 31 20:11:34 2003
@@ -26,7 +26,7 @@
   // find the address of the routine called "import"
   void (*import)(void*, char**) = (void (*)(void*, char**))dlsym(handle, "import");
   //  void (*import)(xrml::world*, char**) = (void (*)(xrml::world*, char**))dlsym(handle, "import__FPQ24xrml5worldPPc");
-  char *error = dlerror();
+  const char *error = dlerror();
   if (error) {
     Error(NULL, "%s", error);
     return false;
