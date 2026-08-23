--- utility/src/htslib/htscodecs/rANS_static4x16pr.c.orig	2024-12-09 07:24:48 UTC
+++ utility/src/htslib/htscodecs/rANS_static4x16pr.c
@@ -1021,12 +1021,14 @@ static inline int have_neon(void) {
     return (getauxval(AT_HWCAP) & HWCAP_ASIMD) != 0;
 #elif defined(__APPLE__)
     return 1;
+// The use of u_long is already eliminated in recent htslib.
+// This patch is only for bundled htslib here.
 #elif defined(__FreeBSD__) && defined(__arm__)
-    u_long cap;
+    unsigned long cap;
     if (elf_aux_info(AT_HWCAP, &cap, sizeof cap) != 0) return 0;
     return (cap & HWCAP_NEON) != 0;
 #elif defined(__FreeBSD__) && defined(__aarch64__)
-    u_long cap;
+    unsigned long cap;
     if (elf_aux_info(AT_HWCAP, &cap, sizeof cap) != 0) return 0;
     return (cap & HWCAP_ASIMD) != 0;
 #elif defined(_WIN32)
