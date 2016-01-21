--- cmake/FindMsgPuck.cmake.orig	2016-01-20 13:26:58 UTC
+++ cmake/FindMsgPuck.cmake
@@ -9,6 +9,7 @@ endif (MSGPUCK_INCLUDE_DIR)
 if (MSGPUCK_INCLUDE_DIR)
     if (NOT MSGPUCK_FIND_QUIETLY)
         message(STATUS "Found msgpuck includes: ${MSGPUCK_INCLUDE_DIR}/msgpuck/msgpuck.h")
+        include_directories(${MSGPUCK_INCLUDE_DIR})
     endif (NOT MSGPUCK_FIND_QUIETLY)
 else (MSGPUCK_INCLUDE_DIR)
     if (MSGPUCK_REQUIRED)
