--- src/CMakeData-arch.cmake.orig	2015-10-30 06:55:52 UTC
+++ src/CMakeData-arch.cmake
@@ -243,7 +243,7 @@ else()
     list(APPEND SMDATA_ARCH_LOADING_HPP
       "arch/LoadingWindow/LoadingWindow_MacOSX.h"
     )
-  elseif(LINUX)
+  else()
     if (GTK2_FOUND)
       list(APPEND SMDATA_ARCH_LOADING_SRC
         "arch/LoadingWindow/LoadingWindow_Gtk.cpp"
