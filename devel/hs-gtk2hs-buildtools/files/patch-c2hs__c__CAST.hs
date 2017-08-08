--- c2hs/c/CAST.hs.orig	2017-01-14 09:17:54 UTC
+++ c2hs/c/CAST.hs
@@ -1125,6 +1125,9 @@ instance Binary CStorageSpec where
     put_ bh (CTypedef ae) = do
             putByte bh 4
             put_ bh ae
+    put_ bh (CThread af) = do
+            putByte bh 5
+            put_ bh af
     get bh = do
             h <- getByte bh
             case h of
@@ -1143,6 +1146,9 @@ instance Binary CStorageSpec where
               4 -> do
                     ae <- get bh
                     return (CTypedef ae)
+              5 -> do
+                    af <- get bh
+                    return (CThread af)
 
 instance Binary CTypeQual where
     put_ bh (CConstQual aa) = do
