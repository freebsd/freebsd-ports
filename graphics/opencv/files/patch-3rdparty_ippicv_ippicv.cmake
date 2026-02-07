--- 3rdparty/ippicv/ippicv.cmake.orig	2021-07-05 12:03:22 UTC
+++ 3rdparty/ippicv/ippicv.cmake
@@ -34,18 +34,11 @@ function(download_ippicv root_var)
   endif()
 
   set(THE_ROOT "${OpenCV_BINARY_DIR}/3rdparty/ippicv")
-  ocv_download(FILENAME ${OPENCV_ICV_NAME}
-               HASH ${OPENCV_ICV_HASH}
-               URL
-                 "${OPENCV_IPPICV_URL}"
-                 "$ENV{OPENCV_IPPICV_URL}"
-                 "https://raw.githubusercontent.com/opencv/opencv_3rdparty/${IPPICV_COMMIT}/ippicv/"
-               DESTINATION_DIR "${THE_ROOT}"
-               ID IPPICV
-               STATUS res
-               UNPACK RELATIVE_URL)
-
-  if(res)
+  set(FILENAME ${THE_ROOT}/${OPENCV_ICV_PACKAGE_SUBDIR})
+  if(EXISTS ${FILENAME})
+    message("++ ippicv: Using prefetched ${OPENCV_ICV_PACKAGE_SUBDIR}")
     set(${root_var} "${THE_ROOT}/${OPENCV_ICV_PACKAGE_SUBDIR}" PARENT_SCOPE)
+  else()
+    message(WARNING "++ ippicv: Could not find ${OPENCV_ICV_PACKAGE_SUBDIR} in ${FILENAME}")
   endif()
 endfunction()
