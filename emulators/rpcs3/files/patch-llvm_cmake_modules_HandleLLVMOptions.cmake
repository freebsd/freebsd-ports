/usr/bin/ld: unrecognized option '--color-diagnostics'
/usr/bin/ld: use the --help option for usage information
c++: error: linker command failed with exit code 1 (use -v to see invocation)

--- llvm/cmake/modules/HandleLLVMOptions.cmake.orig	2018-05-03 16:52:23 UTC
+++ llvm/cmake/modules/HandleLLVMOptions.cmake
@@ -717,7 +717,6 @@ endif()
 # lld doesn't print colored diagnostics when invoked from Ninja
 if (UNIX AND CMAKE_GENERATOR STREQUAL "Ninja")
   include(CheckLinkerFlag)
-  check_linker_flag("-Wl,--color-diagnostics" LINKER_SUPPORTS_COLOR_DIAGNOSTICS)
   append_if(LINKER_SUPPORTS_COLOR_DIAGNOSTICS "-Wl,--color-diagnostics"
     CMAKE_EXE_LINKER_FLAGS CMAKE_MODULE_LINKER_FLAGS CMAKE_SHARED_LINKER_FLAGS)
 endif()
