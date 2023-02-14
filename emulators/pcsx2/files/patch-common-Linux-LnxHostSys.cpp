--- common/Linux/LnxHostSys.cpp.orig	2023-02-10 03:43:10 UTC
+++ common/Linux/LnxHostSys.cpp
@@ -100,6 +100,8 @@ static void SysPageFaultSignalFilter(int signal, sigin
 
 #if defined(__APPLE__) && defined(__x86_64__)
 	void* const exception_pc = reinterpret_cast<void*>(static_cast<ucontext_t*>(ctx)->uc_mcontext->__ss.__rip);
+#elif defined(__FreeBSD__) && defined(__x86_64__)
+	void* const exception_pc = reinterpret_cast<void*>(static_cast<ucontext_t*>(ctx)->uc_mcontext.mc_rip);
 #elif defined(__x86_64__)
 	void* const exception_pc = reinterpret_cast<void*>(static_cast<ucontext_t*>(ctx)->uc_mcontext.gregs[REG_RIP]);
 #else
