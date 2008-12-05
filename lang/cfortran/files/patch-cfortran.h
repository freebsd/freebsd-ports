--- cfortran.h.orig	2008-12-05 13:51:41.000000000 +0100
+++ cfortran.h	2008-12-05 13:55:07.000000000 +0100
@@ -129,7 +129,8 @@
 /* Split #if into 2 because some HP-UX can't handle long #if */
 #if !(defined(NAGf90Fortran)||defined(f2cFortran)||defined(hpuxFortran)||defined(apolloFortran)||defined(sunFortran)||defined(IBMR2Fortran)||defined(CRAYFortran))
 #if !(defined(mipsFortran)||defined(DECFortran)||defined(vmsFortran)||defined(CONVEXFortran)||defined(PowerStationFortran)||defined(AbsoftUNIXFortran)||defined(AbsoftProFortran)||defined(SXFortran))
-/* If your compiler barfs on ' #error', replace # with the trigraph for #     */
+#define f2cFortran
+/* If your compiler barfs on ' #error', replace # with the trigraph for #
  #error "cfortran.h:  Can't find your environment among:\
     - MIPS cc and f77 2.0. (e.g. Silicon Graphics, DECstations, ...)     \
     - IBM AIX XL C and FORTRAN Compiler/6000 Version 01.01.0000.0000     \
@@ -152,7 +153,7 @@
     - Absoft UNIX F77: Use #define AbsoftUNIXFortran or cc -DAbsoftUNIXFortran \
     - Absoft Pro Fortran: Use #define AbsoftProFortran \
     - Portland Group Fortran: Use #define pgiFortran"
-/* Compiler must throw us out at this point! */
+  Compiler must throw us out at this point! */
 #endif
 #endif
 
