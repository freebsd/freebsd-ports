Fix compilation against libidngi 1.9.1

In file included from /wrkdirs/usr/ports/astro/phd2/work/phd2-2.6.9dev5/stepguider_sxao_indi.cpp:40:
In file included from /wrkdirs/usr/ports/astro/phd2/work/phd2-2.6.9dev5/phdindiclient.h:37:
/usr/local/include/libindi/baseclient.h:27:10: error: 'indimacros.h' file not found with <angled> include; use "quotes" instead
#include <indimacros.h>
         ^
1 warning and 1 error generated.

--- thirdparty/thirdparty.cmake.orig	2021-08-06 09:18:28 UTC
+++ thirdparty/thirdparty.cmake
@@ -660,7 +660,7 @@ else()
     find_package(INDI 0.9 REQUIRED)
     # source files include <libindi/baseclient.h> so we need the libindi parent directory in the include directories
     get_filename_component(INDI_INCLUDE_PARENT_DIR ${INDI_INCLUDE_DIR} DIRECTORY)
-    include_directories(${INDI_INCLUDE_PARENT_DIR})
+    include_directories(${INDI_INCLUDE_PARENT_DIR} ${INDI_INCLUDE_DIR})
     if(INDI_VERSION VERSION_LESS "1.4")
       set(PHD_LINK_EXTERNAL ${PHD_LINK_EXTERNAL} ${INDI_CLIENT_LIBRARIES} ${INDI_LIBRARIES})
     else(INDI_VERSION VERSION_LESS "1.4")
