--- src/hmake/Config.hs.orig	2007-11-23 14:26:05.000000000 +0000
+++ src/hmake/Config.hs	2009-07-16 07:56:15.000000000 +0000
@@ -272,14 +272,14 @@
       ok <- doesFileExist ghcpkg0
       let ghcpkg = if ok then ghcpkg0 else dirname fullpath++"/ghc-pkg"
    -- pkgs <- runAndReadStdout (ghcpkg++" --list-packages")
-      pkgs <- runAndReadStdout (ghcpkg++" -l")
+      pkgs <- runAndReadStdout (ghcpkg++" list")
       let pkgsOK = filter (\p-> any (`isPrefixOf` p)
                                     ["std","base","haskell98"])
                           (deComma pkgs)
       idirs <- mapM (\p-> runAndReadStdout
-                              (ghcpkg++" --show-package="
+                              (ghcpkg++" field "
                                ++deVersion (ghcsym>=604) p
-                               ++" --field=import_dirs"))
+                               ++" import_dirs"))
                     pkgsOK
       return config{ includePaths = pkgDirs libdir (nub idirs) }
  where
