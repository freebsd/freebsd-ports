--- source/utils/StackTraceUnix.cpp.orig	2016-08-24 19:52:29 UTC
+++ source/utils/StackTraceUnix.cpp
@@ -105,9 +105,9 @@ void StackTracePrintPrivateData::critErrHandler(int si
     sig_ucontext_t* uc = static_cast<sig_ucontext_t*>(ucontext);
 
 #if defined(__i386__) // gcc specific
-    caller_address = reinterpret_cast<void*>(uc->uc_mcontext.eip); // EIP: x86 specific
+    caller_address = reinterpret_cast<void*>(uc->uc_mcontext.sc_eip); // EIP: x86 specific
 #elif defined(__x86_64__) // gcc specific
-    caller_address = reinterpret_cast<void*>(uc->uc_mcontext.rip); // RIP: x86_64 specific
+    caller_address = reinterpret_cast<void*>(uc->uc_mcontext.sc_rip); // RIP: x86_64 specific
 #else
 #error Unsupported architecture. // TODO: Add support for other arch.
 #endif
