--- array.c.orig	Sat Oct 16 18:02:07 2004
+++ array.c	Sat Oct 16 18:02:10 2004
@@ -223,12 +223,14 @@
 NewBoxVector (int nvalues, TypePtr type)
 {
     ENTER ();
-    BoxVectorPtr    bv = ALLOCATE (&BoxVectorType, 
-				   sizeof (BoxVector) +
-				   nvalues * sizeof (BoxPtr));
+    BoxVectorPtr    bv;
     int		    i;
-    BoxPtr	    *boxes = BoxVectorBoxes (bv);
-    
+    BoxPtr	    *boxes;
+
+    bv = ALLOCATE (&BoxVectorType, sizeof (BoxVector) +
+		   nvalues * sizeof (BoxPtr));
+    boxes = BoxVectorBoxes (bv);
+
     bv->nvalues = nvalues;
     bv->type = type;
     for (i = 0; i < nvalues; i++)
