--- ./libraries/Cabal/Distribution/Simple/Haddock.hs.orig	2011-06-13 19:10:10.000000000 +0200
+++ ./libraries/Cabal/Distribution/Simple/Haddock.hs	2012-01-25 07:33:27.000000000 +0100
@@ -440,8 +440,9 @@
   let allPkgs = installedPkgs lbi
       directDeps = map fst (externalPackageDeps lbi)
   transitiveDeps <- case dependencyClosure allPkgs directDeps of
-                    Left x -> return x
-                    Right _ -> die "Can't find transitive deps for haddock"
+    Left x    -> return x
+    Right inf -> die $ "internal error when calculating transative "
+                    ++ "package dependencies.\nDebug info: " ++ show inf
   interfaces <- sequence
     [ case interfaceAndHtmlPath ipkg of
         Nothing -> return (Left (packageId ipkg))
