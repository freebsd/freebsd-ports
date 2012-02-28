--- ./software/crash_handling/CrashHandling.cpp.orig	2012-02-24 13:54:53.000000000 +0100
+++ ./software/crash_handling/CrashHandling.cpp	2012-02-24 15:15:51.000000000 +0100
@@ -31,11 +31,11 @@
 /*
   Linux/MacOS-specific handling
  */
-#if defined(__linux) || defined(__APPLE__)
+#if defined(__linux) || defined(__APPLE__) || defined(__FreeBSD__)
 
 #include "UnixSignalInterposer.h"
 
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #include <sys/ucontext.h>
 #else
 
@@ -54,7 +54,17 @@
 
   // Get the address at the time the signal was raised from the EIP (x86) or RIP (x86_64)
 
-#ifndef __APPLE__
+#ifdef __FreeBSD__
+
+  ucontext_t * uc = reinterpret_cast<ucontext_t *>(ucontext);
+#ifndef I64
+  void *callerAddress = reinterpret_cast<void *>(uc->uc_mcontext.mc_eip);
+#else
+  void *callerAddress = reinterpret_cast<void *>(uc->uc_mcontext.mc_rip);
+#endif
+
+#else
+#ifndef (__APPLE__)
 
   sig_ucontext_t * uc = reinterpret_cast<sig_ucontext_t *>(ucontext);
 #ifdef I64
@@ -73,6 +83,7 @@
 #endif
 
 #endif
+#endif
 
   std::cerr << TLP_PLATEFORM_HEADER << " " << OS_PLATFORM << std::endl
             << TLP_ARCH_HEADER << " "  << OS_ARCHITECTURE << std::endl
