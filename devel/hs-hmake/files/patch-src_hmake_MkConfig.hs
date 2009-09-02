--- src/hmake/MkConfig.hs.orig	2006-07-07 16:01:16.000000000 +0000
+++ src/hmake/MkConfig.hs	2009-07-16 07:56:44.000000000 +0000
@@ -258,14 +258,14 @@
           ok <- doesFileExist ghcpkg0
           let ghcpkg = if ok then ghcpkg0 else dirname fullpath++"/ghc-pkg"
        -- pkgs <- runAndReadStdout (ghcpkg++" --list-packages")
-          pkgs <- runAndReadStdout (ghcpkg++" -l")
+          pkgs <- runAndReadStdout (ghcpkg++" list")
           let pkgsOK = filter (\p-> any (`isPrefixOf` p)
                                         ["std","base","haskell98"])
                               (deComma pkgs)
           idirs <- mapM (\p-> runAndReadStdout
-                                  (ghcpkg++" --show-package="
+                                  (ghcpkg++" field "
                                    ++deVersion (ghcsym>=604) p
-                                   ++" --field=import_dirs"))
+                                   ++" import_dirs"))
                         pkgsOK
           return config{ includePaths = pkgDirs libdir (nub idirs) }
         else do ioError (userError ("Can't find ghc includes at "++incdir1))
