--- clients/audio/aupanel/aupanel.c	Thu Apr  7 15:08:14 2005
+++ clients/audio/aupanel/aupanel.c	Mon Oct 10 11:23:01 2005
@@ -29,4 +29,5 @@
 
 #include <stdio.h>
+#include <inttypes.h>
 #include <stdlib.h>
 #ifndef SYSV
@@ -262,5 +263,5 @@
 	return;
 
-    AuDeviceInputMode(da) = (int) XawToggleGetCurrent(w) == 1
+    AuDeviceInputMode(da) = (intptr_t) XawToggleGetCurrent(w) == 1
 	? AuDeviceInputModeLineIn : AuDeviceInputModeMicrophone;
 
@@ -326,5 +327,5 @@
     GlobalDataPtr   g = (GlobalDataPtr) gp;
     AuDeviceAttributes *da = &g->da[g->deviceNum];
-    int             value = (int) valuep;
+    intptr_t        value = (intptr_t) valuep;
 
     AuDeviceGain(da) = AuFixedPointFromSum(value, 0);
