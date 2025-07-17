--- cmake/compilers/Clang.cmake.orig	2025-07-17 17:44:20 UTC
+++ cmake/compilers/Clang.cmake
@@ -65,7 +65,7 @@ set(TBB_COMMON_COMPILE_FLAGS ${TBB_COMMON_COMPILE_FLAG
 # Clang flags to prevent compiler from optimizing out security checks
 set(TBB_COMMON_COMPILE_FLAGS ${TBB_COMMON_COMPILE_FLAGS} -Wformat -Wformat-security -Werror=format-security -fPIC $<$<NOT:$<BOOL:${EMSCRIPTEN}>>:-fstack-protector-strong>)
 
-if (NOT APPLE AND NOT ANDROID_PLATFORM AND NOT CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64")
+if (NOT APPLE AND NOT ANDROID_PLATFORM AND NOT CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64" AND NOT CMAKE_SYSTEM_PROCESSOR MATCHES "powerpc")
     set(TBB_LIB_COMPILE_FLAGS ${TBB_LIB_COMPILE_FLAGS} -fstack-clash-protection $<$<NOT:$<BOOL:${EMSCRIPTEN}>>:-fcf-protection=full>)
 endif()
 
