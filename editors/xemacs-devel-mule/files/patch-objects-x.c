Index: objects-x.c
===================================================================
RCS file: /pack/xemacscvs/XEmacs/xemacs/src/objects-x.c,v
retrieving revision 1.30
retrieving revision 1.31
diff -u -r1.30 -r1.31
--- src/objects-x.c	2005/11/26 18:25:03	1.30
+++ src/objects-x.c	2005/12/20 22:01:52	1.31
@@ -1175,7 +1175,7 @@
   Extbyte **names;
   int count = 0;
   const Extbyte *patternext;
-  Lisp_Object result = Qunbound;
+  Lisp_Object result = Qnil;
   int i;
 
   /* #### with Xft need to handle second stage here -- sjt
