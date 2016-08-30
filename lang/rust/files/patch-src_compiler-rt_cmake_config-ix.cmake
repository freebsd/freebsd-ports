--- src/compiler-rt/cmake/config-ix.cmake.orig	2016-08-16 01:54:40 UTC
+++ src/compiler-rt/cmake/config-ix.cmake
@@ -188,20 +188,9 @@ if(ANDROID)
   set(COMPILER_RT_OS_SUFFIX "-android")
 elseif(NOT APPLE) # Supported archs for Apple platforms are generated later
   if("${COMPILER_RT_DEFAULT_TARGET_ARCH}" MATCHES "i[2-6]86|x86|amd64")
-    if(NOT MSVC)
-      test_target_arch(x86_64 "" "-m64")
-      # FIXME: We build runtimes for both i686 and i386, as "clang -m32" may
-      # target different variant than "$CMAKE_C_COMPILER -m32". This part should
-      # be gone after we resolve PR14109.
-      test_target_arch(i686 __i686__ "-m32")
-      test_target_arch(i386 __i386__ "-m32")
-    else()
-      if (CMAKE_SIZEOF_VOID_P EQUAL 4)
-        test_target_arch(i386 "" "")
-      else()
-        test_target_arch(x86_64 "" "")
-      endif()
-    endif()
+    test_target_arch(x86_64 "" "")
+    test_target_arch(i686 "" "")
+    test_target_arch(i386 "" "")
   elseif("${COMPILER_RT_DEFAULT_TARGET_ARCH}" MATCHES "powerpc")
     TEST_BIG_ENDIAN(HOST_IS_BIG_ENDIAN)
     if(HOST_IS_BIG_ENDIAN)
