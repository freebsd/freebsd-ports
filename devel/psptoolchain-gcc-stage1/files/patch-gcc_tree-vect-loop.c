--- gcc/tree-vect-loop.c.orig	2019-11-27 20:05:37 UTC
+++ gcc/tree-vect-loop.c
@@ -56,6 +56,8 @@ along with GCC; see the file COPYING3.  If not see
 #include "tree-vectorizer.h"
 #include "target.h"
 
+#define vec_step vec_step_
+
 /* Loop Vectorization Pass.
 
    This pass tries to vectorize loops.
