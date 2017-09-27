--- wspr2.f90.orig	2017-09-27 23:05:56 UTC
+++ wspr2.f90
@@ -40,7 +40,7 @@ subroutine wspr2
   include 'acom2.f90'
   character dectxt*80,logfile*80
   integer nt(9)
-  integer iclock(12)
+  integer iclock(36)
   integer ib(15)
   common/patience/npatience
   data nrxnormal/0/,ireset/1/
