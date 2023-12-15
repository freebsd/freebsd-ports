--- include/glaze/api/lib.hpp.orig	2023-12-15 09:23:51 UTC
+++ include/glaze/api/lib.hpp
@@ -29,7 +29,7 @@
 #include <dlfcn.h>
 #define SHARED_LIBRARY_EXTENSION ".dylib"
 #define SHARED_LIBRARY_PREFIX "lib"
-#elif __linux__
+#elif defined(__linux__) || defined(__FreeBSD__)
 #include <dlfcn.h>
 #define SHARED_LIBRARY_EXTENSION ".so"
 #define SHARED_LIBRARY_PREFIX "lib"
