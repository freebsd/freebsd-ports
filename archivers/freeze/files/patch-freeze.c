--- ./freeze.c.orig	1993-02-24 14:36:55.000000000 +0100
+++ ./freeze.c	2014-02-13 12:43:34.946976981 +0100
@@ -176,7 +176,7 @@
 
 /* From compress.c. Replace .Z --> .F etc */
 
-void 
+int 
 main(argc, argv)
 register int argc;
 char  **argv;
