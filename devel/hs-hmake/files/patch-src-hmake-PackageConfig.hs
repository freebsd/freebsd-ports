--- src/hmake/PackageConfig.hs.orig	2006-08-21 17:30:46.000000000 +0200
+++ src/hmake/PackageConfig.hs	2008-02-28 22:19:23.000000000 +0100
@@ -51,7 +51,7 @@
     else unsafePerformIO $ do
       pkgcfg <- runAndReadStdout (ghc++" --print-libdir")
       let libdir  = escape pkgcfg
-          incdir1 = libdir++"/imports"
+          incdir1 = if ghcsym < 608 then libdir++"/imports" else libdir++"/lib"
       ok <- doesDirectoryExist incdir1
       if ok
         then do
