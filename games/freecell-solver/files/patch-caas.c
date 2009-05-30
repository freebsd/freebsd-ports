--- caas.c.orig	2009-05-18 18:49:56.000000000 +0900
+++ caas.c	2009-05-18 23:10:59.000000000 +0900
@@ -236,7 +236,7 @@
             PValue,
             instance->stacks_judy_array,
             new_state_key->stacks[a],
-            (fcs_stack_len(*new_state_key, a)+1)
+            col_len
         );
         /* TODO : Handle out-of-memory. */
         if (*PValue == 0)
