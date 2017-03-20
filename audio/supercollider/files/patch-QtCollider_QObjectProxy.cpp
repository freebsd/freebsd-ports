--- QtCollider/QObjectProxy.cpp.orig	2017-03-20 15:18:39 UTC
+++ QtCollider/QObjectProxy.cpp
@@ -38,6 +38,8 @@
 
 #ifdef _WIN32
 # include "SC_Win32Utils.h"
+#elif defined(__FreeBSD__)
+# include <stdlib.h>
 #else
 # include <alloca.h>
 #endif
