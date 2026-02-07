--- ./cmake/modules/lasi.cmake.orig	2009-11-06 18:00:00.106405553 +0100
+++ ./cmake/modules/lasi.cmake	2009-11-06 18:00:11.236964944 +0100
@@ -120,10 +120,10 @@
 # doxygen support
 # =======================================================================
 
-find_package(Doxygen)
-if(NOT DOXYGEN_EXECUTABLE)
-  message(STATUS "WARNING: Doxygen not found so documentation not generated.")
-endif(NOT DOXYGEN_EXECUTABLE)
+#find_package(Doxygen)
+#if(NOT DOXYGEN_EXECUTABLE)
+#  message(STATUS "WARNING: Doxygen not found so documentation not generated.")
+#endif(NOT DOXYGEN_EXECUTABLE)
 
 # =======================================================================
 # Prepare summary macro that is used later.
