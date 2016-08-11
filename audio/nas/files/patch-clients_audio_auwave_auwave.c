--- clients/audio/auwave/auwave.c.orig	2013-10-07 17:05:47 UTC
+++ clients/audio/auwave/auwave.c
@@ -27,6 +27,7 @@
  * $NCDId: @(#)auwave.c,v 1.7 1994/11/01 23:18:30 greg Exp $
  */
 
+#include <inttypes.h>
 #include <stdio.h>
 #include <stdlib.h>
 #ifndef SYSV
@@ -222,7 +223,7 @@ static void
 setVol(Widget w, XtPointer gp, XtPointer valuep)
 {
     GlobalDataPtr   g = (GlobalDataPtr) gp;
-    int             value = (int) valuep;
+    intptr_t        value = (intptr_t) valuep;
 
     AuElementParameters parms;
 
@@ -241,7 +242,7 @@ static void
 setFreq(Widget w, XtPointer gp, XtPointer valuep)
 {
     GlobalDataPtr   g = (GlobalDataPtr) gp;
-    int             value = (int) valuep;
+    intptr_t        value = (intptr_t) valuep;
     AuElementParameters parms;
     char            buf[10];
 
@@ -263,7 +264,7 @@ static void
 setGain(Widget w, XtPointer gp, XtPointer valuep)
 {
     GlobalDataPtr   g = (GlobalDataPtr) gp;
-    int             value = (int) valuep;
+    intptr_t        value = (intptr_t) valuep;
     AuDeviceAttributes da;
 
     AuDeviceGain(&da) = AuFixedPointFromSum(value, 0);
