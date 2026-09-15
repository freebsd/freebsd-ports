-- Stop cmake from downloading the ADE sources at configure time.
-- The ADE sources are prefetched by the ports framework and placed into
-- the OpenCV source tree under opencv/3rdparty/ade.

--- opencv/modules/gapi/cmake/DownloadADE.cmake.orig	2025-07-04 16:37:46 UTC
+++ opencv/modules/gapi/cmake/DownloadADE.cmake
@@ -1,18 +1,12 @@
-set(ade_src_dir "${OpenCV_BINARY_DIR}/3rdparty/ade")
+set(ade_src_dir "${OpenCV_SOURCE_DIR}/3rdparty/ade")
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

