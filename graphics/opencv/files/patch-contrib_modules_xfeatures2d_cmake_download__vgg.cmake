--- contrib/modules/xfeatures2d/cmake/download_vgg.cmake.orig	2021-07-18 08:11:09 UTC
+++ contrib/modules/xfeatures2d/cmake/download_vgg.cmake
@@ -13,18 +13,12 @@ function(download_vgg_descriptors dst_dir status_var)
 
   set(${status_var} TRUE PARENT_SCOPE)
   foreach(id ${ids})
-    ocv_download(FILENAME ${name_${id}}
-                 HASH ${hash_${id}}
-                 URL
-                   "${OPENCV_VGGDESC_URL}"
-                   "$ENV{OPENCV_VGGDESC_URL}"
-                   "https://raw.githubusercontent.com/opencv/opencv_3rdparty/${OPENCV_3RDPARTY_COMMIT}/"
-                 DESTINATION_DIR "${dst_dir}"
-                 ID "xfeatures2d/vgg"
-                 RELATIVE_URL
-                 STATUS res)
-    if(NOT res)
-      set(${status_var} FALSE PARENT_SCOPE)
+     set(FILENAME ${dst_dir}/${name_${id}})
+     if(EXISTS ${FILENAME})
+        message("++ xfeatures2d/vgg: Using prefetched ${name_${id}}")
+     else()
+        message(WARNING "++ xfeatures2d/vgg: Could not find ${name_${id}} in ${FILENAME}")
+        set(${status_var} FALSE PARENT_SCOPE)
     endif()
   endforeach()
 endfunction()
