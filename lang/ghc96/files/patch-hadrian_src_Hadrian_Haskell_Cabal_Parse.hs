--- hadrian/src/Hadrian/Haskell/Cabal/Parse.hs.orig	2025-03-02 13:05:33 UTC
+++ hadrian/src/Hadrian/Haskell/Cabal/Parse.hs
@@ -321,8 +321,8 @@ write_inplace_conf pkg_path res_path pd lbi = do
                   pkg_name = C.display (C.pkgName (CP.sourcePackageId installedPkgInfo))
                   final_ipi = installedPkgInfo {
                                  Installed.includeDirs = concatMap fixupIncludeDir (Installed.includeDirs installedPkgInfo),
-                                 Installed.libraryDirs = [ build_dir ],
-                                 Installed.libraryDynDirs = [ build_dir ],
+                                 Installed.libraryDirs = [ build_dir ] ++ Installed.libraryDirs installedPkgInfo,
+                                 Installed.libraryDynDirs = [ build_dir ] ++ Installed.libraryDynDirs installedPkgInfo,
                                  Installed.dataDir = "${pkgroot}/../../../../" ++ pkg_path,
                                  Installed.haddockHTMLs = [build_dir ++ "/doc/html/" ++ C.display (CP.sourcePackageId installedPkgInfo)],
                                  Installed.haddockInterfaces = [build_dir ++ "/doc/html/" ++  pkg_name ++ "/" ++ pkg_name ++ ".haddock"],
