
$FreeBSD$

--- tools/clang/lib/Analysis/PrintfFormatString.cpp.orig
+++ tools/clang/lib/Analysis/PrintfFormatString.cpp
@@ -198,9 +198,10 @@
     case '@': k = ConversionSpecifier::ObjCObjArg; break;
     // Glibc specific.
     case 'm': k = ConversionSpecifier::PrintErrno; break;
-    // Apple-specific
+
+    // Apple-specific (and one FreeBSD)
     case 'D':
-      if (Target.getTriple().isOSDarwin())
+      if (Target.getTriple().isOSDarwin() || Target.getTriple().isOSFreeBSD())
         k = ConversionSpecifier::DArg;
       break;
     case 'O':
@@ -211,11 +212,29 @@
       if (Target.getTriple().isOSDarwin())
         k = ConversionSpecifier::UArg;
       break;
+
+    // FreeBSD-specific
+    case 'b':
+      if (Target.getTriple().isOSFreeBSD())
+        k = ConversionSpecifier::bArg;
+      break;
+    case 'r':
+      if (Target.getTriple().isOSFreeBSD())
+        k = ConversionSpecifier::xArg;
+      break;
+    case 'y':
+      if (Target.getTriple().isOSFreeBSD())
+        k = ConversionSpecifier::iArg;
+      break;
   }
   PrintfConversionSpecifier CS(conversionPosition, k);
   FS.setConversionSpecifier(CS);
   if (CS.consumesDataArgument() && !FS.usesPositionalArg())
     FS.setArgIndex(argIndex++);
+  // FreeBSD extension
+  if (Target.getTriple().isOSFreeBSD() && (k == ConversionSpecifier::bArg ||
+    k == ConversionSpecifier::DArg))
+      argIndex++;
 
   if (k == ConversionSpecifier::InvalidSpecifier) {
     // Assume the conversion takes one argument.
