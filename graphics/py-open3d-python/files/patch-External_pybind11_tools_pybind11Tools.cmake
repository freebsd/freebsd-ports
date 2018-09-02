--- External/pybind11/tools/pybind11Tools.cmake.orig	2018-09-02 16:32:40 UTC
+++ External/pybind11/tools/pybind11Tools.cmake
@@ -69,17 +69,19 @@ function(_pybind11_add_lto_flags target_
         set(cxx_append ";-fno-fat-lto-objects")
       endif()
 
-      if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" AND prefer_thin_lto)
-        _pybind11_return_if_cxx_and_linker_flags_work(HAS_FLTO_THIN
-          "-flto=thin${cxx_append}" "-flto=thin${linker_append}"
-          PYBIND11_LTO_CXX_FLAGS PYBIND11_LTO_LINKER_FLAGS)
-      endif()
+      # Disable -flto because it fails on 12: /usr/local/bin/ld: /usr/bin/../lib/LLVMgold.so: error loading plugin: Cannot open "/usr/bin/../lib/LLVMgold.so"
+      # It is only activated on 12, not 11, for some reason.
+      #if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" AND prefer_thin_lto)
+      #  _pybind11_return_if_cxx_and_linker_flags_work(HAS_FLTO_THIN
+      #    "-flto=thin${cxx_append}" "-flto=thin${linker_append}"
+      #    PYBIND11_LTO_CXX_FLAGS PYBIND11_LTO_LINKER_FLAGS)
+      #endif()
 
-      if (NOT HAS_FLTO_THIN)
-        _pybind11_return_if_cxx_and_linker_flags_work(HAS_FLTO
-          "-flto${cxx_append}" "-flto${linker_append}"
-          PYBIND11_LTO_CXX_FLAGS PYBIND11_LTO_LINKER_FLAGS)
-      endif()
+      #if (NOT HAS_FLTO_THIN)
+      #  _pybind11_return_if_cxx_and_linker_flags_work(HAS_FLTO
+      #    "-flto${cxx_append}" "-flto${linker_append}"
+      #    PYBIND11_LTO_CXX_FLAGS PYBIND11_LTO_LINKER_FLAGS)
+      #endif()
     elseif (CMAKE_CXX_COMPILER_ID MATCHES "Intel")
       # Intel equivalent to LTO is called IPO
       _pybind11_return_if_cxx_and_linker_flags_work(HAS_INTEL_IPO
