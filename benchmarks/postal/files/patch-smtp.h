--- smtp.h.orig	2016-06-30 08:51:27 UTC
+++ smtp.h
@@ -6,7 +6,7 @@
 #include <cstring>
 #include <time.h>
 #include "conf.h"
-#include <tr1/unordered_map>
+#include <unordered_map>
 #include "tcp.h"
 #include "mutex.h"
 
@@ -25,7 +25,7 @@
   }
 };
 
-typedef std::tr1::unordered_map<unsigned long, string *, hash<unsigned long>, eqlng> NAME_MAP;
+typedef std::unordered_map<unsigned long, string *, hash<unsigned long>, eqlng> NAME_MAP;
 
 class smtpData
 {
