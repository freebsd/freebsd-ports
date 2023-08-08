Patch taken from the following commits:

- https://cgit.freebsd.org/src/commit/?id=7cafe89f9ce33effe6e471b185339d413da1ca46
- https://cgit.freebsd.org/src/commit/?id=930a7c2ac67e1e8e511aa1d0a31a16c632060ebb

--- libsanitizer/sanitizer_common/sanitizer_linux.cpp.orig	2022-11-26 10:40:30 UTC
+++ libsanitizer/sanitizer_common/sanitizer_linux.cpp
@@ -80,6 +80,7 @@
 
 #if SANITIZER_FREEBSD
 #include <sys/exec.h>
+#include <sys/procctl.h>
 #include <sys/sysctl.h>
 #include <machine/atomic.h>
 extern "C" {
@@ -2171,33 +2172,20 @@ void CheckASLR() {
     ReExec();
   }
 #elif SANITIZER_FREEBSD
-  int aslr_pie;
-  uptr len = sizeof(aslr_pie);
-#if SANITIZER_WORDSIZE == 64
-  if (UNLIKELY(internal_sysctlbyname("kern.elf64.aslr.pie_enable",
-      &aslr_pie, &len, NULL, 0) == -1)) {
-    // We're making things less 'dramatic' here since
-    // the OID is not necessarily guaranteed to be here
+  int aslr_status;                                                                             
+  if (UNLIKELY(procctl(P_PID, 0, PROC_ASLR_STATUS, &aslr_status) == -1)) {
+    // We're making things less 'dramatic' here since  
+    // the cmd is not necessarily guaranteed to be here
     // just yet regarding FreeBSD release
     return;
-  }
-
-  if (aslr_pie > 0) {
-    Printf("This sanitizer is not compatible with enabled ASLR "
-           "and binaries compiled with PIE\n");
-    Die();
-  }
-#endif
-  // there might be 32 bits compat for 64 bits
-  if (UNLIKELY(internal_sysctlbyname("kern.elf32.aslr.pie_enable",
-      &aslr_pie, &len, NULL, 0) == -1)) {
-    return;
-  }
-
-  if (aslr_pie > 0) {
-    Printf("This sanitizer is not compatible with enabled ASLR "
-           "and binaries compiled with PIE\n");
-    Die();
+  }                                            
+  if ((aslr_status & PROC_ASLR_ACTIVE) != 0) {                                                 
+    VReport(1, "This sanitizer is not compatible with enabled ASLR "
+               "and binaries compiled with PIE\n"                      
+               "ASLR will be disabled and the program re-executed.\n");
+    int aslr_ctl = PROC_ASLR_FORCE_DISABLE;                                                    
+    CHECK_NE(procctl(P_PID, 0, PROC_ASLR_CTL, &aslr_ctl), -1);
+    ReExec();
   }
 #else
   // Do nothing
