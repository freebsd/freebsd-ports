--- Robot/subroutines.f~	Wed May  4 00:14:51 2005
+++ Robot/subroutines.f	Wed Jan 17 17:55:55 2007
@@ -760,7 +760,7 @@
 	if(nharm .lt. 0)then
 		write(tstring, *)hharm, ' harmonics specified'
 		call xtext(tstring)
-		call xtext('Doesn\'t make sense so doing no summing')
+		call xtext('Does not make sense so doing no summing')
 		return
 	end if
 
