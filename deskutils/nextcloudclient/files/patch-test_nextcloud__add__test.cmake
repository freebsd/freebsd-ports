--- test/nextcloud_add_test.cmake.orig	2021-09-30 11:13:39 UTC
+++ test/nextcloud_add_test.cmake
@@ -23,7 +23,7 @@ macro(nextcloud_add_test test_class)
         )
     endif()
 
-    if (UNIX)
+    if (LINUX)
         target_link_libraries(${OWNCLOUD_TEST_CLASS}Test
             "${synclib_NAME}_vfs_xattr"
         )
