--- gplan.c.orig	2003-11-27 02:37:42.000000000 +0100
+++ gplan.c	2008-02-29 19:00:02.000000000 +0100
@@ -83,12 +83,8 @@
   /* VAX CC rejects "signed char."  */
   char *p;
 #else
-#ifdef __STDC__
-  signed char *p;
-#else
   char *p;
 #endif
-#endif
   double *pl, *pb, *pr;
 #endif
 
@@ -441,12 +437,8 @@
   /* VAX CC rejects "signed char."  */
   char *p;
 #else
-#ifdef __STDC__
-  signed char *p;
-#else
   char *p;
 #endif
-#endif
   long *pl, *pb, *pr;
 #endif
   double su, cu, sv, cv;
@@ -613,12 +605,8 @@
   /* VAX CC rejects "signed char."  */
   char *p;
 #else
-#ifdef __STDC__
-  signed char *p;
-#else
   char *p;
 #endif
-#endif
   long *pl, *pr;
 #endif
   double su, cu, sv, cv;
@@ -764,12 +752,8 @@
   /* VAX CC rejects "signed char."  */
   char *p;
 #else
-#ifdef __STDC__
-  signed char *p;
-#else
   char *p;
 #endif
-#endif
   long *pl;
 #endif
   double su, cu, sv, cv;
