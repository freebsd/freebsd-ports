--- cmn/game_style.cpp.orig	2003-03-22 20:47:42.000000000 +0100
+++ cmn/game_style.cpp	2007-07-31 15:57:08.000000000 +0200
@@ -34,7 +34,8 @@
 }
 
 #if X11
-#include <strstream.h>
+#include <strstream>
+using namespace std;
 #endif
 
 #if WIN32
@@ -2680,7 +2681,7 @@
     HumanP human = locator->get_human(n);
     if (human) {
       // previous depth
-      int depthOld = (int)human->get_data();
+      intptr_t depthOld = (intptr_t)human->get_data();
       Id id = human->get_id();
 
       // Get physical for intelligence
