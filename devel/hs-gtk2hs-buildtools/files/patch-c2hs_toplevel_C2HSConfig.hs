--- c2hs/toplevel/C2HSConfig.hs.orig	2014-04-13 05:14:06 UTC
+++ c2hs/toplevel/C2HSConfig.hs
@@ -70,7 +70,7 @@ cpp  = case os of
 cppopts :: [String]
 cppopts  = case (os,cpp) of
   ("openbsd","cpp") -> ["-xc", "-w"]
-  (_,"cpp")         -> ["-x", "c", "-w"]
+  (_,"cpp")         -> ["-x", "c", "-P", "-w"]
   (_,"gcc")         -> ["-E", "-x", "c", "-w"]
   _                 -> []
 
