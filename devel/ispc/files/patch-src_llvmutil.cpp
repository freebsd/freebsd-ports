ISPC devs insist on using dump() functions which LLVM devs consider a debug functionality, and it isn't available in the LLVM packages.

--- src/llvmutil.cpp.orig	2020-01-25 02:15:35 UTC
+++ src/llvmutil.cpp
@@ -1344,7 +1344,7 @@ static void lDumpValue(llvm::Value *v, std::set<llvm::
         return;
 
     fprintf(stderr, "  ");
-    v->dump();
+    //v->dump();
     done.insert(v);
 
     if (inst == NULL)
