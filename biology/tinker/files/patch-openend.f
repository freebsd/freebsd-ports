--- openend.f.orig	Tue Dec 18 12:28:54 2001
+++ openend.f	Sat Jul 19 12:30:57 2003
@@ -33,7 +33,7 @@
 c
 c     common extension supported by many Fortran 77 compilers
 c
-c     open (unit=iunit,file=name,status='old',access='append')
+      open (unit=iunit,file=name,status='old',access='append')
 c
 c     some Fortran 77 compilers open files for append by default
 c
