--- ./Build/Configure.hs.orig	2014-07-09 22:09:05.000000000 +0200
+++ ./Build/Configure.hs	2014-07-13 15:15:00.000000000 +0200
@@ -68,7 +68,7 @@
 				else search cmds
 	
 	shacmds n = concatMap (\x -> [x, 'g':x]) $
-		map (\x -> "sha" ++ show n ++ x) ["sum", ""]
+		map (\x -> "gsha" ++ show n ++ x) ["sum", ""]
 
 tmpDir :: String
 tmpDir = "tmp"
