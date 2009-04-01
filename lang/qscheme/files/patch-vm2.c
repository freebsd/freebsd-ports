--- vm2.c.orig	2000-06-01 17:47:00.000000000 +0300
+++ vm2.c	2009-03-03 17:12:14.000000000 +0200
@@ -185,8 +185,8 @@
 
 #define RETURN(value) { TOS=(value);  NEXT; }
 
-#define Prim(name,str,nargs)	l_##name##: /* str */
-#define PrimVarargs(name,str)	l_##name##: /* str */
+#define Prim(name,str,nargs)	l_##name: /* str */
+#define PrimVarargs(name,str)	l_##name: /* str */
 
 
 /****************************************************************
@@ -392,7 +392,8 @@
   ef = (SCM_EnvFrame*)sp;											\
   /* alloc space on stack for an env object and fill it's frame and \
      next fields */													\
-  ((void*)sp) -= sizeof(Sobject);									\
+  /*((void*)sp) -= sizeof(Sobject);*/									\
+  sp = ((void*)sp) - sizeof(Sobject);									\
   SCM_ENV_FRAME((SOBJ)sp) = ef;										\
   SCM_ENV_NEXT((SOBJ)sp) = nextenv;									\
   env = (SOBJ)sp;													\
