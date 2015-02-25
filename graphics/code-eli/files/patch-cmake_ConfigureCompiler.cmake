--- cmake/ConfigureCompiler.cmake.orig	2014-08-17 07:02:14 UTC
+++ cmake/ConfigureCompiler.cmake
@@ -135,7 +135,7 @@ if(NOT CONFIGURE_COMPILER_INCLUDED)
   # set GNU Compiler Collection flags
   if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
     set(CONFIGURE_COMPILER_SET_C_COMPILER_FLAGS ON)
-    set(CMAKE_C_FLAGS "-pedantic -Wall -Wextra -fmessage-length=100 -std=c99"
+    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic -Wall -Wextra -fmessage-length=100 -std=c99"
                       CACHE STRING "Flags used by the compiler during all build types." FORCE)
     set(CMAKE_C_FLAGS_DEBUG "-DDEBUG -O0 -g"
                       CACHE STRING "Flags used by the compiler during debug builds." FORCE)
@@ -152,9 +152,9 @@ if(NOT CONFIGURE_COMPILER_INCLUDED)
   if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
     set(CONFIGURE_COMPILER_SET_CXX_COMPILER_FLAGS ON)
     if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.7")
-      set(CMAKE_CXX_FLAGS "-std=c++0x")
+      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
     else()
-      set(CMAKE_CXX_FLAGS "-std=c++11")
+      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
     endif()
     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -Wno-long-long -fmessage-length=100"
                         CACHE STRING "Flags used by the compiler during all build types." FORCE)
@@ -189,7 +189,7 @@ if(NOT CONFIGURE_COMPILER_INCLUDED)
       set(CMAKE_XCODE_ATTRIBUTE_GCC_WARN_INHIBIT_ALL_WARNINGS "YES")
       set(CMAKE_XCODE_ATTRIBUTE_GCC_WARN_PEDANTIC "YES")
     else()
-      set(CMAKE_C_FLAGS "-pedantic -Wall -Wextra -fmessage-length=100 -std=c99"
+      set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic -Wall -Wextra -fmessage-length=100 -std=c99"
                         CACHE STRING "Flags used by the compiler during all build types." FORCE)
     endif()
     set(CMAKE_C_FLAGS_DEBUG "-DDEBUG -O0 -g"
@@ -212,7 +212,7 @@ if(NOT CONFIGURE_COMPILER_INCLUDED)
       set(CMAKE_XCODE_ATTRIBUTE_GCC_WARN_INHIBIT_ALL_WARNINGS "YES")
       set(CMAKE_XCODE_ATTRIBUTE_GCC_WARN_PEDANTIC "YES")
     else()
-      set(CMAKE_CXX_FLAGS "-pedantic -Wall -Wextra -Wno-long-long -fmessage-length=100 -std=c++11 -stdlib=libc++"
+      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -Wno-long-long -fmessage-length=100 -std=c++11 -stdlib=libc++"
                           CACHE STRING "Flags used by the compiler during all build types." FORCE)
     endif()
     set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG -O0 -g"
