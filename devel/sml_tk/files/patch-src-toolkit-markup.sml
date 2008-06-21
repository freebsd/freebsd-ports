--- ./src/toolkit/markup.sml.orig	Fri Mar 30 23:39:46 2001
+++ src/toolkit/markup.sml	Sun Jan 13 11:03:51 2008
@@ -199,7 +199,7 @@
 		   rest
 	   end
  
-       fun parse t = parseMain (all t) 0
+       fun parse t = parseMain (full t) 0
 	   
    end
 
@@ -239,7 +239,7 @@
 	          (case Tags.escape e of
 		      SOME esc =>
 			  let val estr= Tags.textForEsc esc
-			      val nuc = addpos c (Substring.all estr)
+			      val nuc = addpos c (Substring.full estr)
 			      val ean = Tags.annotationForEsc esc (Mark c,
 								   Mark nuc)
 			  in  (oe, nuc, s^estr,
@@ -255,7 +255,7 @@
 			           (Tags.warning ("Unknown escape sequence '"^e^
 						"' (left untouched).");
 				    "&"^e^";")
-			   in (oe, addpos c (Substring.all estr), s^estr, al)
+			   in (oe, addpos c (Substring.full estr), s^estr, al)
 			   end)
       | consEl wid (elemStart els, (oe, c, s, al)) =
 	          ((els, c):: oe, c, s, al)
