--- About-Linux.cmake.orig	2011-08-07 14:16:30.000000000 -0700
+++ About-Linux.cmake	2011-08-07 14:19:03.000000000 -0700
@@ -12,16 +12,8 @@
 endif (HG_CMD STREQUAL HG_CMD-NOTFOUND)
 
 set (OUT_FILE "${SRC_DIR}/AboutThisBuild.txt")
-set (SHELL "/bin/bash")
+set (SHELL "/bin/sh")
 # there should be a better way of getting the compiler + compiler version, not restrained to Gcc
-execute_process(COMMAND gcc -dumpversion OUTPUT_VARIABLE GCC_VERSION OUTPUT_STRIP_TRAILING_WHITESPACE)
-execute_process(COMMAND ${HG_CMD} -R ${SRC_DIR} branch OUTPUT_VARIABLE HG_BRANCH OUTPUT_STRIP_TRAILING_WHITESPACE)
-execute_process(COMMAND ${HG_CMD} parents --template={latesttag}.{latesttagdistance} WORKING_DIRECTORY ${SRC_DIR} OUTPUT_VARIABLE HG_VERSION OUTPUT_STRIP_TRAILING_WHITESPACE)
-execute_process(COMMAND ${HG_CMD} parents --template={node|short} WORKING_DIRECTORY ${SRC_DIR} OUTPUT_VARIABLE HG_CHANGESET OUTPUT_STRIP_TRAILING_WHITESPACE)
-execute_process(COMMAND ${HG_CMD} parents --template={latesttagdistance} WORKING_DIRECTORY ${SRC_DIR} OUTPUT_VARIABLE HG_TAGDISTANCE OUTPUT_STRIP_TRAILING_WHITESPACE)
-if (CACHE_NAME_SUFFIX STREQUAL "")
-  execute_process(COMMAND ${HG_CMD} parents --template={latesttag} WORKING_DIRECTORY ${SRC_DIR} OUTPUT_VARIABLE CACHE_NAME_SUFFIX OUTPUT_STRIP_TRAILING_WHITESPACE)
-endif ()
 
 # build version.h from template
 configure_file (${SRC_DIR}/rtgui/version.h.in ${SRC_DIR}/rtgui/version.h)
