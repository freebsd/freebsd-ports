https://github.com/commercialhaskell/stack/pull/5622

--- src/Stack/Setup.hs.orig	2021-07-19 21:35:32 UTC
+++ src/Stack/Setup.hs
@@ -1266,6 +1266,7 @@ getOSKey platform =
         Platform Arm                   Cabal.Linux   -> return "linux-armv7"
         Platform AArch64               Cabal.Linux   -> return "linux-aarch64"
         Platform Sparc                 Cabal.Linux   -> return "linux-sparc"
+        Platform AArch64               Cabal.FreeBSD -> return "freebsd-aarch64"
         Platform arch os -> throwM $ UnsupportedSetupCombo os arch
 
 downloadOrUseLocal
