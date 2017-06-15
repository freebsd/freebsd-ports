--- cmake/cflags.cmake.orig	2017-01-05 04:17:18 UTC
+++ cmake/cflags.cmake
@@ -2,7 +2,7 @@
 # Each of our project dirs sets CMAKE_CXX_FLAGS based on these. We do
 # not set CMAKE_CXX_FLAGS globally because gtest is not warning-clean.
 if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "\\w*Clang")
-    set(LEATHERMAN_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Werror -Wno-unused-parameter -Wno-tautological-constant-out-of-range-compare")
+    set(LEATHERMAN_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-tautological-constant-out-of-range-compare")
 
     # Clang warns that 'register' is deprecated; 'register' is used throughout boost, so it can't be an error yet.
     # The warning flag is different on different clang versions so we need to extract the clang version.
@@ -41,7 +41,7 @@ elseif ("${CMAKE_CXX_COMPILER_ID}" STREQ
     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-maybe-uninitialized")
 
     # missing-field-initializers is disabled because GCC can't make up their mind how to treat C++11 initializers
-    set(LEATHERMAN_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror -Wno-unused-parameter -Wno-unused-local-typedefs -Wno-unknown-pragmas -Wno-missing-field-initializers")
+    set(LEATHERMAN_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wno-unused-parameter -Wno-unused-local-typedefs -Wno-unknown-pragmas -Wno-missing-field-initializers")
     if (NOT "${CMAKE_SYSTEM_NAME}" MATCHES "SunOS")
         set(LEATHERMAN_CXX_FLAGS "${LEATHERMAN_CXX_FLAGS} -Wextra")
     endif()
