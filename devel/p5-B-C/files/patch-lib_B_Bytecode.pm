--- lib/B/Bytecode.pm.orig	2014-08-21 22:13:08 UTC
+++ lib/B/Bytecode.pm
@@ -846,9 +846,12 @@ sub B::OP::bsave_thin {
     if ($] >= 5.019002 and $op->can('folded')) {
       asm "op_folded", $op->folded if $op->folded;
     }
-    if ($] >= 5.021002 and $op->can('lastsib')) {
+    if ($] >= 5.021002 and $[ < 5.021011 and $op->can('lastsib')) {
       asm "op_lastsib", $op->lastsib if $op->lastsib;
     }
+    if ($] >= 5.021011 and $op->can('moresib')) {
+      asm "op_moresib", $op->moresib if $op->moresib;
+    }
   }
 }
 
