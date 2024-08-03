--- cmake/flags-gcc.cmake.orig	2024-07-26 18:17:03 UTC
+++ cmake/flags-gcc.cmake
@@ -16,8 +16,6 @@ string(APPEND CMAKE_CXX_FLAGS_INIT              " -fom
 # Define our flags
 string(APPEND CMAKE_C_FLAGS_INIT                " -fomit-frame-pointer -Wall -fno-strict-aliasing -Werror=implicit-int -Werror=implicit-function-declaration -Werror=int-conversion -Werror=strict-prototypes -Werror=old-style-definition")
 string(APPEND CMAKE_CXX_FLAGS_INIT              " -fomit-frame-pointer -Wall -fno-strict-aliasing")
-string(APPEND CMAKE_C_FLAGS_RELEASE_INIT        " -g0 -O3")
-string(APPEND CMAKE_CXX_FLAGS_RELEASE_INIT      " -g0 -O3")
 string(APPEND CMAKE_C_FLAGS_DEBUG_INIT          " -ggdb -Og")
 string(APPEND CMAKE_CXX_FLAGS_DEBUG_INIT        " -ggdb -Og")
 string(APPEND CMAKE_C_FLAGS_OPTIMIZED_INIT      " -march=native -mtune=native -O3 -ffp-contract=fast -flto")
