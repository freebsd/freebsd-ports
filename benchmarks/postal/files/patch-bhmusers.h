--- bhmusers.h.orig	2016-06-30 08:57:25 UTC
+++ bhmusers.h
@@ -6,7 +6,7 @@
 #include <string>
 #include "conf.h"
 
-#include <tr1/unordered_map>
+#include <unordered_map>
 
 #include "postal.h"
 
@@ -18,7 +18,7 @@
   int sync_time;
 } BHM_DATA;
 
-typedef std::tr1::unordered_map<string, BHM_DATA, hash<string> > NAME_MAP;
+typedef std::unordered_map<string, BHM_DATA, hash<string> > NAME_MAP;
 
 class BHMUsers
 {
