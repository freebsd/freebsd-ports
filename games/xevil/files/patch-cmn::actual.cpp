--- cmn/actual.cpp.orig	Wed Jan 19 12:54:36 2000
+++ cmn/actual.cpp	Sat Oct 25 21:39:07 2003
@@ -32,7 +32,8 @@
 
 // Include Files
 #if X11
-#include <strstream.h>
+#include <strstream>
+using namespace std;
 #endif
 #if WIN32
 #include <strstrea.h>
