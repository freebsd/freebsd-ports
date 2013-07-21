--- hphp/runtime/vm/jit/translator-x64.cpp.orig	2013-07-21 13:57:07.101533182 +0200
+++ hphp/runtime/vm/jit/translator-x64.cpp	2013-07-21 13:57:26.025419037 +0200
@@ -31,6 +31,7 @@
 
 #ifdef __FreeBSD__
 #define RIP_REGISTER(v) (v).mc_rip
+#include <sys/ucontext.h>
 #elif defined(__APPLE__)
 #define RIP_REGISTER(v) (v)->__ss.__rip
 #elif defined(__x86_64__)
