--- ./Assemblers/68kasm/build.c.orig	1998-11-09 04:39:28.000000000 +0100
+++ ./Assemblers/68kasm/build.c	2012-08-24 12:31:42.849913226 +0200
@@ -58,6 +58,7 @@
  *
  ***********************************************************************/
 
+void
 move(mask, size, source, dest, errorPtr)
 int mask, size;
 opDescriptor *source, *dest;
@@ -216,6 +217,7 @@
  ***********************************************************************/
 
 
+void
 immedInst(mask, size, source, dest, errorPtr)
 int mask, size;
 opDescriptor *source, *dest;
