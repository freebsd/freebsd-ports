--- ext/ming/mingc/swffiltermatrix.c.orig	2011-08-08 14:05:19.000000000 +0000
+++ ext/ming/mingc/swffiltermatrix.c	2011-08-08 14:05:50.000000000 +0000
@@ -43,9 +43,9 @@
   struct RSWFFilterMatrix *fm = ALLOC(struct RSWFFilterMatrix);
   int i;
 
-  int size = RARRAY(vals)->len;
+  int size = RARRAY_LEN(vals);
   float *tab = (float *)malloc(cols*rows*sizeof(float));
-  VALUE *ptr = RARRAY(vals)->ptr;
+  VALUE *ptr = RARRAY_PTR(vals);
 
   for (i=0;i<size;i++,ptr++) {
   
