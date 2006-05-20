--- clients/audio/auedit/auedit.c	Sun Jun 20 15:06:50 2004
+++ clients/audio/auedit/auedit.c	Mon Oct 10 11:16:16 2005
@@ -28,4 +28,5 @@
  */
 
+#include <inttypes.h>
 #include <stdio.h>
 
@@ -390,5 +390,5 @@
 {
     GlobalDataPtr   g = (GlobalDataPtr) gp;
-    int             p = (int) pp;
+    intptr_t        p = (intptr_t) pp;
     int             n;
 
@@ -406,5 +406,5 @@
 {
     GlobalDataPtr   g = (GlobalDataPtr) gp;
-    int             p = (int) pp;
+    intptr_t        p = (intptr_t) pp;
     int             n;
 
@@ -457,5 +457,5 @@
 {
     GlobalDataPtr   g = (GlobalDataPtr) gp;
-    int             gain = (int) gainp;
+    intptr_t        gain = (intptr_t) gainp;
     AuDeviceAttributes da;
 
@@ -1844,5 +1844,5 @@
 {
     GlobalDataPtr   g = (GlobalDataPtr) gp;
-    int             value = (int) valuep;
+    intptr_t        value = (intptr_t) valuep;
     AuElementParameters *parms;
     ElementListPtr  p = ElementList;
