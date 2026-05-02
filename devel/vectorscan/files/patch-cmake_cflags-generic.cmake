--- cmake/cflags-generic.cmake.orig	2026-05-02 04:09:59 UTC
+++ cmake/cflags-generic.cmake
@@ -1,6 +1,6 @@
 # set compiler flags - more are tested and added later
-set(EXTRA_C_FLAGS "${OPT_C_FLAG} -std=c17 -Wall -Wextra ")
-set(EXTRA_CXX_FLAGS "${OPT_CXX_FLAG} -std=c++17 -Wall -Wextra ")
+set(EXTRA_C_FLAGS "-std=c17 -Wall -Wextra ")
+set(EXTRA_CXX_FLAGS "-std=c++17 -Wall -Wextra ")
 if (NOT CMAKE_COMPILER_IS_CLANG)
     set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -fno-new-ttp-matching")
 endif()
