--- ./packages/Cabal/Distribution/PackageDescription.hs.orig	2006-09-21 00:29:42.000000000 +0200
+++ ./packages/Cabal/Distribution/PackageDescription.hs	2014-07-01 03:36:34.000000000 +0200
@@ -437,7 +437,7 @@
                            showToken          parseTokenQ
                            ccOptions          (\val binfo -> binfo{ccOptions=val})
  , listField "ld-options"
-                           showToken          parseTokenQ
+                           showToken'         parseTokenQ'
                            ldOptions          (\val binfo -> binfo{ldOptions=val})
  , listField "frameworks"
                            showToken          parseTokenQ
