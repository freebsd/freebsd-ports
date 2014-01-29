
$FreeBSD$

--- racket/src/number.c.orig
+++ racket/src/number.c
@@ -1890,6 +1890,9 @@
   return (is_rational(argv[0]) ? scheme_true : scheme_false);
 }
 
+#ifdef MZ_XFORM
+START_XFORM_SKIP;
+#endif
 XFORM_NONGCING static int double_is_integer(double d)
 {
 # ifdef NAN_EQUALS_ANYTHING
@@ -1905,7 +1908,13 @@
 
   return 0;
 }
+#ifdef MZ_XFORM
+END_XFORM_SKIP;
+#endif
 
+#ifdef MZ_XFORM
+START_XFORM_SKIP;
+#endif
 int scheme_is_integer(const Scheme_Object *o)
 {
   if (SCHEME_INTP(o) || SCHEME_BIGNUMP(o))
@@ -1916,6 +1925,9 @@
 
   return 0;
 }
+#ifdef MZ_XFORM
+END_XFORM_SKIP;
+#endif
 
 
 static Scheme_Object *
