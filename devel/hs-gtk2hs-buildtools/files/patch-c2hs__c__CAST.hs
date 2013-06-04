--- ./c2hs/c/CAST.hs.orig	2012-11-12 00:26:43.000000000 +0100
+++ ./c2hs/c/CAST.hs	2013-05-28 11:02:33.000000000 +0200
@@ -1125,6 +1125,9 @@
     put_ bh (CTypedef ae) = do
             putByte bh 4
             put_ bh ae
+    put_ bh (CThread af) = do
+            putByte bh 5
+            put_ bh af
     get bh = do
             h <- getByte bh
             case h of
@@ -1143,6 +1146,9 @@
               4 -> do
                     ae <- get bh
                     return (CTypedef ae)
+              5 -> do
+                    af <- get bh
+                    return (CThread af)
 
 instance Binary CTypeQual where
     put_ bh (CConstQual aa) = do
