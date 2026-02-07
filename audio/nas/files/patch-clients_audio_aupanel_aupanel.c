--- clients/audio/aupanel/aupanel.c.orig	2013-10-07 17:05:47 UTC
+++ clients/audio/aupanel/aupanel.c
@@ -28,6 +28,7 @@
  */
 
 #include <stdio.h>
+#include <inttypes.h>
 #include <stdlib.h>
 #ifndef SYSV
 #include <audio/Aos.h>		/* for string and other os stuff */
@@ -280,7 +281,7 @@ inputModeCB(Widget w, XtPointer gp, XtPo
     if (!state)			/* ignore resets */
 	return;
 
-    AuDeviceInputMode(da) = (int) XawToggleGetCurrent(w) == 1
+    AuDeviceInputMode(da) = (intptr_t) XawToggleGetCurrent(w) == 1
 	? AuDeviceInputModeLineIn : AuDeviceInputModeMicrophone;
 
     AuSetDeviceAttributes(g->aud, AuDeviceIdentifier(da),
@@ -331,7 +332,7 @@ setGain(Widget w, XtPointer gp, XtPointe
 {
     GlobalDataPtr   g = (GlobalDataPtr) gp;
     AuDeviceAttributes *da = &g->da[g->deviceNum];
-    int             value = (int) valuep;
+    intptr_t        value = (intptr_t) valuep;
 
     AuDeviceGain(da) = AuFixedPointFromSum(value, 0);
     AuSetDeviceAttributes(g->aud, AuDeviceIdentifier(da),
@@ -359,7 +360,7 @@ muteCB(Widget w, XtPointer gp, XtPointer
         g->restoreValues[g->deviceNum] = current;
         setGain(w, gp, (XtPointer)0);
     } else if(g->restoreValues[g->deviceNum] > 0){
-        setGain(w, gp, (XtPointer)g->restoreValues[g->deviceNum]);
+        setGain(w, gp, (XtPointer)(intptr_t)g->restoreValues[g->deviceNum]);
         g->restoreValues[g->deviceNum] = 0;
     }
     showDevice((GlobalDataPtr)gp);
