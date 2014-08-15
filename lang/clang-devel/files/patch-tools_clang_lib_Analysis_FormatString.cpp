
$FreeBSD$

--- tools/clang/lib/Analysis/FormatString.cpp.orig
+++ tools/clang/lib/Analysis/FormatString.cpp
@@ -550,6 +550,9 @@
 
   // GlibC specific specifiers.
   case PrintErrno: return "m";
+
+  // FreeBSD specfic specifiers.
+  case bArg: return "b";
   }
   return nullptr;
 }
@@ -778,6 +781,7 @@
     case ConversionSpecifier::DArg:
     case ConversionSpecifier::OArg:
     case ConversionSpecifier::UArg:
+    case ConversionSpecifier::bArg:
       return false;
   }
   llvm_unreachable("Invalid ConversionSpecifier Kind!");
