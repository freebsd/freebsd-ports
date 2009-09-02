--- src/hmake/PackageConfig.hs.orig	2008-04-25 10:28:08.000000000 +0000
+++ src/hmake/PackageConfig.hs	2009-07-16 07:57:07.000000000 +0000
@@ -55,7 +55,7 @@
    -- ghcpkg <- runAndReadStdout
    --                  ("echo `" ++ ghc ++ " --print-libdir`/bin/ghc-pkg")
    -- pkgs <- runAndReadStdout (ghcpkg++" --list-packages")
-      pkgs <- runAndReadStdout (ghcpkg++" -l")
+      pkgs <- runAndReadStdout (ghcpkg++" list")
       let (ok,bad) = partition (\p-> elemBy versionMatch p (deComma pkgs))
                                packages
       when (not (null bad))
@@ -63,8 +63,8 @@
                              ++concat (intersperse ", " bad)
                              ++" not available (according to ghc-pkg)"))
       idirs <- mapM (\p-> runAndReadStdout
-                              (ghcpkg++" --show-package="++p
-                               ++" --field=import_dirs"))
+                              (ghcpkg++" field "++p
+                               ++" import_dirs"))
                     ok
       return (pkgDirs libdir idirs)
  where
