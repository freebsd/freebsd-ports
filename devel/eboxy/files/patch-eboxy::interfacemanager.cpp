--- eboxy/interfacemanager.cpp.orig	Thu May 20 16:46:55 2004
+++ eboxy/interfacemanager.cpp	Thu May 20 21:22:10 2004
@@ -16,6 +16,7 @@
  ***************************************************************************/
 
 #include <iostream>
+#include <cstdio>
 
 #include "dlfcn.h"
 #include "main.h"
@@ -48,7 +49,7 @@
   libhandle = dlopen(libfile, RTLD_LAZY);
   if(libhandle == 0) {
     // Load failed
-    char *errorstr = dlerror();
+    const char *errorstr = dlerror();
     cerr << "InterfaceManager: Couldn't load interface plugin " << libfile << endl;
     cerr << errorstr << endl;
     return EBERR_DLOPEN_FAILED;  // Failed to load library
