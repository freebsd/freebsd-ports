ISPC devs insist on using dump() functions which LLVM devs consider a debug functionality, and it isn't available in the LLVM packages.

--- src/opt.cpp.orig	2020-01-25 02:15:35 UTC
+++ src/opt.cpp
@@ -144,7 +144,7 @@ static llvm::Pass *CreateFixBooleanSelectPass();
                                                                        getenv("FUNC"), strlen(getenv("FUNC")))))) {    \
         fprintf(stderr, "Start of " NAME "\n");                                                                        \
         fprintf(stderr, "---------------\n");                                                                          \
-        bb.dump();                                                                                                     \
+        /*bb.dump();*/                                                                                                     \
         fprintf(stderr, "---------------\n\n");                                                                        \
     } else /* eat semicolon */
 
@@ -154,7 +154,7 @@ static llvm::Pass *CreateFixBooleanSelectPass();
                                                                        getenv("FUNC"), strlen(getenv("FUNC")))))) {    \
         fprintf(stderr, "End of " NAME " %s\n", modifiedAny ? "** CHANGES **" : "");                                   \
         fprintf(stderr, "---------------\n");                                                                          \
-        bb.dump();                                                                                                     \
+        /*bb.dump();*/                                                                                                     \
         fprintf(stderr, "---------------\n\n");                                                                        \
     } else /* eat semicolon */
 #else
@@ -442,7 +442,7 @@ void Optimize(llvm::Module *module, int optLevel) {
 #ifndef ISPC_NO_DUMPS
     if (g->debugPrint) {
         printf("*** Code going into optimization ***\n");
-        module->dump();
+        //module->dump();
     }
 #endif
     DebugPassManager optPM;
@@ -655,7 +655,7 @@ void Optimize(llvm::Module *module, int optLevel) {
 #ifndef ISPC_NO_DUMPS
     if (g->debugPrint) {
         printf("\n*****\nFINAL OUTPUT\n*****\n");
-        module->dump();
+        //module->dump();
     }
 #endif
 }
@@ -1728,11 +1728,11 @@ lExtractUniformsFromOffset(llvm::Value **basePtr, llvm
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
 
@@ -4217,7 +4217,7 @@ char DebugPass::ID = 0;
 bool DebugPass::runOnModule(llvm::Module &module) {
     fprintf(stderr, "%s", str_output);
     fflush(stderr);
-    module.dump();
+    //module.dump();
     return true;
 }
 
@@ -4687,7 +4687,13 @@ void DebugPassFile::run(llvm::Module &module, bool init)
     std::error_code EC;
     char fname[100];
     snprintf(fname, sizeof(fname), "%s_%d_%s.ll", init ? "init" : "ir", pnum, sanitize(std::string(pname)).c_str());
-    llvm::raw_fd_ostream OS(fname, EC, llvm::sys::fs::F_None);
+    llvm::raw_fd_ostream OS(fname, EC,
+#if ISPC_LLVM_VERSION >= ISPC_LLVM_13_0
+                                       llvm::sys::fs::OF_None
+#else
+                                       llvm::sys::fs::F_None
+#endif
+    );
     Assert(!EC && "IR dump file creation failed!");
     module.print(OS, 0);
 }
