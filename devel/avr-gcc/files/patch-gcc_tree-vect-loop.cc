--- gcc/tree-vect-loop.cc.orig	2019-11-28 10:47:59 UTC
+++ gcc/tree-vect-loop.cc
@@ -55,6 +55,8 @@ along with GCC; see the file COPYING3.  If not see
 #include "case-cfn-macros.h"
 #include "langhooks.h"
 
+#define vec_step vec_step_
+
 /* Loop Vectorization Pass.
 
    This pass tries to vectorize loops.
