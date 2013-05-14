
$FreeBSD$

--- tools/clang/lib/Basic/Targets.cpp.orig
+++ tools/clang/lib/Basic/Targets.cpp
@@ -271,6 +271,8 @@
           break;
         case llvm::Triple::mips:
         case llvm::Triple::mipsel:
+        case llvm::Triple::mips64:
+        case llvm::Triple::mips64el:
         case llvm::Triple::ppc:
         case llvm::Triple::ppc64:
           this->MCountName = "_mcount";
