$FreeBSD$

--- gcc/c-decl.c.orig	Wed Aug 17 17:21:28 2005
+++ gcc/c-decl.c	Wed Sep  7 02:18:44 2005
@@ -1555,7 +1555,10 @@ diagnose_mismatched_decls (tree newdecl,
       && !(DECL_EXTERNAL (olddecl) && !DECL_EXTERNAL (newdecl))
       /* Don't warn about forward parameter decls.  */
       && !(TREE_CODE (newdecl) == PARM_DECL
-	   && TREE_ASM_WRITTEN (olddecl) && !TREE_ASM_WRITTEN (newdecl)))
+	   && TREE_ASM_WRITTEN (olddecl) && !TREE_ASM_WRITTEN (newdecl))
+      /* Don't warn about a variable definition following a declaration.  */
+      && !(TREE_CODE (newdecl) == VAR_DECL
+	   && DECL_INITIAL (newdecl) && !DECL_INITIAL (olddecl)))
     {
       warning (OPT_Wredundant_decls, "redundant redeclaration of %q+D",
 	       newdecl);
