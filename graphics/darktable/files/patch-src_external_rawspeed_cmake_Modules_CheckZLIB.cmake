--- src/external/rawspeed/cmake/Modules/CheckZLIB.cmake.orig	2023-12-10 23:28:08 UTC
+++ src/external/rawspeed/cmake/Modules/CheckZLIB.cmake
@@ -45,7 +45,7 @@ CHECK_PROTOTYPE_DEFINITION(zError
 CHECK_PROTOTYPE_DEFINITION(zError
  "const char* zError(int zErrorCode)"
  "NULL"
- "zlib.h"
+ "stddef.h;zlib.h"
  HAVE_ZLIB_ZERROR_PROTOTYPE)
 if(NOT HAVE_ZLIB_ZERROR_PROTOTYPE)
   message(SEND_ERROR "Found unexpected prototype for zError() in <zlib.h>")
