--- ../luxrays/cmake/PlatformSpecific.cmake.orig
+++ ../luxrays/cmake/PlatformSpecific.cmake
@@ -138,18 +138,17 @@ ENDIF(MSVC)
 
 
 
-IF(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
+#IF(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
   # Update if necessary
-  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
-  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse -msse2 -msse3 -mssse3")
+  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long")
+  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse")
   IF(NOT CYGWIN)
 	  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
   ENDIF(NOT CYGWIN)
 
   SET(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
-  SET(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O3 -ftree-vectorize -fvariable-expansion-in-unroller")
-  
-ENDIF()
+  SET(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG")
+#ENDIF()
 
 
 # Setting Universal Binary Properties, only for Mac OS X
