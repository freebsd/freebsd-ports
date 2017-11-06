Fix build with clang

asm.c:1343:21: error: function definition is not allowed here
        SOBJ prim(char *x) {
                           ^
--- asm.c.orig	2017-06-24 19:10:34 UTC
+++ asm.c
@@ -1334,16 +1334,17 @@ static SOBJ scm_compile_quote(SOBJ icode, SOBJ argl, S
   return(icode);
 }
 
+static SOBJ prim(char *x) {
+  int dummy;
+  return(SCM_SYM_VALUE(lookup_atom(scm_mkatom(x),NULL,&dummy,FALSE)));
+}
+
 /*-- KKK: should try to compile parial constant list */
 SOBJ backquotify(SOBJ ic, SOBJ l, SOBJ env, int level)
 {
   static SOBJ sym_cons, sym_append, sym_list2, sym_list2vec;
 
   if (sym_cons == NULL) {
-	SOBJ prim(char *x) {
-	  int dummy;
-	  return(SCM_SYM_VALUE(lookup_atom(scm_mkatom(x),NULL,&dummy,FALSE)));
-	}
 	sym_cons   = prim("cons");
 	sym_list2  = prim("list2");
 	sym_append = prim("qq-append2");
