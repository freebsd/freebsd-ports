--- Cabal/src/Distribution/Simple/Configure.hs.orig	2025-04-03 19:39:49 UTC
+++ Cabal/src/Distribution/Simple/Configure.hs
@@ -2854,6 +2854,7 @@ checkForeignLibSupported comp platform flib = go (comp
     goGhcPlatform :: Platform -> Maybe String
     goGhcPlatform (Platform _ OSX) = goGhcOsx (foreignLibType flib)
     goGhcPlatform (Platform _ Linux) = goGhcLinux (foreignLibType flib)
+    goGhcPlatform (Platform _ FreeBSD) = goGhcLinux (foreignLibType flib)
     goGhcPlatform (Platform I386 Windows) = goGhcWindows (foreignLibType flib)
     goGhcPlatform (Platform X86_64 Windows) = goGhcWindows (foreignLibType flib)
     goGhcPlatform _ =
