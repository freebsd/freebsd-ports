--- bhmusers.h.orig	2006-09-28 15:20:28 UTC
+++ bhmusers.h
@@ -6,12 +6,16 @@ using namespace std;
 #include <string>
 #include "conf.h"
 
+#if defined(_LIBCPP_VERSION)
+#include <unordered_map>
+#else
 #ifdef HAVE_EXT_HASH_MAP
 using namespace __gnu_cxx;
 #include <ext/hash_map>
 #else
 #include <hash_map.h>
 #endif
+#endif
 
 #include "postal.h"
 
@@ -23,7 +27,12 @@ typedef struct
   int sync_time;
 } BHM_DATA;
 
+
+#if defined(_LIBCPP_VERSION)
+namespace std
+#else
 namespace __gnu_cxx
+#endif
 {
   template<> struct hash< std::string >
   {
@@ -34,7 +43,11 @@ namespace __gnu_cxx
   };
 }
 
+#if defined(_LIBCPP_VERSION)
+typedef std::unordered_map<string, BHM_DATA , hash<string> > NAME_MAP;
+#else
 typedef hash_map<string, BHM_DATA , hash<string> > NAME_MAP;
+#endif
 
 class BHMUsers
 {
