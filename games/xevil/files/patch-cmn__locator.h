--- cmn/locator.h.orig	2012-05-27 06:52:31.000000000 +0900
+++ cmn/locator.h	2012-05-27 06:53:11.000000000 +0900
@@ -47,7 +47,7 @@
 
 
 // Include Files
-#include <iostream.h>
+#include <iostream>
 
 #include "utils.h"
 #include "coord.h"
@@ -96,6 +96,8 @@
 #define OL_RECENT_SOUNDS_MAX 30
 
 
+class OLgridEntry;
+class OLshadowEntry;
 
 // An entry for one object in the list of all objects currently in the game.
 class OLentry {
