--- tools/clang/lib/Sema/SemaChecking.cpp.orig	2016-05-23 13:56:25 UTC
+++ tools/clang/lib/Sema/SemaChecking.cpp
@@ -38,6 +38,7 @@
 #include "llvm/ADT/SmallString.h"
 #include "llvm/Support/ConvertUTF.h"
 #include "llvm/Support/raw_ostream.h"
+#include <cstdio>
 #include <limits>
 using namespace clang;
 using namespace sema;
