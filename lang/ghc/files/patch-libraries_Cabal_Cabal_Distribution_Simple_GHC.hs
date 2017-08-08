--- libraries/Cabal/Cabal/Distribution/Simple/GHC.hs.orig	2017-01-03 15:59:20 UTC
+++ libraries/Cabal/Cabal/Distribution/Simple/GHC.hs
@@ -996,7 +996,7 @@ getRPaths lbi clbi | supportRPaths hostOS = do
     supportRPaths Linux       = True
     supportRPaths Windows     = False
     supportRPaths OSX         = True
-    supportRPaths FreeBSD     = False
+    supportRPaths FreeBSD     = True
     supportRPaths OpenBSD     = False
     supportRPaths NetBSD      = False
     supportRPaths DragonFly   = False
