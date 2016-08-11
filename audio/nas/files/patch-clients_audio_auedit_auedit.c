--- clients/audio/auedit/auedit.c.orig	2013-10-07 17:05:48 UTC
+++ clients/audio/auedit/auedit.c
@@ -27,6 +27,7 @@
  * $NCDId: @(#)auedit.c,v 1.35 1995/12/06 01:10:29 greg Exp $
  */
 
+#include <inttypes.h>
 #include <stdio.h>
 
 #include "config.h"
@@ -389,7 +390,7 @@ XtPointer       gp;
 XtPointer       pp;
 {
     GlobalDataPtr   g = (GlobalDataPtr) gp;
-    int             p = (int) pp;
+    intptr_t        p = (intptr_t) pp;
     int             n;
 
     XtVaGetValues(g->graph, XtNrightMarker, &n, NULL);
@@ -405,7 +406,7 @@ XtPointer       gp;
 XtPointer       pp;
 {
     GlobalDataPtr   g = (GlobalDataPtr) gp;
-    int             p = (int) pp;
+    intptr_t        p = (intptr_t) pp;
     int             n;
 
     XtVaGetValues(g->graph, XtNleftMarker, &n, NULL);
@@ -456,7 +457,7 @@ XtPointer       gp;
 XtPointer       gainp;
 {
     GlobalDataPtr   g = (GlobalDataPtr) gp;
-    int             gain = (int) gainp;
+    intptr_t        gain = (intptr_t) gainp;
     AuDeviceAttributes da;
 
     if (!AuDeviceChangableMask(AuServerDevice(g->aud,
@@ -1843,7 +1844,7 @@ XtPointer       gp;
 XtPointer       valuep;
 {
     GlobalDataPtr   g = (GlobalDataPtr) gp;
-    int             value = (int) valuep;
+    intptr_t        value = (intptr_t) valuep;
     AuElementParameters *parms;
     ElementListPtr  p = ElementList;
     int             i = 0;
