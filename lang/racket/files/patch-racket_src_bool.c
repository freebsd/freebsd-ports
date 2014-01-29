
$FreeBSD$

--- racket/src/bool.c.orig
+++ racket/src/bool.c
@@ -198,6 +198,9 @@
 }
 
 #ifdef MZ_LONG_DOUBLE
+#ifdef MZ_XFORM
+START_XFORM_SKIP;
+#endif
 XFORM_NONGCING static MZ_INLINE int mz_long_double_eqv(long_double a, long_double b)
 {
 # ifndef NAN_EQUALS_ANYTHING
@@ -233,6 +236,13 @@
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
@@ -269,7 +279,13 @@
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
@@ -317,6 +333,9 @@
 {
   return (is_eqv(obj1, obj2) > 0);
 }
+#ifdef MZ_XFORM
+END_XFORM_SKIP;
+#endif
 
 int scheme_equal (Scheme_Object *obj1, Scheme_Object *obj2)
 {
