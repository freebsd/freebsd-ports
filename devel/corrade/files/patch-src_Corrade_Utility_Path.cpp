--- src/Corrade/Utility/Path.cpp.orig	2023-01-12 11:52:02 UTC
+++ src/Corrade/Utility/Path.cpp
@@ -89,6 +89,11 @@
 #include <io.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
+
 #include "Corrade/configure.h"
 #include "Corrade/Containers/Array.h"
 #include "Corrade/Containers/GrowableArray.h"
@@ -540,6 +545,18 @@ Containers::Optional<Containers::String> executableLoc
     /* hardcoded for Emscripten */
     #elif defined(CORRADE_TARGET_EMSCRIPTEN)
     return Containers::String{"/app.js"_s};
+
+    #elif defined(__FreeBSD__)
+    Containers::Array<char> path;
+    size_t size;
+    const int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
+
+    sysctl(mib, 4, nullptr, &size, NULL, 0);
+    arrayResize(path, NoInit, size + 1);
+    sysctl(mib, 4, path, &size, NULL, 0);
+    path[size] = '\0';
+    const auto deleter = path.deleter();
+    return Containers::String{path.release(), size, deleter};
 
     /* Not implemented */
     #else
