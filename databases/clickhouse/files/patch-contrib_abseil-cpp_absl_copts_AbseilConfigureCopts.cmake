--- contrib/abseil-cpp/absl/copts/AbseilConfigureCopts.cmake.orig	2021-09-10 11:00:21 UTC
+++ contrib/abseil-cpp/absl/copts/AbseilConfigureCopts.cmake
@@ -12,7 +12,9 @@ else()
   set(ABSL_BUILD_DLL FALSE)
 endif()
 
-if("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x86_64" OR "${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "AMD64")
+string (TOUPPER ${CMAKE_SYSTEM_PROCESSOR} CMAKE_SYSTEM_PROCESSOR_UC)
+
+if(CMAKE_SYSTEM_PROCESSOR_UC STREQUAL "X86_64" OR CMAKE_SYSTEM_PROCESSOR_UC STREQUAL "AMD64")
   if (MSVC)
     set(ABSL_RANDOM_RANDEN_COPTS "${ABSL_RANDOM_HWAES_MSVC_X64_FLAGS}")
   else()
