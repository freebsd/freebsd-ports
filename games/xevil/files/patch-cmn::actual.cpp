--- cmn/actual.cpp.orig	2000-01-19 12:54:36.000000000 +0100
+++ cmn/actual.cpp	2007-07-31 15:47:25.000000000 +0200
@@ -32,7 +32,8 @@
 
 // Include Files
 #if X11
-#include <strstream.h>
+#include <strstream>
+using namespace std;
 #endif
 #if WIN32
 #include <strstrea.h>
@@ -1534,7 +1535,7 @@
                                                  void *closure) {
   // notThis is used to prevent transmogifying into the same class an object
   // already is.
-  ClassId notThis = (ClassId)closure;
+  ClassId notThis = (intptr_t)closure;
   if (pc->classId == notThis) {
     return False;
   }
