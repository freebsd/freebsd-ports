--- src/gcc/gcc/tree-vect-loop.c.orig	2019-12-02 09:49:15 UTC
+++ src/gcc/gcc/tree-vect-loop.c
@@ -55,6 +55,8 @@ along with GCC; see the file COPYING3.  If not see
 #include "vec-perm-indices.h"
 #include "tree-eh.h"
 
+#define vec_step vec_step_
+
 /* Loop Vectorization Pass.
 
    This pass tries to vectorize loops.
