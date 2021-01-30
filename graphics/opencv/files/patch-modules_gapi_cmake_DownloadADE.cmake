The ade distdata is downloaded and moved to the proper location by the ports 
framework.

--- modules/gapi/cmake/DownloadADE.cmake.orig	2020-12-21 20:01:38 UTC
+++ modules/gapi/cmake/DownloadADE.cmake
@@ -1,23 +1,9 @@
 set(ade_src_dir "${OpenCV_BINARY_DIR}/3rdparty/ade")
 set(ade_filename "v0.1.1f.zip")
 set(ade_subdir "ade-0.1.1f")
-set(ade_md5 "b624b995ec9c439cbc2e9e6ee940d3a2")
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
-    return()
-endif()
-
 set(ADE_root "${ade_src_dir}/${ade_subdir}/sources/ade")
+
 file(GLOB_RECURSE ADE_sources "${ADE_root}/source/*.cpp")
 file(GLOB_RECURSE ADE_include "${ADE_root}/include/ade/*.hpp")
 add_library(ade STATIC ${ADE_include} ${ADE_sources})
