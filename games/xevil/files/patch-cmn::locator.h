--- cmn/locator.h.orig	Sat Mar 22 20:35:30 2003
+++ cmn/locator.h	Fri Oct  6 13:44:36 2006
@@ -47,7 +47,8 @@
 
 
 // Include Files
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 
 #include "utils.h"
 #include "coord.h"
@@ -108,12 +109,12 @@
 
   
   // Only valid if mapped || flash.
-  OLgridEntry *gridEntry; 
+  class OLgridEntry *gridEntry; 
   // Set by OLgridEntry::insert.  Not nec. valid.
   GLoc gloc; 
 #if X11
   // Only valid if mapped || flash.
-  OLshadowEntry *shadowEntry; 
+  class OLshadowEntry *shadowEntry; 
   // Set by OLshadowEntry::insert.  Not nec. valid.
   GLoc shadowGloc; 
 #endif
