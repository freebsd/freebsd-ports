--- get_fname.F90.orig	Mon Dec 11 10:38:21 2006
+++ get_fname.F90	Mon Dec 11 10:38:42 2006
@@ -5,6 +5,7 @@
   use dfport
 #endif
 
+  external gmtime_r
   character hiscall*12,fname*24,tag*7
   integer ntime
   integer trperiod
@@ -13,7 +14,7 @@
   n1=ntime
   n2=(n1+2)/trperiod
   n3=n2*trperiod
-  call gmtime(n3,it)
+  call gmtime_r(n3,it)
   it(5)=it(5)+1
   it(6)=mod(it(6),100)
   write(fname,1000) (it(j),j=6,1,-1)
