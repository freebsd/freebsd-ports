--- src/CMakeData-arch.cmake.orig	2016-03-30 16:08:58 UTC
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
