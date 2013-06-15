--- ./AboutThisBuild.cmake.orig	2013-05-29 16:29:36.000000000 +0200
+++ ./AboutThisBuild.cmake	2013-06-15 19:16:41.000000000 +0200
@@ -11,24 +11,9 @@
     find_file(HG_CMD hg)
     set (SHELL "/bin/bash")
   else (WIN32) # Linux
-    find_file(HG_CMD hg)
     set (SHELL "/bin/bash")
   endif (WIN32)
 
-  # Fail if Mercurial is not installed
-  if (HG_CMD STREQUAL HG_CMD-NOTFOUND)
-    message(FATAL_ERROR "hg command not found!")
-  else (HG_CMD STREQUAL HG_CMD-NOTFOUND)
-    message(STATUS "hg command found: ${HG_CMD}")
-  endif (HG_CMD STREQUAL HG_CMD-NOTFOUND)
-
-  execute_process(COMMAND ${HG_CMD} -R "${PROJECT_SOURCE_DIR}" branch OUTPUT_VARIABLE HG_BRANCH OUTPUT_STRIP_TRAILING_WHITESPACE)
-  execute_process(COMMAND ${HG_CMD} -R "${PROJECT_SOURCE_DIR}" parents --template={latesttag}.{latesttagdistance} WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" OUTPUT_VARIABLE HG_VERSION OUTPUT_STRIP_TRAILING_WHITESPACE)
-  execute_process(COMMAND ${HG_CMD} -R "${PROJECT_SOURCE_DIR}" parents --template={node|short} WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" OUTPUT_VARIABLE HG_CHANGESET OUTPUT_STRIP_TRAILING_WHITESPACE)
-  execute_process(COMMAND ${HG_CMD} -R "${PROJECT_SOURCE_DIR}" parents --template={latesttagdistance} WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" OUTPUT_VARIABLE HG_TAGDISTANCE OUTPUT_STRIP_TRAILING_WHITESPACE)
-  if (CACHE_NAME_SUFFIX STREQUAL "")
-    execute_process(COMMAND ${HG_CMD} -R "${PROJECT_SOURCE_DIR}" parents --template={latesttag} WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" OUTPUT_VARIABLE CACHE_NAME_SUFFIX OUTPUT_STRIP_TRAILING_WHITESPACE)
-  endif (CACHE_NAME_SUFFIX STREQUAL "")
 else (REL_INFO_FILE STREQUAL REL_INFO_FILE-NOTFOUND)
   include("${PROJECT_SOURCE_DIR}/ReleaseInfo.cmake")
 endif (REL_INFO_FILE STREQUAL REL_INFO_FILE-NOTFOUND)
