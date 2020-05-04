--- src/Language/PureScript/CST/Utils.hs.orig	2019-11-02 17:39:14 UTC
+++ src/Language/PureScript/CST/Utils.hs
@@ -20,6 +20,32 @@ import Language.PureScript.CST.Types
 import qualified Language.PureScript.Names as N
 import Language.PureScript.PSString (PSString, mkString)
 
+
+newtype QualifiedProperName =
+  QualifiedProperName { getQualifiedProperName :: forall a. QualifiedName (N.ProperName a) }
+
+qualifiedProperName :: QualifiedName (N.ProperName a) -> QualifiedProperName
+qualifiedProperName n = QualifiedProperName (N.coerceProperName <$> n)
+
+
+newtype ProperName =
+  ProperName { getProperName :: forall a. Name (N.ProperName a) }
+
+properName :: Name (N.ProperName a) -> ProperName
+properName n = ProperName (N.coerceProperName <$> n)
+
+newtype QualifiedOpName =
+  QualifiedOpName { getQualifiedOpName :: forall a. QualifiedName (N.OpName a) }
+
+qualifiedOpName :: QualifiedName (N.OpName a) -> QualifiedOpName
+qualifiedOpName n = QualifiedOpName (N.coerceOpName <$> n)
+
+newtype OpName =
+  OpName { getOpName :: forall a. Name (N.OpName a) }
+
+opName :: Name (N.OpName a) -> OpName
+opName n = OpName (N.coerceOpName <$> n)
+
 placeholder :: SourceToken
 placeholder = SourceToken
   { tokAnn = TokenAnn (SourceRange (SourcePos 0 0) (SourcePos 0 0)) [] []
