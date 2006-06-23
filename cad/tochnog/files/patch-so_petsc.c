--- so_petsc.c.orig	Wed Jun 21 00:31:58 2006
+++ so_petsc.c	Wed Jun 21 00:33:30 2006
@@ -21,14 +21,14 @@
 
 #if PETSC_USE 
 
-/* before version 2.2.29 of petsc use these two lines */
+/* before version 2.2.29 of petsc use these two lines
 #include "sles.h"
 #include "mg.h"    
+*/
 
-/* version 2.2.29 and further of petsc use these two lines
+/* version 2.2.29 and further of petsc use these two lines */
 #include "petscsles.h"
 #include "petscmg.h"
-*/
 
 extern double *solve_solution;
 
