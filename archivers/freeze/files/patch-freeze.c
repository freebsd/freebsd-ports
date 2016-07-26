--- freeze.c.orig	1993-02-24 13:36:55 UTC
+++ freeze.c
@@ -176,7 +176,7 @@ void    writeerr(), copystat(), version(
 
 /* From compress.c. Replace .Z --> .F etc */
 
-void 
+int 
 main(argc, argv)
 register int argc;
 char  **argv;
