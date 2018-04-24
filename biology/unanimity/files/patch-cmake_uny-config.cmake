--- cmake/uny-config.cmake.orig	2016-09-12 19:55:43 UTC
+++ cmake/uny-config.cmake
@@ -1,6 +1,6 @@
 # Config generation
 
-find_git_sha1(UNANIMITY_GIT_SHA1)
+# find_git_sha1(UNANIMITY_GIT_SHA1)
 
 file (STRINGS "${UNY_RootDir}/CHANGELOG.md" UNANIMITY_CHANGELOG)
 
