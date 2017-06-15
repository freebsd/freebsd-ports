From 712aa6bdaac2d717f08dfcc7481a3aa45b815cb8 Mon Sep 17 00:00:00 2001
From: Dan Collins <dcollinsn@gmail.com>
Date: Tue, 7 Jun 2016 12:43:16 -0400
Subject: [PATCH 1/2] The Perl core, since 586d4abb8, has had a build mode
 called PERL_OP_PARENT, which causes the last sibling in a sibling chain to
 use op_sibling to point to the parent, rather than being null. Under this
 build mode, op_sibling is now called op_sibparent. This causes errors of the
 type:
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit

error: ‘OP {aka const struct op}’ has no member named ‘op_sibling’; did
you mean ‘op_sibparent’?

The name of the field was changed to force programs using op_sibling to
revisit their code in light of this change - now, the last sibling in
a chain will have a non-NULL op_sibparent, and the caller must use
op_moresib to know whether the pointer is to another sibling or to
the parent.

This breakage is now visible in bleadperl, since PERL_OP_PARENT was
made default, and will be default in 5.26.0.

op.h provides a macro, OpSIBLING(o), which behaves correctly, checking
op->moresib under PERL_OP_PARENT, and returning either op_sibparent or
NULL. This patch replaces op_sibling with use that macro.
--- Cover.xs.orig	2016-04-24 14:42:56 UTC
+++ Cover.xs
@@ -126,6 +126,14 @@ extern "C" {
 }
 #endif
 
+/* op->op_sibling is deprecated on new perls, but the OpSIBLING macro doesn't
+   exist on older perls. We don't need to check for PERL_OP_PARENT here
+   because if PERL_OP_PARENT was set, and we needed to check op_moresib,
+   we would already have this macro. */
+#ifndef OpSIBLING
+#define OpSIBLING(o) (0 + (o)->op_sibling)
+#endif
+
 static double get_elapsed() {
 #ifdef WIN32
     dTHX;
@@ -614,9 +622,9 @@ static OP *find_skipped_conditional(pTHX
         return NULL;
 
     /* Get to the end of the "a || b || c" block */
-    OP *right = cLOGOP->op_first->op_sibling;
-    while (right && cLOGOPx(right)->op_sibling)
-        right = cLOGOPx(right)->op_sibling;
+    OP *right = OpSIBLING(cLOGOP->op_first);
+    while (right && OpSIBLING(cLOGOPx(right)))
+        right = OpSIBLING(cLOGOPx(right));
 
     if (!right)
         return NULL;
@@ -784,7 +792,7 @@ static void cover_logop(pTHX) {
             (PL_op->op_type == OP_XOR)) {
             /* no short circuit */
 
-            OP *right = cLOGOP->op_first->op_sibling;
+            OP *right = OpSIBLING(cLOGOP->op_first);
 
             NDEB(op_dump(right));
 
@@ -874,7 +882,7 @@ static void cover_logop(pTHX) {
         } else {
             /* short circuit */
 #if PERL_VERSION > 14
-            OP *up = cLOGOP->op_first->op_sibling->op_next;
+            OP *up = OpSIBLING(cLOGOP->op_first)->op_next;
 #if PERL_VERSION > 18
             OP *skipped;
 #endif
@@ -887,7 +895,7 @@ static void cover_logop(pTHX) {
                 add_conditional(aTHX_ up, 3);
                 if (up->op_next == PL_op->op_next)
                     break;
-                up = cLOGOPx(up)->op_first->op_sibling->op_next;
+                up = OpSIBLING(cLOGOPx(up)->op_first)->op_next;
             }
 #endif
             add_conditional(aTHX_ PL_op, 3);
