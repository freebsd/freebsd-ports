Index: func.c
===================================================================
RCS file: /cvs/keithp/nickle/func.c,v
retrieving revision 1.25
retrieving revision 1.26
diff -u -u -r1.25 -r1.26
--- func.c	9 Jul 2004 18:48:35 -0000	1.25
+++ func.c	25 Feb 2005 03:23:06 -0000	1.26
@@ -1,4 +1,4 @@
-/* $Header: /cvs/keithp/nickle/func.c,v 1.25 2004/07/09 18:48:35 keithp Exp $ */
+/* $Header: /cvs/keithp/nickle/func.c,v 1.26 2005/02/25 03:23:06 keithp Exp $ */
 
 /*
  * Copyright © 1988-2004 Keith Packard and Bart Massey.
@@ -99,6 +99,7 @@
     bc->base.args = args;
     bc->base.name = 0;
     bc->base.previous = 0;
+    bc->base.func = 0;
     bc->base.doc = doc ? NewStrString (doc) : Void;
     
     bc->builtin.needsNext = needsNext;
