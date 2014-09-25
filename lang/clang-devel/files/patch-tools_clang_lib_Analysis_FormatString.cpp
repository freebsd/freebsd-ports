
$FreeBSD$

--- tools/clang/lib/Analysis/FormatString.cpp.orig
+++ tools/clang/lib/Analysis/FormatString.cpp
@@ -557,6 +557,9 @@
 
   // MS specific specifiers.
   case ZArg: return "Z";
+
+  // FreeBSD specfic specifiers.
+  case bArg: return "b";
   }
   return nullptr;
 }
@@ -812,6 +815,7 @@
     case ConversionSpecifier::OArg:
     case ConversionSpecifier::UArg:
     case ConversionSpecifier::ZArg:
+    case ConversionSpecifier::bArg:
       return false;
   }
   llvm_unreachable("Invalid ConversionSpecifier Kind!");
