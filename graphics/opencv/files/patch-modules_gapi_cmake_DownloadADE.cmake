The ade distdata is downloaded and moved to the proper location by the ports 
framework.

--- modules/gapi/cmake/DownloadADE.cmake.orig	2021-07-05 12:03:22 UTC
+++ modules/gapi/cmake/DownloadADE.cmake
@@ -2,22 +2,18 @@ set(ade_src_dir "${OpenCV_BINARY_DIR}/3rdparty/ade")
 set(ade_filename "v0.1.1f.zip")
 set(ade_subdir "ade-0.1.1f")
 set(ade_md5 "b624b995ec9c439cbc2e9e6ee940d3a2")
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
 
-if (NOT res)
+set(file_id ade-0.1.1f/CMakeLists.txt)
+set(FILENAME ${ade_src_dir}/${file_id})
+if(EXISTS ${FILENAME})
+    message("++ ade: Using prefetched ${file_id}")
+else()
+    message(WARNING "++ ade: Could not find ${file_id} in ${FILENAME}")
     return()
-endif()
+ endif()
 
 set(ADE_root "${ade_src_dir}/${ade_subdir}/sources/ade")
+
 file(GLOB_RECURSE ADE_sources "${ADE_root}/source/*.cpp")
 file(GLOB_RECURSE ADE_include "${ADE_root}/include/ade/*.hpp")
 add_library(ade STATIC ${OPENCV_3RDPARTY_EXCLUDE_FROM_ALL}
