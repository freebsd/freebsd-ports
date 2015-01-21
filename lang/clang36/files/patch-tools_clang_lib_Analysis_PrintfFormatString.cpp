
$FreeBSD$

--- tools/clang/lib/Analysis/PrintfFormatString.cpp.orig
+++ tools/clang/lib/Analysis/PrintfFormatString.cpp
@@ -208,7 +208,7 @@
     case 'm': k = ConversionSpecifier::PrintErrno; break;
     // Apple-specific.
     case 'D':
-      if (Target.getTriple().isOSDarwin())
+      if (Target.getTriple().isOSDarwin() || Target.getTriple().isOSFreeBSD())
         k = ConversionSpecifier::DArg;
       break;
     case 'O':
@@ -219,6 +219,19 @@
       if (Target.getTriple().isOSDarwin())
         k = ConversionSpecifier::UArg;
       break;
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
     // MS specific.
     case 'Z':
       if (Target.getTriple().isOSMSVCRT())
@@ -228,6 +241,10 @@
   FS.setConversionSpecifier(CS);
   if (CS.consumesDataArgument() && !FS.usesPositionalArg())
     FS.setArgIndex(argIndex++);
+  // FreeBSD extension
+  if (Target.getTriple().isOSFreeBSD() && (k == ConversionSpecifier::bArg ||
+    k == ConversionSpecifier::DArg))
+      argIndex++;
 
   if (k == ConversionSpecifier::InvalidSpecifier) {
     // Assume the conversion takes one argument.
