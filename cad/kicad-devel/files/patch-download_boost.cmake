--- CMakeModules/download_boost.cmake.orig	2013-09-17 18:50:32.424234883 +0000
+++ CMakeModules/download_boost.cmake	2013-09-17 18:33:58.024299100 +0000
@@ -167,4 +167,5 @@
 
 ExternalProject_Add_Step( boost bzr_commit_boost
+    COMMAND bzr whoami "M R <mr@freebsd.org>"
     COMMAND bzr ci -q -m pristine <SOURCE_DIR>
     COMMENT "committing pristine boost files to 'boost scratch repo'"
