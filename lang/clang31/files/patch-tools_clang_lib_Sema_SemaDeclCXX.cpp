
$FreeBSD$

--- tools/clang/lib/Sema/SemaDeclCXX.cpp.orig
+++ tools/clang/lib/Sema/SemaDeclCXX.cpp
@@ -10795,14 +10795,23 @@
 
 void Sema::MarkVirtualMembersReferenced(SourceLocation Loc,
                                         const CXXRecordDecl *RD) {
-  for (CXXRecordDecl::method_iterator i = RD->method_begin(), 
-       e = RD->method_end(); i != e; ++i) {
-    CXXMethodDecl *MD = *i;
-
-    // C++ [basic.def.odr]p2:
-    //   [...] A virtual member function is used if it is not pure. [...]
-    if (MD->isVirtual() && !MD->isPure())
-      MarkFunctionReferenced(Loc, MD);
+  // Mark all functions which will appear in RD's vtable as used.
+  CXXFinalOverriderMap FinalOverriders;
+  RD->getFinalOverriders(FinalOverriders);
+  for (CXXFinalOverriderMap::const_iterator I = FinalOverriders.begin(),
+                                            E = FinalOverriders.end();
+       I != E; ++I) {
+    for (OverridingMethods::const_iterator OI = I->second.begin(),
+                                           OE = I->second.end();
+         OI != OE; ++OI) {
+      assert(OI->second.size() > 0 && "no final overrider");
+      CXXMethodDecl *Overrider = OI->second.front().Method;
+
+      // C++ [basic.def.odr]p2:
+      //   [...] A virtual member function is used if it is not pure. [...]
+      if (!Overrider->isPure())
+        MarkFunctionReferenced(Loc, Overrider);
+    }
   }
 
   // Only classes that have virtual bases need a VTT.
