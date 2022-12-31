--- src/external/rawspeed/cmake/Modules/CheckZLIB.cmake.orig	2022-12-13 01:49:58 UTC
+++ src/external/rawspeed/cmake/Modules/CheckZLIB.cmake
@@ -44,7 +44,7 @@ endif()
 CHECK_PROTOTYPE_DEFINITION(zError
  "const char* zError(int zErrorCode)"
  "NULL"
- "zlib.h"
+ "stddef.h;zlib.h"
  HAVE_ZLIB_ZERROR_PROTOTYPE)
 if(NOT HAVE_ZLIB_ZERROR_PROTOTYPE)
   message(SEND_ERROR "Found unexpected prototype for zError() in <zlib.h>")
