ISPC devs insist on using dump() functions which LLVM devs consider a debug functionality, and it isn't available in the LLVM packages.

--- src/opt.cpp.orig	2022-01-15 08:35:15 UTC
+++ src/opt.cpp
@@ -155,7 +155,7 @@ static llvm::Pass *CreateMangleOpenCLBuiltins();
                                                                        getenv("FUNC"), strlen(getenv("FUNC")))))) {    \
         fprintf(stderr, "Start of " NAME "\n");                                                                        \
         fprintf(stderr, "---------------\n");                                                                          \
-        bb.dump();                                                                                                     \
+        /*bb.dump();*/                                                                                                     \
         fprintf(stderr, "---------------\n\n");                                                                        \
     } else /* eat semicolon */
 
@@ -165,7 +165,7 @@ static llvm::Pass *CreateMangleOpenCLBuiltins();
                                                                        getenv("FUNC"), strlen(getenv("FUNC")))))) {    \
         fprintf(stderr, "End of " NAME " %s\n", modifiedAny ? "** CHANGES **" : "");                                   \
         fprintf(stderr, "---------------\n");                                                                          \
-        bb.dump();                                                                                                     \
+        /*bb.dump();*/                                                                                                     \
         fprintf(stderr, "---------------\n\n");                                                                        \
     } else /* eat semicolon */
 #else
@@ -467,7 +467,7 @@ void ispc::Optimize(llvm::Module *module, int optLevel
 #ifndef ISPC_NO_DUMPS
     if (g->debugPrint) {
         printf("*** Code going into optimization ***\n");
-        module->dump();
+        //module->dump();
     }
 #endif
     DebugPassManager optPM;
@@ -811,7 +811,7 @@ void ispc::Optimize(llvm::Module *module, int optLevel
 #ifndef ISPC_NO_DUMPS
     if (g->debugPrint) {
         printf("\n*****\nFINAL OUTPUT\n*****\n");
-        module->dump();
+        //module->dump();
     }
 #endif
 }
@@ -1933,11 +1933,11 @@ lExtractUniformsFromOffset(llvm::Value **basePtr, llvm
                            llvm::Value *offsetScale,
                            llvm::Instruction *insertBefore) {
 #if 1
-    (*basePtr)->dump();
+    //(*basePtr)->dump();
     printf("\n");
-    (*offsetVector)->dump();
+    //(*offsetVector)->dump();
     printf("\n");
-    offsetScale->dump();
+    //offsetScale->dump();
     printf("-----\n");
 #endif
 
@@ -4746,7 +4746,7 @@ char DebugPass::ID = 0;
 bool DebugPass::runOnModule(llvm::Module &module) {
     fprintf(stderr, "%s", str_output);
     fflush(stderr);
-    module.dump();
+    //module.dump();
     return true;
 }
 
