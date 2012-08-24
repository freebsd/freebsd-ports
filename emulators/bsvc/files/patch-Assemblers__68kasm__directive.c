--- ./Assemblers/68kasm/directive.c.orig	1998-11-09 04:39:28.000000000 +0100
+++ ./Assemblers/68kasm/directive.c	2012-08-24 12:30:34.710913465 +0200
@@ -53,6 +53,7 @@
  *
  ***********************************************************************/
 
+void
 org(size, label, op, errorPtr)
 int size;
 char *label, *op;
@@ -115,6 +116,7 @@
  *
  ***********************************************************************/
 
+void
 equ(size, label, op, errorPtr)
 int size;
 char *label, *op;
@@ -157,6 +159,7 @@
  *
  ***********************************************************************/
 
+void
 set(size, label, op, errorPtr)
 int size;
 char *label, *op;
@@ -210,6 +213,7 @@
  *
  ***********************************************************************/
 
+void
 dc(size, label, op, errorPtr)
 int size;
 char *label, *op;
@@ -319,6 +323,7 @@
  *
  ***********************************************************************/
 
+void
 dcb(size, label, op, errorPtr)
 int size;
 char *label, *op;
@@ -385,6 +390,7 @@
  *
  ***********************************************************************/
 
+void
 ds(size, label, op, errorPtr)
 int size;
 char *label, *op;
