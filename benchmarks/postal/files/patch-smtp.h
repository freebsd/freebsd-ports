--- smtp.h.orig
+++ smtp.h
@@ -4,14 +4,18 @@
 using namespace std;
 #include <string>
 #include <cstring>
-#include <time.h>
+#include <ctime>
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
 #include "tcp.h"
 #include "mutex.h"
 
@@ -30,7 +34,11 @@
   }
 };
 
+#if defined(_LIBCPP_VERSION)
+typedef std::unordered_map<unsigned long, string *, hash<unsigned long>, eqlng> NAME_MAP;
+#else
 typedef hash_map<unsigned long, string *, hash<unsigned long>, eqlng> NAME_MAP;
+#endif
 
 class smtpData
 {
