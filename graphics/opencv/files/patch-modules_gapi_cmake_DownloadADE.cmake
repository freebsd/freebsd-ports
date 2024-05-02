The ade distdata is downloaded and moved to the proper location by the ports 
framework.

--- modules/gapi/cmake/DownloadADE.cmake.orig	2023-12-27 16:46:55 UTC
+++ modules/gapi/cmake/DownloadADE.cmake
@@ -2,18 +2,12 @@ set(ade_md5 "dbb095a8bf3008e91edbbf45d8d34885")
 set(ade_filename "v0.1.2d.zip")
 set(ade_subdir "ade-0.1.2d")
 set(ade_md5 "dbb095a8bf3008e91edbbf45d8d34885")
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
+set(file_id ade-0.1.2d/CMakeLists.txt)
+set(FILENAME ${ade_src_dir}/${file_id})
+if(EXISTS ${FILENAME})
+    message("++ ade: Using prefetched ${file_id}")
+else()
+    message(WARNING "++ ade: Could not find ${file_id} in ${FILENAME}")
     return()
 endif()
 
