--- clients/audio/auphone/auphone.c.orig	2007-06-16 23:03:12.000000000 +0400
+++ clients/audio/auphone/auphone.c	2008-05-14 22:44:05.000000000 +0400
@@ -27,6 +27,7 @@
  * $NCDId: @(#)auphone.c,v 1.10 1996/05/07 20:13:12 greg Exp $
  */
 
+#include <inttypes.h>
 #include <stdio.h>
 #include <stdlib.h>
 
@@ -219,13 +220,12 @@
                *ringoutData,
                *busyData;
 
-static int
+static intptr_t
 fatalError(const char *message, const char *arg)
 {
     fprintf(stderr, message, arg);
     fprintf(stderr, "\n");
     exit(1);
-    return 0;
 }
 
 static void
@@ -237,7 +237,7 @@
     {
 	g->bufSize = e->num_bytes;
 
-	if (!(g->buf = (char *) malloc(g->bufSize)))
+	if (!(g->buf = malloc(g->bufSize)))
 	    fatalError("malloc failed", NULL);
     }
     else
@@ -249,8 +249,8 @@
 
 	g->bufSize += e->num_bytes;
 
-	if (!(g->buf = (char *) realloc(g->buf, g->bufSize)))
-	    fatalError("malloc failed", NULL);
+	if (!(g->buf = realloc(g->buf, g->bufSize)))
+	    fatalError("remalloc failed", NULL);
     }
 
     n = AuReadElement(g->local.aud, e->flow, e->element_num, e->num_bytes,
@@ -871,7 +871,7 @@
 adjustVolume(Widget w, XtPointer gp, XtPointer volp)
 {
     GlobalDataPtr   g = (GlobalDataPtr)gp;
-    int             vol = (int)volp;
+    intptr_t        vol = (intptr_t)volp;
     AuElementParameters parms;
 
     if (!g->local.volFlow)
@@ -890,7 +890,7 @@
 adjustInputGain(Widget w, XtPointer gp, XtPointer gainp)
 {
     GlobalDataPtr   g = (GlobalDataPtr)gp;
-    int             gain = (int)gainp;
+    intptr_t        gain = (intptr_t)gainp;
     ServerPtr       l = &g->local;
     AuDeviceAttributes da;
 
@@ -1065,7 +1065,7 @@
 	if (!(s = SoundOpenFileForReading(ring)))
 	    fatalError("Can't open ring %s", ring);
 
-	if (!(chunk = (char *) malloc(CHUNK_SIZE)))
+	if (!(chunk = malloc(CHUNK_SIZE)))
 	    fatalError("malloc failed", NULL);
 
 	sprintf(buf, "%s %d", RINGIN, volume);
