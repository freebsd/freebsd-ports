--- ./libraries/Cabal/Distribution/Simple/LocalBuildInfo.hs.orig	2011-06-13 19:10:10.000000000 +0200
+++ ./libraries/Cabal/Distribution/Simple/LocalBuildInfo.hs	2012-01-25 07:33:27.000000000 +0100
@@ -136,13 +136,17 @@
   }
   deriving (Read, Show)
 
--- | External package dependencies for the package as a whole, the union of the
--- individual 'targetPackageDeps'.
+-- | External package dependencies for the package as a whole. This is the
+-- union of the individual 'componentPackageDeps', less any internal deps.
 externalPackageDeps :: LocalBuildInfo -> [(InstalledPackageId, PackageId)]
-externalPackageDeps lbi = nub $
+externalPackageDeps lbi = filter (not . internal . snd) $ nub $
   -- TODO:  what about non-buildable components?
-     maybe [] componentPackageDeps (libraryConfig lbi)
-  ++ concatMap (componentPackageDeps . snd) (executableConfigs lbi)
+       maybe [] componentPackageDeps (libraryConfig lbi)
+    ++ concatMap (componentPackageDeps . snd) (executableConfigs lbi)
+  where
+    -- True if this dependency is an internal one (depends on the library
+    -- defined in the same package).
+    internal pkgid = pkgid == packageId (localPkgDescr lbi)
 
 -- | The installed package Id we use for local packages registered in the local
 -- package db. This is what is used for intra-package deps between components.
