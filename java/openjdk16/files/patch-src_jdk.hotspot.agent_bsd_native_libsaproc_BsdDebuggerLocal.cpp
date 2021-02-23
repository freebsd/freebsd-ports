--- src/jdk.hotspot.agent/bsd/native/libsaproc/BsdDebuggerLocal.cpp
+++ src/jdk.hotspot.agent/bsd/native/libsaproc/BsdDebuggerLocal.cpp
@@ -35,7 +35,11 @@
 #define amd64 1
 #endif
 
-#ifdef i386
+#if defined(i386) && !defined(i586)
+#define i586 1
+#endif
+
+#ifdef i586
 #include "sun_jvm_hotspot_debugger_x86_X86ThreadContext.h"
 #endif
 
@@ -43,10 +47,6 @@
 #include "sun_jvm_hotspot_debugger_amd64_AMD64ThreadContext.h"
 #endif
 
-#if defined(sparc) || defined(sparcv9)
-#include "sun_jvm_hotspot_debugger_sparc_SPARCThreadContext.h"
-#endif
-
 #if defined(ppc64) || defined(ppc64le)
 #include "sun_jvm_hotspot_debugger_ppc64_PPC64ThreadContext.h"
 #endif
@@ -319,6 +319,7 @@ JNIEXPORT jbyteArray JNICALL Java_sun_jvm_hotspot_debugger_bsd_BsdDebuggerLocal_
   return (err == PS_OK)? array : 0;
 }
 
+#if defined(i586) || defined(amd64) || defined(ppc64) || defined(ppc64le) || defined(aarch64)
 extern "C"
 JNIEXPORT jlongArray JNICALL Java_sun_jvm_hotspot_debugger_bsd_BsdDebuggerLocal_getThreadIntegerRegisterSet0
   (JNIEnv *env, jobject this_obj, jint lwp_id) {
@@ -340,21 +341,19 @@ JNIEXPORT jlongArray JNICALL Java_sun_jvm_hotspot_debugger_bsd_BsdDebuggerLocal_
   }
 
 #undef NPRGREG
-#ifdef i386
+#ifdef i586
 #define NPRGREG sun_jvm_hotspot_debugger_x86_X86ThreadContext_NPRGREG
 #endif
 #ifdef amd64
 #define NPRGREG sun_jvm_hotspot_debugger_amd64_AMD64ThreadContext_NPRGREG
 #endif
-#if defined(sparc) || defined(sparcv9)
-#define NPRGREG sun_jvm_hotspot_debugger_sparc_SPARCThreadContext_NPRGREG
+#ifdef aarch64
+#define NPRGREG sun_jvm_hotspot_debugger_aarch64_AARCH64ThreadContext_NPRGREG
 #endif
 #if defined(ppc64) || defined(ppc64le)
 #define NPRGREG sun_jvm_hotspot_debugger_ppc64_PPC64ThreadContext_NPRGREG
 #endif
-#ifdef aarch64
-#define NPRGREG sun_jvm_hotspot_debugger_aarch64_AARCH64ThreadContext_NPRGREG
-#endif
+
 
   array = env->NewLongArray(NPRGREG);
   CHECK_EXCEPTION_(0);
@@ -362,7 +361,7 @@ JNIEXPORT jlongArray JNICALL Java_sun_jvm_hotspot_debugger_bsd_BsdDebuggerLocal_
 
 #undef REG_INDEX
 
-#ifdef i386
+#ifdef i586
 #define REG_INDEX(reg) sun_jvm_hotspot_debugger_x86_X86ThreadContext_##reg
 
   regs[REG_INDEX(GS)]  = (uintptr_t) gregs.r_gs;
@@ -381,7 +380,7 @@ JNIEXPORT jlongArray JNICALL Java_sun_jvm_hotspot_debugger_bsd_BsdDebuggerLocal_
   regs[REG_INDEX(CS)]  = (uintptr_t) gregs.r_cs;
   regs[REG_INDEX(SS)]  = (uintptr_t) gregs.r_ss;
 
-#endif /* i386 */
+#endif /* i586 */
 
 #ifdef amd64
 #define REG_INDEX(reg) sun_jvm_hotspot_debugger_amd64_AMD64ThreadContext_##reg
@@ -420,38 +419,19 @@ JNIEXPORT jlongArray JNICALL Java_sun_jvm_hotspot_debugger_bsd_BsdDebuggerLocal_
 
 #endif /* amd64 */
 
-#if defined(sparc) || defined(sparcv9)
+#if defined(aarch64)
 
-#define REG_INDEX(reg) sun_jvm_hotspot_debugger_sparc_SPARCThreadContext_##reg
+#define REG_INDEX(reg) sun_jvm_hotspot_debugger_aarch64_AARCH64ThreadContext_##reg
+
+  {
+    int i;
+    for (i = 0; i < 31; i++)
+      regs[i] = gregs.x[i];
+    regs[REG_INDEX(SP)] = gregs.sp;
+    regs[REG_INDEX(PC)] = gregs.elr;
+  }
+#endif /* aarch64 */
 
-#ifdef _LP64
-  regs[REG_INDEX(R_PSR)] = gregs.tstate;
-  regs[REG_INDEX(R_PC)]  = gregs.tpc;
-  regs[REG_INDEX(R_nPC)] = gregs.tnpc;
-  regs[REG_INDEX(R_Y)]   = gregs.y;
-#else
-  regs[REG_INDEX(R_PSR)] = gregs.psr;
-  regs[REG_INDEX(R_PC)]  = gregs.pc;
-  regs[REG_INDEX(R_nPC)] = gregs.npc;
-  regs[REG_INDEX(R_Y)]   = gregs.y;
-#endif
-  regs[REG_INDEX(R_G0)]  =            0 ;
-  regs[REG_INDEX(R_G1)]  = gregs.u_regs[0];
-  regs[REG_INDEX(R_G2)]  = gregs.u_regs[1];
-  regs[REG_INDEX(R_G3)]  = gregs.u_regs[2];
-  regs[REG_INDEX(R_G4)]  = gregs.u_regs[3];
-  regs[REG_INDEX(R_G5)]  = gregs.u_regs[4];
-  regs[REG_INDEX(R_G6)]  = gregs.u_regs[5];
-  regs[REG_INDEX(R_G7)]  = gregs.u_regs[6];
-  regs[REG_INDEX(R_O0)]  = gregs.u_regs[7];
-  regs[REG_INDEX(R_O1)]  = gregs.u_regs[8];
-  regs[REG_INDEX(R_O2)]  = gregs.u_regs[ 9];
-  regs[REG_INDEX(R_O3)]  = gregs.u_regs[10];
-  regs[REG_INDEX(R_O4)]  = gregs.u_regs[11];
-  regs[REG_INDEX(R_O5)]  = gregs.u_regs[12];
-  regs[REG_INDEX(R_O6)]  = gregs.u_regs[13];
-  regs[REG_INDEX(R_O7)]  = gregs.u_regs[14];
-#endif /* sparc */
 #if defined(ppc64) || defined(ppc64le)
 #define REG_INDEX(reg) sun_jvm_hotspot_debugger_ppc64_PPC64ThreadContext_##reg
 
@@ -491,23 +471,11 @@ JNIEXPORT jlongArray JNICALL Java_sun_jvm_hotspot_debugger_bsd_BsdDebuggerLocal_
   regs[REG_INDEX(R31)] = gregs.fixreg[31];
 
 #endif /* ppc64 */
-#if defined(aarch64)
-
-#define REG_INDEX(reg) sun_jvm_hotspot_debugger_aarch64_AARCH64ThreadContext_##reg
-
-  {
-    int i;
-    for (i = 0; i < 31; i++)
-      regs[i] = gregs.x[i];
-    regs[REG_INDEX(SP)] = gregs.sp;
-    regs[REG_INDEX(PC)] = gregs.elr;
-  }
-#endif /* aarch64 */
-
 
   env->ReleaseLongArrayElements(array, regs, JNI_COMMIT);
   return array;
 }
+#endif
 
 /*
  * Class:     sun_jvm_hotspot_debugger_bsd_BsdDebuggerLocal
