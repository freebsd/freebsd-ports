--- himenobmtxp_l.f.orig	2016-07-27 14:57:50 UTC
+++ himenobmtxp_l.f
@@ -39,7 +39,6 @@ C -------------------
 C "use portlib" statement on the next line is for Visual fortran
 C to use UNIX libraries. Please remove it if your system is UNIX.
 C -------------------
-      use portlib
       IMPLICIT REAL*4(a-h,o-z)
 C
       PARAMETER (mimax=513,mjmax=257,mkmax=257)
