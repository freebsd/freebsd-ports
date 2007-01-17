--- tests/f/test33.f~	Mon Feb 27 20:46:24 2006
+++ tests/f/test33.f	Wed Jan 17 15:00:47 2007
@@ -71,7 +71,7 @@
 	call efnema(fid,maa,MED_CONN,MED_ARETE,MED_SEG2,MED_DESC
      1    ,narr,cret)   
 	if (cret .ne. 0 ) then
-	   print *,'Erreur acces au nombre d''arretes du premier maillage'
+	   print *,'Erreur acces au nombre d arretes du premier maillage'
 	   call efexit(-1)
 	endif      
 
