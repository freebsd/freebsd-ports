--- freeze.c.orig	Thu Aug 30 14:45:31 2001
+++ freeze.c	Thu Aug 30 14:45:37 2001
@@ -176,7 +176,7 @@
 
 /* From compress.c. Replace .Z --> .F etc */
 
-void 
+int 
 main(argc, argv)
 register int argc;
 char  **argv;
