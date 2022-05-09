--- cmake/FindLibunwind.cmake.orig	2022-05-09 10:37:16 UTC
+++ cmake/FindLibunwind.cmake
@@ -23,9 +23,15 @@
 
 
 find_path(LIBUNWIND_INCLUDE_DIR libunwind.h )
+if(CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+# FreeBSD 14 doesn't install an <unwind.h> header with
+# the libunwind port, and in any case it is not needed.
+message(STATUS "Assuming there is a corresponding unwind.h")
+else()
 if(NOT EXISTS "${LIBUNWIND_INCLUDE_DIR}/unwind.h")
   MESSAGE("Found libunwind.h but corresponding unwind.h is absent!")
   SET(LIBUNWIND_INCLUDE_DIR "")
+endif()
 endif()
 
 find_library(LIBUNWIND_LIBRARY unwind)
