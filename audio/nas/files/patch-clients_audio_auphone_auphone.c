--- clients/audio/auphone/auphone.c	Sat Jul 20 21:13:30 2002
+++ clients/audio/auphone/auphone.c	Mon Oct 10 11:32:46 2005
@@ -28,4 +28,5 @@
  */
 
+#include <inttypes.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -218,7 +219,7 @@
                *busyData;
 
-static int
+static intptr_t
 fatalError(message, arg)
-char           *message,
+const char     *message,
                *arg;
 {
@@ -226,5 +227,4 @@
     fprintf(stderr, "\n");
     exit(1);
-    return 0;
 }
 
@@ -240,5 +240,5 @@
 	g->bufSize = e->num_bytes;
 
-	if (!(g->buf = (char *) malloc(g->bufSize)))
+	if (!(g->buf = malloc(g->bufSize)))
 	    fatalError("malloc failed");
     }
@@ -252,6 +252,6 @@
 	g->bufSize += e->num_bytes;
 
-	if (!(g->buf = (char *) realloc(g->buf, g->bufSize)))
-	    fatalError("malloc failed");
+	if (!(g->buf = realloc(g->buf, g->bufSize)))
+	    fatalError("realloc failed");
     }
 
@@ -918,5 +918,5 @@
 {
     GlobalDataPtr   g = (GlobalDataPtr)gp;
-    int             vol = (int)volp;
+    intptr_t        vol = (intptr_t)volp;
     AuElementParameters parms;
 
@@ -940,5 +940,5 @@
 {
     GlobalDataPtr   g = (GlobalDataPtr)gp;
-    int             gain = (int)gainp;
+    intptr_t        gain = (intptr_t)gainp;
     ServerPtr       l = &g->local;
     AuDeviceAttributes da;
@@ -1129,5 +1129,5 @@
 	    fatalError("Can't open ring %s", ring);
 
-	if (!(chunk = (char *) malloc(CHUNK_SIZE)))
+	if (!(chunk = malloc(CHUNK_SIZE)))
 	    fatalError("malloc failed");
 
