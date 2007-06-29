--- examples/util/transform.c.orig	Fri Jun 29 17:19:27 2007
+++ examples/util/transform.c	Fri Jun 29 17:18:15 2007
@@ -47,10 +47,12 @@
 static DtInt transcount=0, arraysize=0;
 
 /* prototypes for static functions */
-transform_matrix (DtMatrix4x4, DtInt, DtReal, DtCompType);
-translate (DtMatrix4x4, int, DtReal, DtCompType);
-scale(DtMatrix4x4, int, DtReal, DtCompType);
-rotate(DtMatrix4x4, int, int, DtReal, DtCompType);
+static transform_matrix (DtMatrix4x4, DtInt, DtReal, DtCompType);
+static translate (DtMatrix4x4, int, DtReal, DtCompType);
+static scale(DtMatrix4x4, int, DtReal, DtCompType);
+static rotate(DtMatrix4x4, int, int, DtReal, DtCompType);
+static load_identity(DtMatrix4x4);
+static load_matrix(DtMatrix4x4, DtMatrix4x4);
 
 
 /*
