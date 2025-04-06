--- Cabal/src/Distribution/Simple/Configure.hs.orig	2024-06-24 23:58:58 UTC
+++ Cabal/src/Distribution/Simple/Configure.hs
@@ -2631,6 +2631,7 @@ checkForeignLibSupported comp platform flib = go (comp
     goGhcPlatform :: Platform -> Maybe String
     goGhcPlatform (Platform _ OSX) = goGhcOsx (foreignLibType flib)
     goGhcPlatform (Platform _ Linux) = goGhcLinux (foreignLibType flib)
+    goGhcPlatform (Platform _ FreeBSD) = goGhcLinux (foreignLibType flib)
     goGhcPlatform (Platform I386 Windows) = goGhcWindows (foreignLibType flib)
     goGhcPlatform (Platform X86_64 Windows) = goGhcWindows (foreignLibType flib)
     goGhcPlatform _ =
