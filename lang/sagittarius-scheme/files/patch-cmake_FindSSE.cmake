--- cmake/FindSSE.cmake.orig	2017-09-23 20:35:38 UTC
+++ cmake/FindSSE.cmake
@@ -5,6 +5,7 @@
 MACRO (FindSSE)
   # SSE is only for x86 and relatives
   IF(CMAKE_SYSTEM_PROCESSOR MATCHES "i.86" OR
+     CMAKE_SYSTEM_PROCESSOR MATCHES "amd64" OR
      CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")
    IF(CMAKE_SYSTEM_NAME MATCHES "Linux" OR CYGWIN)
      EXEC_PROGRAM(cat ARGS "/proc/cpuinfo" OUTPUT_VARIABLE CPUINFO)
@@ -122,6 +123,57 @@ MACRO (FindSSE)
      set(SSE4_1_FOUND false CACHE BOOL "SSE4.1 available on host")
      set(SSE4_2_FOUND false CACHE BOOL "SSE4.2 available on host")
      set(AVX_FOUND    false CACHE BOOL "AVX available on host")
+
+   ELSEIF(CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+     EXEC_PROGRAM(%%CPUID%% OUTPUT_VARIABLE CPUINFO)
+
+     STRING(REGEX REPLACE "^.*,(SSE2).*$" "\\1" SSE_THERE ${CPUINFO})
+     STRING(COMPARE EQUAL "SSE2" "${SSE_THERE}" SSE2_TRUE)
+     IF (SSE2_TRUE)
+       set(SSE2_FOUND true CACHE BOOL "SSE2 available on host")
+     ELSE (SSE2_TRUE)
+       set(SSE2_FOUND false CACHE BOOL "SSE2 available on host")
+     ENDIF (SSE2_TRUE)
+
+     STRING(REGEX REPLACE "^.*<(SSE3).*$" "\\1" SSE_THERE ${CPUINFO})
+     STRING(COMPARE EQUAL "SSE3" "${SSE_THERE}" SSE3_TRUE)
+
+     STRING(REGEX REPLACE "^.*,(SSSE3).*$" "\\1" SSE_THERE ${CPUINFO})
+     STRING(COMPARE EQUAL "SSSE3" "${SSE_THERE}" SSSE3_TRUE)
+     IF (SSE3_TRUE OR SSSE3_TRUE)
+       set(SSE3_FOUND true CACHE BOOL "SSE3 available on host")
+     ELSE (SSE3_TRUE OR SSSE3_TRUE)
+       set(SSE3_FOUND false CACHE BOOL "SSE3 available on host")
+     ENDIF (SSE3_TRUE OR SSSE3_TRUE)
+     IF (SSSE3_TRUE)
+       set(SSSE3_FOUND true CACHE BOOL "SSSE3 available on host")
+     ELSE (SSSE3_TRUE)
+       set(SSSE3_FOUND false CACHE BOOL "SSSE3 available on host")
+     ENDIF (SSSE3_TRUE)
+
+     STRING(REGEX REPLACE "^.*,(SSE4\\.1).*$" "\\1" SSE_THERE ${CPUINFO})
+     STRING(COMPARE EQUAL "SSE4.1" "${SSE_THERE}" SSE41_TRUE)
+     IF (SSE41_TRUE)
+       set(SSE4_1_FOUND true CACHE BOOL "SSE4.1 available on host")
+     ELSE (SSE41_TRUE)
+       set(SSE4_1_FOUND false CACHE BOOL "SSE4.1 available on host")
+     ENDIF (SSE41_TRUE)
+
+     STRING(REGEX REPLACE "^.*,(SSE4\\.2).*$" "\\1" SSE_THERE ${CPUINFO})
+     STRING(COMPARE EQUAL "SSE4.2" "${SSE_THERE}" SSE42_TRUE)
+     IF (SSE42_TRUE)
+       set(SSE4_2_FOUND true CACHE BOOL "SSE4.2 available on host")
+     ELSE (SSE42_TRUE)
+       set(SSE4_2_FOUND false CACHE BOOL "SSE4.2 available on host")
+     ENDIF (SSE42_TRUE)
+
+     STRING(REGEX REPLACE "^.*,(AVX).*$" "\\1" SSE_THERE ${CPUINFO})
+     STRING(COMPARE EQUAL "AVX" "${SSE_THERE}" AVX_TRUE)
+     IF (AVX_TRUE)
+       set(AVX_FOUND true CACHE BOOL "AVX available on host")
+     ELSE (AVX_TRUE)
+       set(AVX_FOUND false CACHE BOOL "AVX available on host")
+     ENDIF (AVX_TRUE)
    ELSE()
      set(SSE2_FOUND   true  CACHE BOOL "SSE2 available on host")
      set(SSE3_FOUND   false CACHE BOOL "SSE3 available on host")
