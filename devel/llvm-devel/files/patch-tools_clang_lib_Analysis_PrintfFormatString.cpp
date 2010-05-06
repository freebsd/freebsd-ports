
$FreeBSD$

--- tools/clang/lib/Analysis/PrintfFormatString.cpp.orig
+++ tools/clang/lib/Analysis/PrintfFormatString.cpp
@@ -369,11 +369,19 @@
     case '@': k = ConversionSpecifier::ObjCObjArg; break;
     // Glibc specific.
     case 'm': k = ConversionSpecifier::PrintErrno; break;
+    // FreeBSD format extensions
+    case 'b': k = ConversionSpecifier::bArg; break; /* check for int and then char * */
+    case 'r': k = ConversionSpecifier::xArg; break;
+    case 'y': k = ConversionSpecifier::iArg; break;
+    case 'D': k = ConversionSpecifier::DArg; break; /* check for u_char * pointer and a char * string */
   }
   ConversionSpecifier CS(conversionPosition, k);
   FS.setConversionSpecifier(CS);
   if (CS.consumesDataArgument() && !FS.usesPositionalArg())
     FS.setArgIndex(argIndex++);
+  // FreeBSD extension
+  if (k == ConversionSpecifier::bArg || k == ConversionSpecifier::DArg)
+    argIndex++;
 
   if (k == ConversionSpecifier::InvalidSpecifier) {
     // Assume the conversion takes one argument.
