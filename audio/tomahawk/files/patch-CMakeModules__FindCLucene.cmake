--- ./CMakeModules/FindCLucene.cmake.orig	2013-04-29 23:22:22.000000000 +0200
+++ ./CMakeModules/FindCLucene.cmake	2013-04-29 23:23:02.000000000 +0200
@@ -85,14 +85,14 @@
 SET(CLUCENE_GOOD_VERSION TRUE)
 
 FIND_PATH(CLUCENE_LIBRARY_DIR
-	NAMES CLuceneConfig.cmake/CLuceneConfig.cmake CLucene/CLuceneConfig.cmake
-       	PATHS ${TRIAL_LIBRARY_PATHS} ${TRIAL_INCLUDE_PATHS} NO_DEFAULT_PATH)
+	NAMES CLuceneConfig.cmake CLucene/CLuceneConfig.cmake
+       	PATHS ${TRIAL_LIBRARY_PATHS} ${TRIAL_INCLUDE_PATHS} ${CLUCENE_CONFIG_PATH} NO_DEFAULT_PATH)
 IF (CLUCENE_LIBRARY_DIR)
   MESSAGE(STATUS "Found CLucene library dir: ${CLUCENE_LIBRARY_DIR}")
   # include CLuceneConfig/CLuceneConfig.cmake
-  IF(EXISTS ${CLUCENE_LIBRARY_DIR}/CLuceneConfig.cmake/CLuceneConfig.cmake)
-        INCLUDE(${CLUCENE_LIBRARY_DIR}/CLuceneConfig.cmake/CLuceneConfig.cmake)
-  ENDIF(EXISTS ${CLUCENE_LIBRARY_DIR}/CLuceneConfig.cmake/CLuceneConfig.cmake)
+  IF(EXISTS ${CLUCENE_LIBRARY_DIR}/CLuceneConfig.cmake)
+        INCLUDE(${CLUCENE_LIBRARY_DIR}/CLuceneConfig.cmake)
+  ENDIF(EXISTS ${CLUCENE_LIBRARY_DIR}/CLuceneConfig.cmake)
   # include CLucene/CLuceneConfig.cmake
   IF(EXISTS ${CLUCENE_LIBRARY_DIR}/CLucene/CLuceneConfig.cmake)
         INCLUDE(${CLUCENE_LIBRARY_DIR}/CLucene/CLuceneConfig.cmake)
