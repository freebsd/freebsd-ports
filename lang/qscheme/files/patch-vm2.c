--- vm2.c.orig	Wed Oct 27 19:33:03 2004
+++ vm2.c	Wed Oct 27 19:33:16 2004
@@ -185,8 +185,8 @@
 
 #define RETURN(value) { TOS=(value);  NEXT; }
 
-#define Prim(name,str,nargs)	l_##name##: /* str */
-#define PrimVarargs(name,str)	l_##name##: /* str */
+#define Prim(name,str,nargs)	l_##name: /* str */
+#define PrimVarargs(name,str)	l_##name: /* str */
 
 
 /****************************************************************
