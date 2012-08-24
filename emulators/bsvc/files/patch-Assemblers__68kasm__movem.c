--- ./Assemblers/68kasm/movem.c.orig	1998-11-09 04:39:28.000000000 +0100
+++ ./Assemblers/68kasm/movem.c	2012-08-24 12:28:10.639913796 +0200
@@ -62,6 +62,7 @@
 char *evalList();
 
 
+void
 movem(size, label, op, errorPtr)
 int size;
 char *label, *op;
@@ -167,6 +168,7 @@
 }
 
 
+void
 reg(size, label, op, errorPtr)
 int size;
 char *label, *op;
