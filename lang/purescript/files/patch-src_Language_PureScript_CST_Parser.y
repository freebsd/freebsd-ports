--- src/Language/PureScript/CST/Parser.y.orig	2019-11-02 17:39:14 UTC
+++ src/Language/PureScript/CST/Parser.y
@@ -175,12 +175,12 @@ moduleName :: { Name N.ModuleName }
   : UPPER {% upperToModuleName $1 }
   | QUAL_UPPER {% upperToModuleName $1 }
 
-qualProperName :: { QualifiedName (N.ProperName a) }
-  : UPPER {% toQualifiedName N.ProperName $1 }
-  | QUAL_UPPER {% toQualifiedName N.ProperName $1 }
+qualProperName :: { QualifiedProperName }
+  : UPPER {% qualifiedProperName <\$> toQualifiedName N.ProperName $1 }
+  | QUAL_UPPER {% qualifiedProperName <\$> toQualifiedName N.ProperName $1 }
 
-properName :: { Name (N.ProperName a) }
-  : UPPER {% toName N.ProperName $1 }
+properName :: { ProperName }
+  : UPPER {% properName <\$> toName N.ProperName $1 }
 
 qualIdent :: { QualifiedName Ident }
   : LOWER {% toQualifiedName Ident $1 }
@@ -195,29 +195,29 @@ ident :: { Name Ident }
   | 'hiding' {% toName Ident $1 }
   | 'kind' {% toName Ident $1 }
 
-qualOp :: { QualifiedName (N.OpName a) }
-  : OPERATOR {% toQualifiedName N.OpName $1 }
-  | QUAL_OPERATOR {% toQualifiedName N.OpName $1 }
-  | '<=' {% toQualifiedName N.OpName $1 }
-  | '-' {% toQualifiedName N.OpName $1 }
-  | '#' {% toQualifiedName N.OpName $1 }
-  | ':' {% toQualifiedName N.OpName $1 }
+qualOp :: { QualifiedOpName }
+  : OPERATOR {% qualifiedOpName <\$> toQualifiedName N.OpName $1 }
+  | QUAL_OPERATOR {% qualifiedOpName <\$> toQualifiedName N.OpName $1 }
+  | '<=' {% qualifiedOpName <\$> toQualifiedName N.OpName $1 }
+  | '-' {% qualifiedOpName <\$> toQualifiedName N.OpName $1 }
+  | '#' {% qualifiedOpName <\$> toQualifiedName N.OpName $1 }
+  | ':' {% qualifiedOpName <\$> toQualifiedName N.OpName $1 }
 
-op :: { Name (N.OpName a) }
-  : OPERATOR {% toName N.OpName $1 }
-  | '<=' {% toName N.OpName $1 }
-  | '-' {% toName N.OpName $1 }
-  | '#' {% toName N.OpName $1 }
-  | ':' {% toName N.OpName $1 }
+op :: { OpName }
+  : OPERATOR {% opName <\$> toName N.OpName $1 }
+  | '<=' {% opName <\$> toName N.OpName $1 }
+  | '-' {% opName <\$> toName N.OpName $1 }
+  | '#' {% opName <\$> toName N.OpName $1 }
+  | ':' {% opName <\$> toName N.OpName $1 }
 
-qualSymbol :: { QualifiedName (N.OpName a) }
-  : SYMBOL {% toQualifiedName N.OpName $1 }
-  | QUAL_SYMBOL {% toQualifiedName N.OpName $1 }
-  | '(..)' {% toQualifiedName N.OpName $1 }
+qualSymbol :: { QualifiedOpName }
+  : SYMBOL {% qualifiedOpName <\$> toQualifiedName N.OpName $1 }
+  | QUAL_SYMBOL {% qualifiedOpName <\$> toQualifiedName N.OpName $1 }
+  | '(..)' {% qualifiedOpName <\$> toQualifiedName N.OpName $1 }
 
-symbol :: { Name (N.OpName a) }
-  : SYMBOL {% toName N.OpName $1 }
-  | '(..)' {% toName N.OpName $1 }
+symbol :: { OpName }
+  : SYMBOL {% opName <\$> toName N.OpName $1 }
+  | '(..)' {% opName <\$> toName N.OpName $1 }
 
 label :: { Label }
   : LOWER { toLabel $1 }
@@ -278,7 +278,7 @@ kind :: { Kind () }
   | kind1 '->' kind { KindArr () $1 $2 $3 }
 
 kind1 :: { Kind () }
-  : qualProperName { KindName () $1 }
+  : qualProperName { KindName () (getQualifiedProperName $1) }
   | '#' kind1 { KindRow () $1 $2 }
   | '(' kind ')' { KindParens () (Wrapped $1 $2 $3) }
 
@@ -297,7 +297,7 @@ type2 :: { Type () }
 
 type3 :: { Type () }
   : type4 { $1 }
-  | type3 qualOp type4 { TypeOp () $1 $2 $3 }
+  | type3 qualOp type4 { TypeOp () $1 (getQualifiedOpName $2) $3 }
 
 type4 :: { Type () }
   : typeAtom { $1 }
@@ -306,8 +306,8 @@ type4 :: { Type () }
 typeAtom :: { Type ()}
   : '_' { TypeWildcard () $1 }
   | ident { TypeVar () $1 }
-  | qualProperName { TypeConstructor () $1 }
-  | qualSymbol { TypeOpName () $1 }
+  | qualProperName { TypeConstructor () (getQualifiedProperName $1) }
+  | qualSymbol { TypeOpName () (getQualifiedOpName $1) }
   | string { uncurry (TypeString ()) $1 }
   | hole { TypeHole () $1 }
   | '(->)' { TypeArrName () $1 }
@@ -321,8 +321,8 @@ typeAtom :: { Type ()}
 -- row, and to annotate `a` with kind `Foo`, one must use `((a) :: Foo)`.
 typeKindedAtom :: { Type () }
   : '_' { TypeWildcard () $1 }
-  | qualProperName { TypeConstructor () $1 }
-  | qualSymbol { TypeOpName () $1 }
+  | qualProperName { TypeConstructor () (getQualifiedProperName $1) }
+  | qualSymbol { TypeOpName () (getQualifiedOpName $1) }
   | hole { TypeHole () $1 }
   | '{' row '}' { TypeRecord () (Wrapped $1 $2 $3) }
   | '(' row ')' { TypeRow () (Wrapped $1 $2 $3) }
@@ -356,7 +356,7 @@ expr :: { Expr () }
 
 expr1 :: { Expr () }
   : expr2 { $1 }
-  | expr1 qualOp expr2 { ExprOp () $1 $2 $3 }
+  | expr1 qualOp expr2 { ExprOp () $1 (getQualifiedOpName $2) $3 }
 
 expr2 :: { Expr () }
   : expr3 { $1 }
@@ -364,7 +364,7 @@ expr2 :: { Expr () }
 
 exprBacktick :: { Expr () }
   : expr3 { $1 }
-  | exprBacktick qualOp expr3 { ExprOp () $1 $2 $3 }
+  | exprBacktick qualOp expr3 { ExprOp () $1 (getQualifiedOpName $2) $3 }
 
 expr3 :: { Expr () }
   : expr4 { $1 }
@@ -415,8 +415,8 @@ exprAtom :: { Expr () }
   : '_' { ExprSection () $1 }
   | hole { ExprHole () $1 }
   | qualIdent { ExprIdent () $1 }
-  | qualProperName { ExprConstructor () $1 }
-  | qualSymbol { ExprOpName () $1 }
+  | qualProperName { ExprConstructor () (getQualifiedProperName $1) }
+  | qualSymbol { ExprOpName () (getQualifiedOpName $1) }
   | boolean { uncurry (ExprBoolean ()) $1 }
   | char { uncurry (ExprChar ()) $1 }
   | string { uncurry (ExprString ()) $1 }
@@ -554,7 +554,7 @@ binder :: { Binder () }
 
 binder1 :: { Binder () }
   : binder2 { $1 }
-  | binder1 qualOp binder2 { BinderOp () $1 $2 $3 }
+  | binder1 qualOp binder2 { BinderOp () $1 (getQualifiedOpName $2) $3 }
 
 binder2 :: { Binder () }
   : many(binderAtom) {% toBinderConstructor $1 }
@@ -563,7 +563,7 @@ binderAtom :: { Binder () }
   : '_' { BinderWildcard () $1 }
   | ident { BinderVar () $1 }
   | ident '@' binderAtom { BinderNamed () $1 $2 $3 }
-  | qualProperName { BinderConstructor () $1 [] }
+  | qualProperName { BinderConstructor () (getQualifiedProperName $1) [] }
   | boolean { uncurry (BinderBoolean ()) $1 }
   | char { uncurry (BinderChar ()) $1 }
   | string { uncurry (BinderString ()) $1 }
@@ -602,7 +602,7 @@ moduleDecls :: { ([ImportDecl ()], [Declaration ()]) }
   : manySep(moduleDecl, '\;') {% toModuleDecls $ NE.toList $1 }
   | {- empty -} { ([], []) }
 
-moduleDecl :: { TmpModuleDecl a }
+moduleDecl :: { TmpModuleDecl () }
   : importDecl { TmpImport $1 }
   | sep(decl, declElse) { TmpChain $1 }
 
@@ -616,18 +616,18 @@ exports :: { Maybe (DelimitedNonEmpty (Export ())) }
 
 export :: { Export () }
   : ident { ExportValue () $1 }
-  | symbol { ExportOp () $1 }
-  | properName { ExportType () $1 Nothing }
-  | properName dataMembers { ExportType () $1 (Just $2) }
-  | 'type' symbol { ExportTypeOp () $1 $2 }
-  | 'class' properName { ExportClass () $1 $2 }
-  | 'kind' properName { ExportKind () $1 $2 }
+  | symbol { ExportOp () (getOpName $1) }
+  | properName { ExportType () (getProperName $1) Nothing }
+  | properName dataMembers { ExportType () (getProperName $1) (Just $2) }
+  | 'type' symbol { ExportTypeOp () $1 (getOpName $2) }
+  | 'class' properName { ExportClass () $1 (getProperName $2) }
+  | 'kind' properName { ExportKind () $1 (getProperName $2) }
   | 'module' moduleName { ExportModule () $1 $2 }
 
 dataMembers :: { (DataMembers ()) }
  : '(..)' { DataAll () $1 }
  | '(' ')' { DataEnumerated () (Wrapped $1 Nothing $2) }
- | '(' sep(properName, ',') ')' { DataEnumerated () (Wrapped $1 (Just $2) $3) }
+ | '(' sep(properName, ',') ')' { DataEnumerated () (Wrapped $1 (Just \$ getProperName <\$> $2) $3) }
 
 importDecl :: { ImportDecl () }
   : 'import' moduleName imports { ImportDecl () $1 $2 $3 Nothing }
@@ -640,18 +640,18 @@ imports :: { Maybe (Maybe SourceToken, DelimitedNonEmp
 
 import :: { Import () }
   : ident { ImportValue () $1 }
-  | symbol { ImportOp () $1 }
-  | properName { ImportType () $1 Nothing }
-  | properName dataMembers { ImportType () $1 (Just $2) }
-  | 'type' symbol { ImportTypeOp () $1 $2 }
-  | 'class' properName { ImportClass () $1 $2 }
-  | 'kind' properName { ImportKind () $1 $2 }
+  | symbol { ImportOp () (getOpName $1) }
+  | properName { ImportType () (getProperName $1) Nothing }
+  | properName dataMembers { ImportType () (getProperName $1) (Just $2) }
+  | 'type' symbol { ImportTypeOp () $1 (getOpName $2) }
+  | 'class' properName { ImportClass () $1 (getProperName $2) }
+  | 'kind' properName { ImportKind () $1 (getProperName $2) }
 
 decl :: { Declaration () }
   : dataHead { DeclData () $1 Nothing }
   | dataHead '=' sep(dataCtor, '|') { DeclData () $1 (Just ($2, $3)) }
   | typeHead '=' type {% checkNoWildcards $3 *> pure (DeclType () $1 $2 $3) }
-  | newtypeHead '=' properName typeAtom {% checkNoWildcards $4 *> pure (DeclNewtype () $1 $2 $3 $4) }
+  | newtypeHead '=' properName typeAtom {% checkNoWildcards $4 *> pure (DeclNewtype () $1 $2 (getProperName $3) $4) }
   | classHead {% checkFundeps $1 *> pure (DeclClass () $1 Nothing) }
   | classHead 'where' '\{' manySep(classMember, '\;') '\}' {% checkFundeps $1 *> pure (DeclClass () $1 (Just ($2, $4))) }
   | instHead { DeclInstanceChain () (Separated (Instance $1 Nothing) []) }
@@ -664,17 +664,17 @@ decl :: { Declaration () }
   | 'foreign' 'import' foreign { DeclForeign () $1 $2 $3 }
 
 dataHead :: { DataHead () }
-  : 'data' properName manyOrEmpty(typeVarBinding) { DataHead $1 $2 $3 }
+  : 'data' properName manyOrEmpty(typeVarBinding) { DataHead $1 (getProperName $2) $3 }
 
 typeHead :: { DataHead () }
-  : 'type' properName manyOrEmpty(typeVarBinding) { DataHead $1 $2 $3 }
+  : 'type' properName manyOrEmpty(typeVarBinding) { DataHead $1 (getProperName $2) $3 }
 
 newtypeHead :: { DataHead () }
-  : 'newtype' properName manyOrEmpty(typeVarBinding) { DataHead $1 $2 $3 }
+  : 'newtype' properName manyOrEmpty(typeVarBinding) { DataHead $1 (getProperName $2) $3 }
 
 dataCtor :: { DataCtor () }
   : properName manyOrEmpty(typeAtom)
-      {% for_ $2 checkNoWildcards *> pure (DataCtor () $1 $2) }
+      {% for_ $2 checkNoWildcards *> pure (DataCtor () (getProperName $1) $2) }
 
 -- Class head syntax requires unbounded lookahead due to a conflict between
 -- row syntax and `typeVarBinding`. `(a :: B)` is either a row in `constraint`
@@ -698,7 +698,7 @@ classSuper
   : constraints '<=' {%^ revert $ pure ($1, $2) }
 
 classNameAndFundeps :: { (Name (N.ProperName 'N.ClassName), [TypeVarBinding ()], Maybe (SourceToken, Separated ClassFundep)) }
-  : properName manyOrEmpty(typeVarBinding) fundeps {%^ revert $ pure ($1, $2, $3) }
+  : properName manyOrEmpty(typeVarBinding) fundeps {%^ revert $ pure (getProperName $1, $2, $3) }
 
 fundeps :: { Maybe (SourceToken, Separated ClassFundep) }
   : {- empty -} { Nothing }
@@ -713,16 +713,16 @@ classMember :: { Labeled (Name Ident) (Type ()) }
 
 instHead :: { InstanceHead () }
   : 'instance' ident '::' constraints '=>' qualProperName manyOrEmpty(typeAtom)
-      { InstanceHead $1 $2 $3 (Just ($4, $5)) $6 $7 }
+      { InstanceHead $1 $2 $3 (Just ($4, $5)) (getQualifiedProperName $6) $7 }
   | 'instance' ident '::' qualProperName manyOrEmpty(typeAtom)
-      { InstanceHead $1 $2 $3 Nothing $4 $5 }
+      { InstanceHead $1 $2 $3 Nothing (getQualifiedProperName $4) $5 }
 
 constraints :: { OneOrDelimited (Constraint ()) }
   : constraint { One $1 }
   | '(' sep(constraint, ',') ')' { Many (Wrapped $1 $2 $3) }
 
 constraint :: { Constraint () }
-  : qualProperName manyOrEmpty(typeAtom) {% for_ $2 checkNoWildcards *> for_ $2 checkNoForalls *> pure (Constraint () $1 $2) }
+  : qualProperName manyOrEmpty(typeAtom) {% for_ $2 checkNoWildcards *> for_ $2 checkNoForalls *> pure (Constraint () (getQualifiedProperName $1) $2) }
   | '(' constraint ')' { ConstraintParens () (Wrapped $1 $2 $3) }
 
 instBinding :: { InstanceBinding () }
@@ -730,9 +730,9 @@ instBinding :: { InstanceBinding () }
   | ident manyOrEmpty(binderAtom) guardedDecl { InstanceBindingName () (ValueBindingFields $1 $2 $3) }
 
 fixity :: { FixityFields }
-  : infix int qualIdent 'as' op { FixityFields $1 $2 (FixityValue (fmap Left $3) $4 $5) }
-  | infix int qualProperName 'as' op { FixityFields $1 $2 (FixityValue (fmap Right $3) $4 $5) }
-  | infix int 'type' qualProperName 'as' op { FixityFields $1 $2 (FixityType $3 $4 $5 $6) }
+  : infix int qualIdent 'as' op { FixityFields $1 $2 (FixityValue (fmap Left $3) $4 (getOpName $5)) }
+  | infix int qualProperName 'as' op { FixityFields $1 $2 (FixityValue (fmap Right (getQualifiedProperName $3)) $4 (getOpName $5)) }
+  | infix int 'type' qualProperName 'as' op { FixityFields $1 $2 (FixityType $3 (getQualifiedProperName $4) $5 (getOpName $6)) }
 
 infix :: { (SourceToken, Fixity) }
   : 'infix' { ($1, Infix) }
@@ -741,8 +741,8 @@ infix :: { (SourceToken, Fixity) }
 
 foreign :: { Foreign () }
   : ident '::' type { ForeignValue (Labeled $1 $2 $3) }
-  | 'data' properName '::' kind { ForeignData $1 (Labeled $2 $3 $4) }
-  | 'kind' properName { ForeignKind $1 $2 }
+  | 'data' properName '::' kind { ForeignData $1 (Labeled (getProperName $2) $3 $4) }
+  | 'kind' properName { ForeignKind $1 (getProperName $2) }
 
 -- Partial parsers which can be combined with combinators for adhoc use. We need
 -- to revert the lookahead token so that it doesn't consume an extra token
