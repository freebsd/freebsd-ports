--- lib/CodeGen/CGDebugInfo.cpp.orig	2019-10-20 18:50:14 UTC
+++ lib/CodeGen/CGDebugInfo.cpp
@@ -3143,7 +3143,7 @@ CGDebugInfo::getGlobalVariableForwardDeclaration(const
   auto Align = getDeclAlignIfRequired(VD, CGM.getContext());
   auto *GV = DBuilder.createTempGlobalVariableFwdDecl(
       DContext, Name, LinkageName, Unit, Line, getOrCreateType(T, Unit),
-      !VD->isExternallyVisible(), nullptr, llvm::DINode::FlagZero, Align);
+      !VD->isExternallyVisible(), nullptr, Align);
   FwdDeclReplaceMap.emplace_back(
       std::piecewise_construct,
       std::make_tuple(cast<VarDecl>(VD->getCanonicalDecl())),
@@ -4071,7 +4071,7 @@ void CGDebugInfo::EmitGlobalVariable(llvm::GlobalVaria
         DContext, DeclName, LinkageName, Unit, LineNo, getOrCreateType(T, Unit),
         Var->hasLocalLinkage(),
         Expr.empty() ? nullptr : DBuilder.createExpression(Expr),
-        getOrCreateStaticDataMemberDeclarationOrNull(D), llvm::DINode::FlagZero,
+        getOrCreateStaticDataMemberDeclarationOrNull(D),
 	Align);
     Var->addDebugInfo(GVE);
   }
@@ -4132,7 +4132,7 @@ void CGDebugInfo::EmitGlobalVariable(const ValueDecl *
   GV.reset(DBuilder.createGlobalVariableExpression(
       DContext, Name, StringRef(), Unit, getLineNumber(VD->getLocation()), Ty,
       true, InitExpr, getOrCreateStaticDataMemberDeclarationOrNull(VarD),
-      llvm::DINode::FlagZero, Align));
+      Align));
 }
 
 llvm::DIScope *CGDebugInfo::getCurrentContextDescriptor(const Decl *D) {
