--- ./GetOpt.hs.orig	2002-02-18 01:54:06.000000000 +0100
+++ ./GetOpt.hs	2012-05-13 00:56:23.000000000 +0200
@@ -19,7 +19,7 @@
 
 module GetOpt (ArgOrder(..), OptDescr(..), ArgDescr(..), usageInfo, getOpt) where
 
-import List(isPrefixOf)
+import Data.List(isPrefixOf)
 
 data ArgOrder a                        -- what to do with options following non-options:
    = RequireOrder                      --    no option processing after first non-option
