--- src/hmake/Config.hs.orig	2006-07-07 18:01:16.000000000 +0200
+++ src/hmake/Config.hs	2008-02-28 22:18:01.000000000 +0100
@@ -267,7 +267,7 @@
     else do -- 5.00 and above
       pkgcfg <- runAndReadStdout (escape ghcpath++" --print-libdir")
       let libdir  = escape pkgcfg
-          incdir1 = libdir++"/imports"
+          incdir1 = if ghcsym < 608 then libdir++"/imports" else libdir++"/lib"
       ok <- doesDirectoryExist incdir1
       if ok
         then do
