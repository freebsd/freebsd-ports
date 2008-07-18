--- src/Haddock/GHC/Typecheck.hs.orig	2008-05-01 15:13:13.000000000 +0200
+++ src/Haddock/GHC/Typecheck.hs	2008-06-22 16:52:52.000000000 +0200
@@ -23,6 +23,7 @@
 
 import Data.List
 
+import FastString
 
 type CheckedMod = (Module, FilePath, FullyCheckedMod)
 
@@ -69,7 +70,7 @@
 mkGhcModule (mod, file, checkedMod) dynflags = GhcModule {
   ghcModule         = mod,
   ghcFilename       = file,
-  ghcMbDocOpts      = mbOpts,
+  ghcMbDocOpts      = fmap unpackFS mbOpts,
   ghcHaddockModInfo = info,
   ghcMbDoc          = mbDoc,
   ghcGroup          = group,
@@ -79,6 +80,6 @@
   ghcInstances      = modInfoInstances modInfo
 }
   where
-    HsModule _ _ _ _ _ mbOpts _ _      = unLoc parsed
+    HsModule _ _ _ _ mbOpts _ _      = unLoc parsed
     (group, _, mbExports, mbDoc, info) = renamed
     (parsed, renamed, _, modInfo)      = checkedMod
