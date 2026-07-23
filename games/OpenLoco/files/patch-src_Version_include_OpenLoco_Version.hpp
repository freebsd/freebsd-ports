--- src/Version/include/OpenLoco/Version.hpp.orig	2026-05-30 08:07:06 UTC
+++ src/Version/include/OpenLoco/Version.hpp
@@ -18,6 +18,12 @@
     #else
         #define OPENLOCO_ARCHITECTURE "arm"
     #endif
+#elif defined(__powerpc__)
+    #if defined(__powerpc64__)
+        #define OPENLOCO_ARCHITECTURE "powerpc64"
+    #else
+        #define OPENLOCO_ARCHITECTURE "powerpc"
+    #endif
 #else
     #error "OPENLOCO_ARCHITECTURE is undefined. Please add identification."
 #endif
