--- cmn/intel.cpp.orig	Wed Mar 19 09:49:22 2003
+++ cmn/intel.cpp	Sat Oct 25 21:42:14 2003
@@ -35,7 +35,8 @@
   #include <string.h>
 }
 #if X11
-#include <strstream.h>
+#include <strstream>
+using namespace std;
 #endif
 #if WIN32
 #include <strstrea.h>
