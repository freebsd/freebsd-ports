--- Build/Configure.hs.orig	2017-06-12 17:56:05 UTC
+++ Build/Configure.hs
@@ -75,7 +75,7 @@ shaTestCases l = map make l
 				else search cmds
 	
 	shacmds n = concatMap (\x -> [x, 'g':x]) $
-		map (\x -> "sha" ++ show n ++ x) ["sum", ""]
+		map (\x -> "gsha" ++ show n ++ x) ["sum", ""]
 
 tmpDir :: String
 tmpDir = "tmp"
