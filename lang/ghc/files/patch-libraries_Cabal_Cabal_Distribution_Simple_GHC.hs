--- libraries/Cabal/Cabal/Distribution/Simple/GHC.hs.orig	2015-04-01 00:24:45 UTC
+++ libraries/Cabal/Cabal/Distribution/Simple/GHC.hs
@@ -875,7 +875,7 @@ getRPaths lbi clbi | supportRPaths hostO
     supportRPaths Linux       = True
     supportRPaths Windows     = False
     supportRPaths OSX         = True
-    supportRPaths FreeBSD     = False
+    supportRPaths FreeBSD     = True
     supportRPaths OpenBSD     = False
     supportRPaths NetBSD      = False
     supportRPaths DragonFly   = False
