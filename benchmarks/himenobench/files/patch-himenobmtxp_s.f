--- himenobmtxp_s.f.orig	Mon Aug 16 15:39:44 2004
+++ himenobmtxp_s.f	Mon Aug 16 15:39:54 2004
@@ -39,7 +39,6 @@
 C "use portlib" statement on the next line is for Visual fortran
 C to use UNIX libraries. Please remove it if your system is UNIX.
 C -------------------
-      use portlib
       IMPLICIT REAL*4(a-h,o-z)
 C
       PARAMETER (mimax=513,mjmax=257,mkmax=257)
