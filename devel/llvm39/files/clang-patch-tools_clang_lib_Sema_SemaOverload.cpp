--- tools/clang/lib/Sema/SemaOverload.cpp.orig
+++ tools/clang/lib/Sema/SemaOverload.cpp
@@ -5783,6 +5783,28 @@
       Candidate.FailureKind = ovl_fail_illegal_constructor;
       return;
     }
+
+    // C++ [over.match.funcs]p8: (proposed DR resolution)
+    //   A constructor inherited from class type C that has a first parameter
+    //   of type "reference to P" (including such a constructor instantiated
+    //   from a template) is excluded from the set of candidate functions when
+    //   constructing an object of type cv D if the argument list has exactly
+    //   one argument and D is reference-related to P and P is reference-related
+    //   to C.
+    auto *Shadow = dyn_cast<ConstructorUsingShadowDecl>(FoundDecl.getDecl());
+    if (Shadow && Args.size() == 1 && Constructor->getNumParams() >= 1 &&
+        Constructor->getParamDecl(0)->getType()->isReferenceType()) {
+      QualType P = Constructor->getParamDecl(0)->getType()->getPointeeType();
+      QualType C = Context.getRecordType(Constructor->getParent());
+      QualType D = Context.getRecordType(Shadow->getParent());
+      SourceLocation Loc = Args.front()->getExprLoc();
+      if ((Context.hasSameUnqualifiedType(P, C) || IsDerivedFrom(Loc, P, C)) &&
+          (Context.hasSameUnqualifiedType(D, P) || IsDerivedFrom(Loc, D, P))) {
+        Candidate.Viable = false;
+        Candidate.FailureKind = ovl_fail_inhctor_slice;
+        return;
+      }
+    }
   }
 
   unsigned NumParams = Proto->getNumParams();
@@ -9750,6 +9772,17 @@
   case ovl_fail_enable_if:
     return DiagnoseFailedEnableIfAttr(S, Cand);
 
+  case ovl_fail_inhctor_slice:
+    // It's generally not interesting to note copy/move constructors here.
+    if (cast<CXXConstructorDecl>(Fn)->isCopyOrMoveConstructor())
+      return;
+    S.Diag(Fn->getLocation(),
+           diag::note_ovl_candidate_inherited_constructor_slice)
+      << (Fn->getPrimaryTemplate() ? 1 : 0)
+      << Fn->getParamDecl(0)->getType()->isRValueReferenceType();
+    MaybeEmitInheritedConstructorNote(S, Cand->FoundDecl);
+    return;
+
   case ovl_fail_addr_not_available: {
     bool Available = checkAddressOfCandidateIsAvailable(S, Cand->Function);
     (void)Available;
