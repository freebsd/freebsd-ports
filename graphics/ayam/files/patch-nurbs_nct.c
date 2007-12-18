--- nurbs/nct.c.orig	2007-12-17 18:37:00.000000000 +0100
+++ nurbs/nct.c	2007-12-17 18:38:29.000000000 +0100
@@ -817,7 +817,7 @@
 
   if(argc > 1)
     {
-      Tcl_SplitList(interp, argv[1], &aknotc, &aknotv);
+      Tcl_SplitList(interp, argv[1], &aknotc, (const char ***)&aknotv);
 
       if(!(X = calloc(aknotc, sizeof(double))))
 	{
