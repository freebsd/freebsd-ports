--- parse.c.orig	Fri Feb 24 05:25:00 2006
+++ parse.c	Fri Mar  3 02:04:47 2006
@@ -834,6 +834,7 @@
 cmp_priorities(PNode *x, PNode *y) {
   StackPNode psx, psy;
   StackInt isx, isy;
+  int r;
 
   stack_clear(&psx); stack_clear(&psy); stack_clear(&isx); stack_clear(&isy);
   get_exp_one(x, &psx, &isx);
@@ -841,7 +842,7 @@
   get_unshared_priorities(&psx, &psy, &isx, &isy);
   intsort(isx.start, stack_depth(&isx));
   intsort(isy.start, stack_depth(&isy));
-  int r = compare_priorities(isx.start, stack_depth(&isx), 
+  r = compare_priorities(isx.start, stack_depth(&isx), 
 		     isy.start, stack_depth(&isy));
   stack_free(&psx); stack_free(&psy); stack_free(&isx); stack_free(&isy);
   return r;
@@ -949,12 +950,12 @@
 static int
 cmp_greedyness(PNode *x, PNode *y) {
   VecPNode pvx, pvy;
+  int ix = 0, iy = 0;
   vec_clear(&pvx); vec_clear(&pvy); 
   get_unshared_pnodes(x, y, &pvx, &pvy);
   set_to_vec(&pvx); set_to_vec(&pvy);
   qsort(pvx.v, pvx.n, sizeof(PNode *), greedycmp);
   qsort(pvy.v, pvy.n, sizeof(PNode *), greedycmp);
-  int ix = 0, iy = 0;
   while (1) {
     if (pvx.n <= ix || pvy.n <= iy)
       return 0;
@@ -1202,8 +1203,8 @@
 static void
 set_add_znode_hash(VecZNode *v, ZNode *z) {
   VecZNode vv;
-  vec_clear(&vv);
   int i, j, n = v->n;
+  vec_clear(&vv);
   if (n) {
     uint h = ((uintptr_t)z->pn) % n;
     for (i = h, j = 0; 
@@ -1237,8 +1238,8 @@
 static void
 set_add_znode(VecZNode *v, ZNode *z) {
   VecZNode vv;
-  vec_clear(&vv);
   int i, n = v->n;
+  vec_clear(&vv);
   if (n < INTEGRAL_VEC_SIZE) {
     vec_add(v, z);
     return;
