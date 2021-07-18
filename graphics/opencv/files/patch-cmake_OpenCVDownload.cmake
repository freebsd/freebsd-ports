TODO: instead of patching the callers of ocv_download() to not use it,
it would be nicer to just make ocv_download use the cached file from
${FILESDIR}

--- cmake/OpenCVDownload.cmake.orig	2021-07-18 09:08:36 UTC
+++ cmake/OpenCVDownload.cmake
@@ -159,6 +159,7 @@ function(ocv_download)
     ocv_download_log("#cmake_download \"${CACHE_CANDIDATE}\" \"${DL_URL}\"")
     foreach(try ${OPENCV_DOWNLOAD_TRIES_LIST})
       ocv_download_log("#try ${try}")
+      message(FATAL_ERROR "++ Trying to download file ${CACHE_CANDIDATE} via cmake from ${DL_URL}")
       file(DOWNLOAD "${DL_URL}" "${CACHE_CANDIDATE}"
            STATUS status
            LOG __log
