$FreeBSD$

--- gcc/c-decl.c.orig	Mon Aug  8 00:42:26 2005
+++ gcc/c-decl.c	Wed Sep  7 02:41:09 2005
@@ -1271,7 +1271,10 @@ diagnose_mismatched_decls (tree newdecl,
       && !(DECL_EXTERNAL (olddecl) && !DECL_EXTERNAL (newdecl))
       /* Don't warn about forward parameter decls.  */
       && !(TREE_CODE (newdecl) == PARM_DECL
-	   && TREE_ASM_WRITTEN (olddecl) && !TREE_ASM_WRITTEN (newdecl)))
+	   && TREE_ASM_WRITTEN (olddecl) && !TREE_ASM_WRITTEN (newdecl))
+      /* Don't warn about a variable definition following a declaration.  */
+      && !(TREE_CODE (newdecl) == VAR_DECL
+	   && DECL_INITIAL (newdecl) && !DECL_INITIAL (olddecl)))
     {
       warning ("%Jredundant redeclaration of '%D'", newdecl, newdecl);
       warned = true;
