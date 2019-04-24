ISPC devs insist on using dump() functions which LLVM devs consider a debug functionality, and it isn't available in the LLVM packages.

--- src/opt.cpp.orig	2019-03-02 06:22:00 UTC
--- src/opt.cpp.orig	2019-04-20 16:07:05 UTC
+++ src/opt.cpp
@@ -175,7 +175,7 @@ static llvm::Pass *CreatePromoteLocalToP
                                                                        getenv("FUNC"), strlen(getenv("FUNC")))))) {    \
         fprintf(stderr, "Start of " NAME "\n");                                                                        \
         fprintf(stderr, "---------------\n");                                                                          \
-        bb.dump();                                                                                                     \
+        /*bb.dump();*/                                                                                                     \
         fprintf(stderr, "---------------\n\n");                                                                        \
     } else /* eat semicolon */
 
@@ -185,7 +185,7 @@ static llvm::Pass *CreatePromoteLocalToP
                                                                        getenv("FUNC"), strlen(getenv("FUNC")))))) {    \
         fprintf(stderr, "End of " NAME " %s\n", modifiedAny ? "** CHANGES **" : "");                                   \
         fprintf(stderr, "---------------\n");                                                                          \
-        bb.dump();                                                                                                     \
+        /*bb.dump();*/                                                                                                     \
         fprintf(stderr, "---------------\n\n");                                                                        \
     } else /* eat semicolon */
 #else
@@ -505,7 +505,7 @@ void Optimize(llvm::Module *module, int 
 #ifndef ISPC_NO_DUMPS
     if (g->debugPrint) {
         printf("*** Code going into optimization ***\n");
-        module->dump();
+        //module->dump();
     }
 #endif
     DebugPassManager optPM;
@@ -892,7 +892,7 @@ void Optimize(llvm::Module *module, int 
 #ifndef ISPC_NO_DUMPS
     if (g->debugPrint) {
         printf("\n*****\nFINAL OUTPUT\n*****\n");
-        module->dump();
+        //module->dump();
     }
 #endif
 }
@@ -1944,11 +1944,11 @@ lExtractUniformsFromOffset(llvm::Value *
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
 
@@ -4394,7 +4394,7 @@ char DebugPass::ID = 0;
 bool DebugPass::runOnModule(llvm::Module &module) {
     fprintf(stderr, "%s", str_output);
     fflush(stderr);
-    module.dump();
+    //module.dump();
     return true;
 }
 
