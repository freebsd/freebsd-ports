--- contrib/modules/xfeatures2d/cmake/download_boostdesc.cmake.orig	2021-07-04 21:55:23 UTC
+++ contrib/modules/xfeatures2d/cmake/download_boostdesc.cmake
@@ -19,17 +19,11 @@ function(download_boost_descriptors dst_dir status_var
 
   set(${status_var} TRUE PARENT_SCOPE)
   foreach(id ${ids})
-    ocv_download(FILENAME ${name_${id}}
-                 HASH ${hash_${id}}
-                 URL
-                   "${OPENCV_BOOSTDESC_URL}"
-                   "$ENV{OPENCV_BOOSTDESC_URL}"
-                   "https://raw.githubusercontent.com/opencv/opencv_3rdparty/${OPENCV_3RDPARTY_COMMIT}/"
-                 DESTINATION_DIR ${dst_dir}
-                 ID "xfeatures2d/boostdesc"
-                 RELATIVE_URL
-                 STATUS res)
-    if(NOT res)
+    set(FILENAME ${dst_dir}/${name_${id}})
+    if(EXISTS ${FILENAME})
+      message("++ xfeatures2d/boostdesc: Using prefetched ${name_${id}}")
+    else()
+      message(WARNING "++ xfeatures2d/boostdesc: Could not find ${name_${id}} in ${FILENAME}")
       set(${status_var} FALSE PARENT_SCOPE)
     endif()
   endforeach()
