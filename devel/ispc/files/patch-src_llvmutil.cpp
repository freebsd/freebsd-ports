ISPC devs insist on using dump() functions which LLVM devs consider a debug functionality, and it isn't available in the LLVM packages.

--- src/llvmutil.cpp.orig	2019-03-02 06:20:14 UTC
+++ src/llvmutil.cpp
@@ -1550,7 +1550,7 @@ lDumpValue(llvm::Value *v, std::set<llvm
         return;
 
     fprintf(stderr, "  ");
-    v->dump();
+    //v->dump();
     done.insert(v);
 
     if (inst == NULL)
