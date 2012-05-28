--- ccomp/runtime/GCATS/gcats1_misc.dats.orig	2012-05-23 14:32:51.606718510 +0800
+++ ccomp/runtime/GCATS/gcats1_misc.dats	2012-05-23 14:33:22.846718098 +0800
@@ -55,6 +55,7 @@
 //
 // dir=1/-1 : upward/downward
 //
+static int gc_stack_dir_get_inner (int *some_ptr) __attribute__((noinline));
 static
 int gc_stack_dir_get_inner (int *some_ptr) {
   int some_int ;
