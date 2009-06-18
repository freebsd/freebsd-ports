--- ./perl.c.orig	2009-06-18 03:30:23.290690879 -0400
+++ ./perl.c	2009-06-18 03:30:13.000000000 -0400
@@ -296,7 +296,7 @@
 
   ret = perl_eval_pv(RSTRING(pv)->ptr, Qfalse);
   if (SvTRUE(ERRSV)) {
-    rb_raise(ePerlError, SvPVx(ERRSV, PL_na));
+    rb_raise(ePerlError, SvPVx_nolen(ERRSV));
   }
 
   return perl__Sv2Object(ret);
@@ -352,7 +352,7 @@
   LEAVE;
 
   if (SvTRUE(ERRSV)) {
-    rb_raise(ePerlError, SvPVx(ERRSV, PL_na));
+    rb_raise(ePerlError, SvPVx_nolen(ERRSV));
   }
 
   return ret;
@@ -394,7 +394,7 @@
   LEAVE;
 
   if (SvTRUE(ERRSV)) {
-    rb_raise(ePerlError, SvPVx(ERRSV, PL_na));
+    rb_raise(ePerlError, SvPVx_nolen(ERRSV));
   }
 
   return ret;
@@ -453,7 +453,7 @@
   LEAVE;
 
   if (SvTRUE(ERRSV)) {
-    rb_raise(ePerlError, SvPVx(ERRSV, PL_na));
+    rb_raise(ePerlError, SvPVx_nolen(ERRSV));
   }
 
   return ret;
@@ -490,7 +490,7 @@
   LEAVE;
 
   if (SvTRUE(ERRSV)) {
-    rb_raise(ePerlError, SvPVx(ERRSV, PL_na));
+    rb_raise(ePerlError, SvPVx_nolen(ERRSV));
   }
 
   return ret;
