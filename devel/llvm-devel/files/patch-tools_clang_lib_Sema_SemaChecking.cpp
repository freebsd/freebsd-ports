
$FreeBSD$

--- tools/clang/lib/Sema/SemaChecking.cpp.orig
+++ tools/clang/lib/Sema/SemaChecking.cpp
@@ -1275,6 +1275,39 @@
     CoveredArgs.set(argIndex);
   }
 
+  // FreeBSD extensions
+  if (CS.getKind() == ConversionSpecifier::bArg || CS.getKind() == ConversionSpecifier::DArg) { 
+     // claim the second argument
+     CoveredArgs.set(argIndex + 1);
+
+    // Now type check the data expression that matches the
+    // format specifier.
+    const Expr *Ex = getDataArg(argIndex);
+    QualType type = (CS.getKind() == ConversionSpecifier::bArg) ? S.Context.IntTy : S.Context.getPointerType(S.Context.UnsignedCharTy);
+    //const analyze_printf::ArgTypeResult &ATR = S.Context.IntTy;
+    const analyze_printf::ArgTypeResult &ATR = type;
+    if (ATR.isValid() && !ATR.matchesType(S.Context, Ex->getType()))
+      S.Diag(getLocationOfByte(CS.getStart()),
+             diag::warn_printf_conversion_argument_type_mismatch)
+        << ATR.getRepresentativeType(S.Context) << Ex->getType()
+        << getFormatSpecifierRange(startSpecifier, specifierLen)
+        << Ex->getSourceRange();
+
+    // Now type check the data expression that matches the
+    // format specifier.
+    Ex = getDataArg(argIndex + 1);
+    const analyze_printf::ArgTypeResult &ATR2 = ArgTypeResult::CStrTy;
+    if (ATR2.isValid() && !ATR2.matchesType(S.Context, Ex->getType()))
+      S.Diag(getLocationOfByte(CS.getStart()),
+             diag::warn_printf_conversion_argument_type_mismatch)
+        << ATR2.getRepresentativeType(S.Context) << Ex->getType()
+        << getFormatSpecifierRange(startSpecifier, specifierLen)
+        << Ex->getSourceRange();
+
+     return true;
+  }
+  // END OF FREEBSD EXTENSIONS
+
   // Check for using an Objective-C specific conversion specifier
   // in a non-ObjC literal.
   if (!IsObjCLiteral && CS.isObjCArg()) {
