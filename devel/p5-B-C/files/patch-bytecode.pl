--- bytecode.pl.orig	2014-08-21 22:13:08 UTC
+++ bytecode.pl
@@ -1044,4 +1044,5 @@ __END__
 165 18	op_savefree	PL_op->op_savefree		U8
 166 18	op_static	PL_op->op_static		U8
 167 19.003 op_folded	PL_op->op_folded		U8
-168 21.002 op_lastsib	PL_op->op_lastsib		U8
+168 21.002-21.010 op_lastsib	PL_op->op_lastsib		U8
+169 21.011 op_moresib	PL_op->op_moresib		U8
