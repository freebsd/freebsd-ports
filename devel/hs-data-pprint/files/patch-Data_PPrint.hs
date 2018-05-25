--- Data/PPrint.hs.orig 2018-04-13 19:36:43 UTC
+++ Data/PPrint.hs
@@ -60,6 +60,6 @@ a === b = do
 showBotts :: [(String, String)] -> Doc
 showBotts es = vcat $ map f es
  where
-    f (i, e) = text i <> text ":" <+> vcat (map text $ lines e)
+    f (i, e) = text i Text.PrettyPrint.HughesPJ.<> text ":" <+> vcat (map text $ lines e)
 
