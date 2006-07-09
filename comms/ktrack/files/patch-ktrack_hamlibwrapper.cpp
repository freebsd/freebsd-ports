--- ktrack/hamlibwrapper.cpp.orig	Sun Jan 18 03:25:00 2004
+++ ktrack/hamlibwrapper.cpp	Thu Feb 23 11:23:18 2006
@@ -18,6 +18,7 @@
 #include <string.h>
 #include <stdlib.h>
 #include <kapplication.h>
+#include <math.h>
 
 #include "hamlibwrapper.h"
 
@@ -100,6 +101,7 @@
   // open the rig
   if (rig_open(downlinkRig) != RIG_OK) {
     retval--;
+    downlinkRig->caps->rig_model=RIG_MODEL_DUMMY;
   }
 
 
@@ -116,8 +118,9 @@
     uplinkRig=rig_init(urig);
     uplinkRig->state.rigport.parm.serial.rate=uspeed;
     strcpy(downlinkRig->state.rigport.pathname, uport);
-    if (rig_open(downlinkRig) != RIG_OK) {
+    if (rig_open(uplinkRig) != RIG_OK) {
 			retval--;
+			uplinkRig->caps->rig_model=RIG_MODEL_DUMMY;
     }
   }
 
@@ -248,13 +251,16 @@
   int errorcode;
   freq_t frequency=0;
   mutex.lock();
-  errorcode=rig_get_freq(downlinkRig, downlinkvfo, &frequency);
-  if (errorcode!=RIG_OK) {
-    fprintf(stderr, "WARNING: Error fetching frequency from Radio! Using default Frequency!\n");
-    errorstring=rigerror(errorcode);
-    if (errorstring)
-      fprintf(stderr, "The reported error was: %s\n", errorstring);
-    frequency=433000000;
+  if (downlinkRig->caps->rig_model != RIG_MODEL_DUMMY) {
+    errorcode=rig_get_freq(downlinkRig, downlinkvfo, &frequency);
+    if (errorcode!=RIG_OK) {
+      fprintf(stderr, "WARNING: Error fetching frequency from Radio! Using default Frequency!\n");
+      errorstring=rigerror(errorcode);
+      if (errorstring)
+        fprintf(stderr, "The reported error was: %s\n", errorstring);
+      downlinkRig->caps->rig_model = RIG_MODEL_DUMMY;
+      frequency=433000000;
+    }
   }
   // sleep on dummy rig - that saves CPU power
   if (downlinkRig->caps->rig_model == RIG_MODEL_DUMMY)
