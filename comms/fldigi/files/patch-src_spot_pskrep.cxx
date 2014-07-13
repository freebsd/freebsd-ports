--- src/spot/pskrep.cxx.orig	2014-07-04 15:11:14.000000000 -0700
+++ src/spot/pskrep.cxx	2014-07-04 15:13:32.000000000 -0700
@@ -50,7 +50,7 @@
 #include <algorithm>
 #include <fstream>
 
-#if GCC_VER_OK
+#if GCC_VER_OK || HAVE_STD_HASH
 #	if HAVE_STD_HASH
 #		define MAP_TYPE std::unordered_map
 #		define HASH_TYPE std::hash
