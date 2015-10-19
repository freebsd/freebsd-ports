--- common/cmake/gcc.cmake.orig	2015-09-17 06:11:18 UTC
+++ common/cmake/gcc.cmake
@@ -23,11 +23,11 @@ SET(FLAGS_AVX   "-mavx")
 SET(FLAGS_AVX2  "-mf16c -mavx2 -mfma -mlzcnt -mbmi -mbmi2")
 SET(FLAGS_AVX512 "-mavx512f -mavx512pf -mavx512er -mavx512cd")
 
-SET(CMAKE_CXX_COMPILER "g++")
-SET(CMAKE_C_COMPILER "gcc")
-SET(CMAKE_CXX_FLAGS "-fPIC -std=c++11 -fno-strict-aliasing -Wno-narrowing")
+#SET(CMAKE_CXX_COMPILER "g++")
+#SET(CMAKE_C_COMPILER "gcc")
+SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -std=c++11 -fno-strict-aliasing -Wno-narrowing")
 SET(CMAKE_CXX_FLAGS_DEBUG          "-DDEBUG  -g -O0")
-SET(CMAKE_CXX_FLAGS_RELEASE        "-DNDEBUG    -O3")
+SET(CMAKE_CXX_FLAGS_RELEASE        "-DNDEBUG")
 SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-DDEBUG  -g -O3")
 SET(CMAKE_EXE_LINKER_FLAGS "")
 
