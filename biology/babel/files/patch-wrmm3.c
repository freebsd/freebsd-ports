
$FreeBSD$

--- wrmm3.c.orig	Tue Jan 21 09:53:02 1997
+++ wrmm3.c	Wed Sep  4 16:00:23 2002
@@ -33,14 +33,17 @@
   int METHOD; /* 0 no cojugated pi system, 1 if conjugated pi system */
   int N; /* #of atoms */
   int IPRINT; /* Controls amount of printout */
+  int MDERIV; /* Optimization termination; 0 for geometry, 1 for energy */
   int NSTR; /* Restricted motion data  */
   int INIT; /* Minimize energy  */
   int NCONST; /* Read in new constants ? */
   double TMAX; /* Max time */
 
+  int KFIXTYP; /* Atom type check; 0 for yes, 1 for no */
   int NCON; /* Number of connected atoms */
   int NATTACH; /*Number of attached atoms */
-  double DEL; /* Termianation of geometry optimization */
+  double DEL; /* Termination of geometry optimization, convergence limit */
+  int ISPEED; /* Speed up minimization of crude structures, 0 is no, 1 is yes */
   int NSYMM;/* Number of symmetry matrices */
   int NX; /* Number of coordiante calcualtions or replacement cards */
   int NROT; /* Reorient */
@@ -62,17 +65,20 @@
   strcpy(ID,OutfileName);
 
 /*------ CARD 1 -------*/
-  METHOD = 1;
+  METHOD = 0;
   N = Atoms;
   IPRINT = 3;
   if (isdigit(OutputKeywords[0]))
     IPRINT = atoi(OutputKeywords);
+  MDERIV = 1;
   NSTR = 0;
   INIT = 0;
-  NCONST = 0;
+  NCONST = 1;
   TMAX = 999.0;
 /*------ CARD 2 -------*/
+  KFIXTYP = 0;
   DEL = 0.00008;
+  ISPEED = 0;
   NCON = connections;
   NATTACH = attachments;
   NSYMM = 0;
@@ -86,22 +92,23 @@
   NDRIVE = 0;
   
 
-  fprintf(file1,"%-60s%d%4d %d  %d %d  %d%-5.0f\n",
+  fprintf(file1,"%-60s%1d%4d%2d%1d%2d%2d%3d%5.0f\n",
 	  ID,
 	  METHOD,
 	  N,
 	  IPRINT,
+	  MDERIV,
 	  NSTR,
 	  INIT,
 	  NCONST,
 	  TMAX);
 
-  fprintf(file1,"%1d%4d%5s%4.5f%8s%5d%5d%5d%5d%5d%5d%5d%5d%10d%5d\n",
-	  0,
+  fprintf(file1,"%1d%4d%5s%10.7f%5d%5d%5d%5d%5d%5d%5d%5d%5d%5s%5d%5d\n",
+	  KFIXTYP,
 	  NCON,
 	  "",
 	  DEL,
-	  "",
+	  ISPEED,
 	  NATTACH,
 	  NSYMM,
 	  NX,
@@ -110,6 +117,7 @@
 	  NDC,
 	  NCALC,
 	  HFORM,
+	  "",
 	  MVDW,
 	  NDRIVE);
 
@@ -145,7 +153,7 @@
     get_output_type(i,"MM2",Type(i),temp_type,all_caps);
     type_name = atoi(temp_type);
     type_name = update_mm2_types(mol,i,type_name);
-    fprintf(file1,"  %8.5f  %8.5f  %8.5f%5d(%3d)\n",
+    fprintf(file1,"%10.5f%10.5f%10.5f%5d(%3d)\n",
 	    X(i),
 	    Y(i),
 	    Z(i),
