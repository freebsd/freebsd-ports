ISPC devs insist on using dump() functions which LLVM devs consider a debug functionality, and it isn't available in the LLVM packages.

--- src/opt.cpp.orig	2019-03-02 06:22:00 UTC
+++ src/opt.cpp
@@ -173,7 +173,7 @@ static llvm::Pass *CreatePromoteLocalToP
                   strlen(getenv("FUNC"))))) {                           \
         fprintf(stderr, "Start of " NAME "\n");                \
         fprintf(stderr, "---------------\n");                  \
-        bb.dump();                                             \
+        /*bb.dump();*/                                             \
         fprintf(stderr, "---------------\n\n");                \
     } else /* eat semicolon */
 
@@ -184,7 +184,7 @@ static llvm::Pass *CreatePromoteLocalToP
                   strlen(getenv("FUNC"))))) {                           \
         fprintf(stderr, "End of " NAME " %s\n", modifiedAny ? "** CHANGES **" : ""); \
         fprintf(stderr, "---------------\n");                  \
-        bb.dump();                                             \
+        /*bb.dump();*/                                             \
         fprintf(stderr, "---------------\n\n");                \
     } else /* eat semicolon */
 
@@ -537,7 +537,7 @@ void
 Optimize(llvm::Module *module, int optLevel) {
     if (g->debugPrint) {
         printf("*** Code going into optimization ***\n");
-        module->dump();
+        //module->dump();
     }
     DebugPassManager optPM;
     optPM.add(llvm::createVerifierPass(),0);
@@ -932,7 +932,7 @@ Optimize(llvm::Module *module, int optLe
 
     if (g->debugPrint) {
         printf("\n*****\nFINAL OUTPUT\n*****\n");
-        module->dump();
+        //module->dump();
     }
 
 }
@@ -4895,7 +4895,7 @@ bool
 DebugPass::runOnModule(llvm::Module &module) {
     fprintf(stderr, "%s", str_output);
     fflush(stderr);
-    module.dump();
+    //module.dump();
     return true;
 }
 
