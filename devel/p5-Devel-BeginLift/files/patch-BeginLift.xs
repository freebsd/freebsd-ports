--- BeginLift.xs.orig	2010-05-11 06:01:00 UTC
+++ BeginLift.xs
@@ -8,10 +8,6 @@
 
 #include "hook_op_check_entersubforcv.h"
 
-/* lifted from op.c */
-
-#define LINKLIST(o) ((o)->op_next ? (o)->op_next : linklist((OP*)o))
-
 #ifndef linklist
 # define linklist(o) THX_linklist(aTHX_ o)
 STATIC OP *THX_linklist(pTHX_ OP *o) {
@@ -24,9 +20,9 @@ STATIC OP *THX_linklist(pTHX_ OP *o) {
     o->op_next = LINKLIST(first);
     kid = first;
     for (;;) {
-      if (kid->op_sibling) {
-   kid->op_next = LINKLIST(kid->op_sibling);
-   kid = kid->op_sibling;
+      if (OpHAS_SIBLING(kid)) {
+   kid->op_next = LINKLIST(OpSIBLING(kid));
+   kid = OpSIBLING(kid);
       } else {
    kid->op_next = o;
    break;
@@ -61,7 +57,7 @@ STATIC OP *lift_cb(pTHX_ OP *o, CV *cv, 
     PUSHMARK(SP); /* push a mark for the arguments */
 
     /* push an arg for every sibling op */
-    for ( arg = curop->op_sibling; arg->op_sibling; arg = arg->op_sibling ) {
+    for ( arg = OpSIBLING(arg); OpHAS_SIBLING(arg); arg = OpSIBLING(arg) ) {
       XPUSHs(sv_bless(newRV_inc(newSViv(PTR2IV(arg))), gv_stashpv("B::LISTOP", 0)));
     }
 
@@ -96,7 +92,7 @@ STATIC OP *lift_cb(pTHX_ OP *o, CV *cv, 
 
     if (SvROK(sv) && sv_derived_from(sv, "B::OP")) {
       OP *new = INT2PTR(OP *,SvIV((SV *)SvRV(sv)));
-      new->op_sibling = NULL;
+      new->op_sibparent = NULL;
 
       /* FIXME this is bullshit */
       if ( (PL_opargs[new->op_type] & OA_CLASS_MASK) != OA_SVOP ) {
