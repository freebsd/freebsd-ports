--- haddock/src/Main.hs.orig	Tue Feb  1 22:42:31 2005
+++ haddock/src/Main.hs	Tue Feb  1 22:42:50 2005
@@ -460,8 +460,7 @@
 
   when (not (null name_strings)) $
 	  tell ["Warning: " ++ show mdl ++ 
-		": the following names could not be resolved:\n\ 
-		\   " ++ concat (map (' ':) name_strings)
+		": the following names could not be resolved:\n" ++ concat (map (' ':) name_strings)
 		]
 
   return (mdl, Interface { 
