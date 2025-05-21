The ade distdata is downloaded and moved to the proper location by the ports 
framework.

--- modules/gapi/cmake/DownloadADE.cmake.orig	2025-04-26 12:11:25 UTC
+++ modules/gapi/cmake/DownloadADE.cmake
@@ -2,18 +2,12 @@ set(ade_md5 "962ce79e0b95591f226431f7b5f152cd")
 set(ade_filename "v0.1.2e.zip")
 set(ade_subdir "ade-0.1.2e")
 set(ade_md5 "962ce79e0b95591f226431f7b5f152cd")
-ocv_download(FILENAME ${ade_filename}
-             HASH ${ade_md5}
-             URL
-               "${OPENCV_ADE_URL}"
-               "$ENV{OPENCV_ADE_URL}"
-               "https://github.com/opencv/ade/archive/"
-             DESTINATION_DIR ${ade_src_dir}
-             ID ADE
-             STATUS res
-             UNPACK RELATIVE_URL)
-
-if (NOT res)
+set(file_id ade-0.1.2e/CMakeLists.txt)
+set(FILENAME ${ade_src_dir}/${file_id})
+if(EXISTS ${FILENAME})
+    message("++ ade: Using prefetched ${file_id}")
+else()
+    message(WARNING "++ ade: Could not find ${file_id} in ${FILENAME}")
     return()
 endif()
 
