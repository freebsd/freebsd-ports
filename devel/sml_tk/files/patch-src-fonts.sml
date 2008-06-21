--- ./src/fonts.sml.orig	Fri Mar 30 23:39:12 2001
+++ src/fonts.sml	Sun Jan 13 11:03:51 2008
@@ -109,8 +109,8 @@
  	    fun read_em si = if TextIO.endOfStream si 
  				 then [] before (TextIO.closeIn si;
  						 TextIO.closeOut so)
-                               else (splitFields
- 				    (TextIO.inputLine si))::(read_em si)
+                               else (splitFields (valOf
+ 				    (TextIO.inputLine si)))::(read_em si)
  	in  read_em si
  	end
  
