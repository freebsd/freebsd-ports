--- hash_utils.h.orig	Mon Sep  1 02:32:24 2003
+++ hash_utils.h	Thu Jun 14 01:07:42 2007
@@ -26,7 +26,7 @@
 #else
 #if HAVE_EXT_HASH_MAP
 #  include <ext/hash_map>
-#  if (defined(__GNUC__) && (__GNUC__ == 3) && ( __GNUC_MINOR__ > 0))
+#  if (defined(__GNUC__) && ((__GNUC__ == 3) && ( __GNUC_MINOR__ > 0) || (__GNUC__ >= 4)))
 using __gnu_cxx::hash_map;
 #  else
 using std::hash_map;
@@ -44,7 +44,7 @@
 #else
 #if HAVE_EXT_HASH_SET
 #  include <ext/hash_set>
-#  if (defined(__GNUC__) && (__GNUC__ == 3) && ( __GNUC_MINOR__ > 0))
+#  if (defined(__GNUC__) && ((__GNUC__ == 3) && ( __GNUC_MINOR__ > 0) || (__GNUC__ >= 4)))
 using __gnu_cxx::hash_set;
 #  else
 using std::hash_set;
