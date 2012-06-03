--- ./dump-ast.hs.orig	2011-09-09 11:13:26.000000000 +0200
+++ ./dump-ast.hs	2012-05-15 20:30:49.000000000 +0200
@@ -147,13 +147,10 @@
   dump (CFDefExt cFunDef)  = parens $ "CFDefExt "++ dump cFunDef
   -- The version of CAsmExt in the repository has an additional second
   -- argument. Uncomment this if needed.
-  dump (CAsmExt cStrLit _) = parens $ "CAsmExt " ++ dump cStrLit
+  dump (CAsmExt cStrLit) = parens $ "CAsmExt " ++ dump cStrLit
   --dump (CAsmExt cStrLit) = parens $ "CAsmExt " ++ dump cStrLit
 
-cDeclFile (CDecl _ _ nodeInfo) =
-  case fileOfNode nodeInfo of
-    Nothing -> ""
-    Just filePath -> "\"" ++ filePath ++ "\""
+cDeclFile (CDecl _ _ nodeInfo) = "\"" ++ fileOfNode nodeInfo ++ "\""
 
 -- | C function definition (C99 6.9.1, K&R A10.1)
 --
