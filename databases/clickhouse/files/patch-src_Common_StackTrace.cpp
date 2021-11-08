--- src/Common/StackTrace.cpp.orig	2021-09-13 15:30:01.608345000 +0200
+++ src/Common/StackTrace.cpp	2021-09-13 15:30:10.009331000 +0200
@@ -186,6 +186,8 @@ static void * getCallerAddress(const ucontext_t & context)
 #elif defined(__APPLE__) && defined(__aarch64__)
     return reinterpret_cast<void *>(context.uc_mcontext->__ss.__pc);
 
+#elif defined(__FreeBSD__) && defined(__aarch64__)
+    return reinterpret_cast<void *>(context.uc_mcontext.mc_gpregs.gp_elr);
 #elif defined(__aarch64__)
     return reinterpret_cast<void *>(context.uc_mcontext.pc);
 #elif defined(__powerpc64__)
