--- ./Build/Configure.hs.orig	2013-03-23 20:06:19.000000000 +0200
+++ ./Build/Configure.hs	2013-05-09 22:49:33.000000000 +0200
@@ -55,7 +55,7 @@
 		key = "sha" ++ show n
 		check = "</dev/null 2>/dev/null | grep -q '" ++ knowngood ++ "'"
 	shacmds n = concatMap (\x -> [x, 'g':x, osxpath </> x]) $
-		map (\x -> "sha" ++ show n ++ x) ["sum", ""]
+		map (\x -> "gsha" ++ show n ++ x) ["sum", ""]
 	{- Max OSX sometimes puts GNU tools outside PATH, so look in
 	 - the location it uses, and remember where to run them
 	 - from. -}
