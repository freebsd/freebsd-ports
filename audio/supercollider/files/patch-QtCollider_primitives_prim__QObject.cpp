--- QtCollider/primitives/prim_QObject.cpp.orig	2017-03-20 15:18:39 UTC
+++ QtCollider/primitives/prim_QObject.cpp
@@ -39,6 +39,8 @@
 
 #ifdef _WIN32
 # include "SC_Win32Utils.h"
+#elif defined(__FreeBSD__)
+# include <stdlib.h>
 #else
 # include <alloca.h>
 #endif
