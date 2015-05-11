--- src/spot/pskrep.cxx.orig	2015-03-21 00:29:04 UTC
+++ src/spot/pskrep.cxx
@@ -50,7 +50,7 @@
 #include <algorithm>
 #include <fstream>
 
-#if GCC_VER_OK
+#if GCC_VER_OK || HAVE_STD_HASH
 #	if HAVE_STD_HASH
 #		define MAP_TYPE std::unordered_map
 #		define HASH_TYPE std::hash
