--- src/haskell/StdPrimsUtil.hs.orig	1999-09-13 00:27:01.000000000 +0200
+++ src/haskell/StdPrimsUtil.hs	2007-10-04 21:22:09.000000000 +0200
@@ -81,8 +81,8 @@
 
 sexp_rd_identifier s = do t <- get_prim "identifier" s
                           (case t of 
-			  SexpLex.STR str -> return str
-			  _ -> error "expected identifier")
+			   SexpLex.STR str -> return str
+			   _ -> error "expected identifier")
 
 
 
