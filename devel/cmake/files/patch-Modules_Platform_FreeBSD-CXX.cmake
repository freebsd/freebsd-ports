This prefers c++ over CC as the C++ compiler command. See PR 203793.

Upstreamed as 6f666f4335c7f6b44fc4ccdc886590094fdfa16d
Will be included in CMake 3.10

--- Modules/Platform/FreeBSD-CXX.cmake.orig	2017-06-14 21:54:30 UTC
+++ Modules/Platform/FreeBSD-CXX.cmake
@@ -0,0 +1,3 @@
+if(NOT CMAKE_CXX_COMPILER_NAMES)
+  set(CMAKE_CXX_COMPILER_NAMES c++)
+endif()
