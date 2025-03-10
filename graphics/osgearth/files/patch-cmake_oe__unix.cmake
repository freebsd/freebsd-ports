--- cmake/oe_unix.cmake.orig	2024-07-24 17:28:38 UTC
+++ cmake/oe_unix.cmake
@@ -12,8 +12,7 @@ if(UNIX AND NOT ANDROID)
     # for ptheads in linux
     find_package(Threads REQUIRED)
     
-    # add 64 to the lib prefix.
-    set(INSTALL_LIBRARY_FOLDER "lib64")
-    set(INSTALL_PLUGINS_FOLDER "lib64")
+    set(INSTALL_LIBRARY_FOLDER "lib")
+    set(INSTALL_PLUGINS_FOLDER "lib")
     
 endif(UNIX AND NOT ANDROID)
