
$FreeBSD$

--- openend.f.orig	Fri Apr 18 13:31:51 2003
+++ openend.f	Mon Jul 21 13:36:11 2003
@@ -29,11 +29,11 @@
 c
 c     standard Fortran 90, unavailable in some Fortran 77 compilers
 c
-      open (unit=iunit,file=name,status='old',position='append')
+c     open (unit=iunit,file=name,status='old',position='append')
 c
 c     common extension supported by many Fortran 77 compilers
 c
-c     open (unit=iunit,file=name,status='old',access='append')
+      open (unit=iunit,file=name,status='old',access='append')
 c
 c     some Fortran 77 compilers open files for append by default
 c
