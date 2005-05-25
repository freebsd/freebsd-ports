--- ghc/compiler/ndpFlatten/Flattening.hs.orig	Tue May 24 22:10:38 2005
+++ ghc/compiler/ndpFlatten/Flattening.hs	Tue May 24 22:10:56 2005
@@ -650,8 +650,8 @@ dftbpBinders indexBnds exprBnds =
 	return ((fBnd, (newBnd:restBnds)), liftTy ty)
 
     dftbpBinders'  _ _ _ = 
-      panic "Flattening.dftbpBinders: index and expression binder lists \ 
-	    \have different length!"
+      panic ("Flattening.dftbpBinders: index and expression binder lists "++
+	    "have different length!")
 
 getExprOfBind:: CoreBind -> CoreExpr
 getExprOfBind (NonRec _ expr) = expr
