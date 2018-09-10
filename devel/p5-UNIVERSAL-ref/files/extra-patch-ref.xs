Patch for Perl 0.25 and newer, where op_sibling has been replaced with
op_sibparent which points to a sibling if the op has one and its parent
otherwise.  See <https://rt.cpan.org/Public/Bug/Display.html?id=118008>.

--- ref.xs.orig	2011-01-23 19:17:15 UTC
+++ ref.xs
@@ -89,9 +89,9 @@ void universal_ref_fixupop( OP* o ) {
     universal_ref_fixupop(cUNOPx(o)->op_first);
   }
 
-  if ( o->op_sibling ) {
-    UNIVERSAL_REF_DEBUG(printf("# ->sibling=%x\n",o->op_sibling));
-    universal_ref_fixupop(o->op_sibling);
+  if ( OpHAS_SIBLING(o) ) {
+    UNIVERSAL_REF_DEBUG(printf("# ->sibling=%x\n",OpSIBLING(o)));
+    universal_ref_fixupop(OpSIBLING(o));
   }
 }
 
