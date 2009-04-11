--- Robot/subroutines3.f.orig	2009-04-11 21:56:19.000000000 +0200
+++ Robot/subroutines3.f	2009-04-11 21:56:43.000000000 +0200
@@ -1608,7 +1608,7 @@
 	end if
       return
 C ERROR MESSAGES
-992   write(tstring,'(a, i)')'ERROR: THERE IS TOO MUCH DATA IN UNIT', IFIL
+992   write(tstring,'(a, i5)')'ERROR: THERE IS TOO MUCH DATA IN UNIT', IFIL
 	call totext(tstring)
       write(tstring,*)'A MAXIMUM OF',MSIZ,' POINTS IS ALLOWED'
 	call totext(tstring)
