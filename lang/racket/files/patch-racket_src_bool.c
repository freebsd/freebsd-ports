--- racket/src/bool.c.orig
+++ racket/src/bool.c
@@ -203,6 +203,9 @@
 }
 
 #ifdef MZ_LONG_DOUBLE
+#ifdef MZ_XFORM
+START_XFORM_SKIP;
+#endif
 XFORM_NONGCING static MZ_INLINE int mz_long_double_eqv(long_double a, long_double b)
 {
 # ifndef NAN_EQUALS_ANYTHING
@@ -238,6 +241,13 @@
   return 1;
 # endif
 }
+#ifdef MZ_XFORM
+END_XFORM_SKIP;
+#endif
+#endif
+
+#ifdef MZ_XFORM
+START_XFORM_SKIP;
 #endif
 XFORM_NONGCING static MZ_INLINE int double_eqv(double a, double b)
 {
@@ -274,7 +284,13 @@
   return 1;
 # endif
 }
+#ifdef MZ_XFORM
+END_XFORM_SKIP;
+#endif
 
+#ifdef MZ_XFORM
+START_XFORM_SKIP;
+#endif
 XFORM_NONGCING static int is_eqv(Scheme_Object *obj1, Scheme_Object *obj2)
 {
   Scheme_Type t1, t2;
@@ -323,12 +339,24 @@
     }
   }
 }
+#ifdef MZ_XFORM
+END_XFORM_SKIP;
+#endif
 
+#ifdef MZ_XFORM
+START_XFORM_SKIP;
+#endif
 int scheme_eqv (Scheme_Object *obj1, Scheme_Object *obj2)
 {
   return (is_eqv(obj1, obj2) > 0);
 }
+#ifdef MZ_XFORM
+END_XFORM_SKIP;
+#endif
 
+#ifdef MZ_XFORM
+START_XFORM_SKIP;
+#endif
 XFORM_NONGCING int is_fast_equal (Scheme_Object *obj1, Scheme_Object *obj2, int for_chaperone)
 {
   Scheme_Type t1, t2;
@@ -414,6 +442,9 @@
 
  return -1;
 }
+#ifdef MZ_XFORM
+END_XFORM_SKIP;
+#endif
 
 int is_slow_equal (Scheme_Object *obj1, Scheme_Object *obj2)
 {
