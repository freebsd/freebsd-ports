--- cmake/CPM.cmake.orig	2025-08-28 15:36:29 UTC
+++ cmake/CPM.cmake
@@ -16,7 +16,7 @@ get_filename_component (CPM_DOWNLOAD_LOCATION ${CPM_DO
 # Expand relative path. This is important if the provided path contains a tilde (~)
 get_filename_component (CPM_DOWNLOAD_LOCATION ${CPM_DOWNLOAD_LOCATION} ABSOLUTE)
 
-file (DOWNLOAD https://github.com/cpm-cmake/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake
+file (DOWNLOAD file://${CPM_LOCATION}/CPM.cmake
       ${CPM_DOWNLOAD_LOCATION} EXPECTED_HASH SHA256=${CPM_HASH_SUM})
 
 include (${CPM_DOWNLOAD_LOCATION})
