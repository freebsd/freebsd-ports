--- clients/audio/aupanel/aupanel.c.orig	Tue Nov 22 03:09:06 2005
+++ clients/audio/aupanel/aupanel.c	Sat May 20 10:58:12 2006
@@ -28,6 +28,7 @@
  */
 
 #include <stdio.h>
+#include <inttypes.h>
 #include <stdlib.h>
 #ifndef SYSV
 #include <audio/Aos.h>		/* for string and other os stuff */
@@ -271,7 +272,7 @@
     if (!state)			/* ignore resets */
 	return;
 
-    AuDeviceInputMode(da) = (int) XawToggleGetCurrent(w) == 1
+    AuDeviceInputMode(da) = (intptr_t) XawToggleGetCurrent(w) == 1
 	? AuDeviceInputModeLineIn : AuDeviceInputModeMicrophone;
 
     AuSetDeviceAttributes(g->aud, AuDeviceIdentifier(da),
@@ -335,7 +336,7 @@
 {
     GlobalDataPtr   g = (GlobalDataPtr) gp;
     AuDeviceAttributes *da = &g->da[g->deviceNum];
-    int             value = (int) valuep;
+    intptr_t        value = (intptr_t) valuep;
 
     AuDeviceGain(da) = AuFixedPointFromSum(value, 0);
     AuSetDeviceAttributes(g->aud, AuDeviceIdentifier(da),
@@ -366,7 +367,7 @@
         g->restoreValues[g->deviceNum] = current;
         setGain(w, gp, (XtPointer)0);
     } else if(g->restoreValues[g->deviceNum] > 0){
-        setGain(w, gp, (XtPointer)g->restoreValues[g->deviceNum]);
+        setGain(w, gp, (XtPointer)(intptr_t)g->restoreValues[g->deviceNum]);
         g->restoreValues[g->deviceNum] = 0;
     }
     showDevice((GlobalDataPtr)gp);
