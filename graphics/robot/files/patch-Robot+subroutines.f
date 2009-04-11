--- Robot/subroutines.f.orig	2005-05-03 17:14:51.000000000 +0200
+++ Robot/subroutines.f	2009-04-11 21:54:31.000000000 +0200
@@ -51,13 +51,15 @@
 	subroutine setchars()
 	include 'typecom'
 	include 'charcom'
+        CHARACTER :: tab
+        tab = '\t'
 
         ispace = ichar(' ')        
         ibang = ichar('!')        
         ihash = ichar('#')        
 c        itab = ichar('	') 
 c some versions of g77 get this wrong so use different coding
-	itab = ichar('\t')	       
+	itab = ichar(tab)	       
         ilb = ichar('(')        
         irb = ichar(')')        
         ilab = ichar('<')        
@@ -699,7 +701,7 @@
 	integer npts, ntime
                    
       if(npts .le. 2)then
-         write(tstring,'(a, i, a)')
+         write(tstring,'(a, i5, a)')
      +       '***There are only ',NPTS,' points in the data set***'
 	call totext(tstring)
         call xtext('I will not smooth that few data points')
@@ -760,7 +762,7 @@
 	if(nharm .lt. 0)then
 		write(tstring, *)hharm, ' harmonics specified'
 		call xtext(tstring)
-		call xtext('Doesn\'t make sense so doing no summing')
+		call xtext('Does not make sense so doing no summing')
 		return
 	end if
 
