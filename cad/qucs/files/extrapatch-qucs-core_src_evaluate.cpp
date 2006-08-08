--- qucs-core/src/evaluate.cpp.orig	Sat May 27 11:46:33 2006
+++ qucs-core/src/evaluate.cpp	Tue Aug  8 00:52:02 2006
@@ -113,6 +113,7 @@
 #define _DEFR() constant * res = new constant (TAG_RANGE);
 #define _RETD(var) res->d = (var); return res;
 #define _RETC(var) res->c = new complex (var); return res;
+#define _RETV2() res->v = new vector (); return res;
 #define _RETV(var) res->v = new vector (var); return res;
 #define _RETM(var) res->m = new matrix (var); return res;
 #define _RETMV(var) res->mv = new matvec (var); return res;
@@ -3246,7 +3247,7 @@
   if (n < 1) {
     THROW_MATH_EXCEPTION ("runavg: number n to be averaged over must be "
 			  "larger or equal 1");
-    _RETV ();
+    _RETV2 ();
   }
   _RETV (runavg (rect (x, 0), n));
 }
@@ -3258,7 +3259,7 @@
   if (n < 1) {
     THROW_MATH_EXCEPTION ("runavg: number n to be averaged over must be "
 			  "larger or equal 1");
-    _RETV ();
+    _RETV2 ();
   }
   _RETV (runavg (*x, n));
 }
@@ -3271,7 +3272,7 @@
     THROW_MATH_EXCEPTION ("runavg: number n to be averaged over must be "
 			  "larger or equal 1 and less or equal than the "
 			  "number of vector elements");
-    _RETV ();
+    _RETV2 ();
   }
   _RETV (runavg (*x, n));
 }
@@ -3285,7 +3286,7 @@
   nr_double_t sval = 0.0;
   if (size <= 0) {
     THROW_MATH_EXCEPTION ("kbd: vector length must be greater than zero");
-    _RETV ();
+    _RETV2 ();
   }
   vector v (size);
   for (i = 0; i < size / 2; i++) {
