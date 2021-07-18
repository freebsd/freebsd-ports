--- vector/v.hull/chull.c.orig	2021-07-04 15:27:24 UTC
+++ vector/v.hull/chull.c
@@ -22,6 +22,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
+#include <stdbool.h>
 
 #include <grass/gis.h>
 #include <grass/vector.h>
@@ -29,10 +30,6 @@
 
 #include "globals.h"
 
-/*Define Boolean type */
-typedef enum
-{ BFALSE, BTRUE } bool;
-
 /* Define vertex indices. */
 #define X   0
 #define Y   1
@@ -76,10 +73,10 @@ struct tFaceStructure
 };
 
 /* Define flags */
-#define ONHULL   	BTRUE
-#define REMOVED  	BTRUE
-#define VISIBLE  	BTRUE
-#define PROCESSED	BTRUE
+#define ONHULL   	true
+#define REMOVED  	true
+#define VISIBLE  	true
+#define PROCESSED	true
 
 /* Global variable definitions */
 tVertex vertices = NULL;
@@ -436,7 +433,7 @@ bool AddOne(tVertex p)
     tFace f;
     tEdge e, temp;
     long int vol;
-    bool vis = BFALSE;
+    bool vis = false;
 
 
     /* Mark faces visible from p. */
@@ -446,7 +443,7 @@ bool AddOne(tVertex p)
 
 	if (vol < 0) {
 	    f->visible = VISIBLE;
-	    vis = BTRUE;
+	    vis = true;
 	}
 	f = f->next;
     } while (f != faces);
@@ -454,7 +451,7 @@ bool AddOne(tVertex p)
     /* If no faces are visible from p, then p is inside the hull. */
     if (!vis) {
 	p->onhull = !ONHULL;
-	return BFALSE;
+	return false;
     }
 
     /* Mark edges in interior of visible region for deletion.
@@ -470,7 +467,7 @@ bool AddOne(tVertex p)
 	    e->newface = MakeConeFace(e, p);
 	e = temp;
     } while (e != edges);
-    return BTRUE;
+    return true;
 }
 
 /*---------------------------------------------------------------------
