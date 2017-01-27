--- include/SFML/Config.hpp.orig	2016-11-03 06:50:51 UTC
+++ include/SFML/Config.hpp
@@ -81,7 +81,7 @@
          // Linux
         #define SFML_SYSTEM_LINUX
 
-    #elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+    #elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
 
         // FreeBSD
         #define SFML_SYSTEM_FREEBSD
