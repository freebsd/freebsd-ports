--- src/CMakeLists.txt.orig	2023-12-27 13:53:12.178934000 +0000
+++ src/CMakeLists.txt	2023-12-27 13:53:23.287048000 +0000
@@ -10,7 +10,7 @@
 include_directories(${READLINE_INCLUDE_DIRS})
 include_directories(${LIBYAML_INCLUDE_DIRS})
 include_directories(${MSGPUCK_INCLUDE_DIRS})
-include_directories(BEFORE ${CURL_INCLUDE_DIRS})
+include_directories(${CURL_INCLUDE_DIRS})
 include_directories(${ICU_INCLUDE_DIRS})
 include_directories(${ICONV_INCLUDE_DIRS})
 include_directories(${DECNUMBER_INCLUDE_DIR})
