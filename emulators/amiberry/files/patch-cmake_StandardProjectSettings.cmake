--- cmake/StandardProjectSettings.cmake.orig	2026-04-26 10:53:54 UTC
+++ cmake/StandardProjectSettings.cmake
@@ -83,6 +83,13 @@ if(WITH_LTO)
 endif()
 
 if(WITH_LTO)
+	# ensure LTO links with lld on FreeBSD/clang.
+    if(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD" AND CMAKE_CXX_COMPILER_ID MATCHES "Clang")
+        string(APPEND CMAKE_EXE_LINKER_FLAGS " -fuse-ld=lld")
+        string(APPEND CMAKE_SHARED_LINKER_FLAGS " -fuse-ld=lld")
+        string(APPEND CMAKE_MODULE_LINKER_FLAGS " -fuse-ld=lld")
+    endif()
+
     include(CheckIPOSupported)
     check_ipo_supported(RESULT lto_supported OUTPUT lto_error)
     if(lto_supported)
