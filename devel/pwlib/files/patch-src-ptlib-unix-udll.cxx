--- src/ptlib/unix/udll.cxx.orig	Wed Nov 30 13:47:42 2005
+++ src/ptlib/unix/udll.cxx	Wed Apr  5 22:36:51 2006
@@ -382,6 +382,10 @@
   dllHandle = dlopen((char *)(const char *)name, RTLD_NOW);
 #else
+  const char *dummyerr = dlerror();
   dllHandle = dlopen((const char *)name, RTLD_NOW);
+  const char *err = dlerror();
+  if (err != NULL)
+    cerr << err << '\n';
 #endif
 
   return IsLoaded();
