--- third_party/boringssl/crypto/cpu-aarch64-linux.c.orig	2018-01-02 23:09:20 UTC
+++ third_party/boringssl/crypto/cpu-aarch64-linux.c
@@ -16,7 +16,42 @@
 
 #if defined(OPENSSL_AARCH64) && !defined(OPENSSL_STATIC_ARMCAP)
 
+#if __has_include(<sys/auxv.h>)
 #include <sys/auxv.h>
+#elif defined(__FreeBSD__)
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <elf.h>
+#include <errno.h>
+#include <unistd.h>
+
+#ifndef AT_HWCAP
+#define AT_HWCAP                25
+#endif
+
+static unsigned long getauxval(unsigned long type) {
+  Elf_Auxinfo auxv[AT_COUNT];
+  size_t len = sizeof(auxv);
+  int mib[] = {
+    CTL_KERN,
+    KERN_PROC,
+    KERN_PROC_AUXV,
+    getpid(),
+  };
+
+  if (sysctl(mib, nitems(mib), auxv, &len, NULL, 0) != -1) {
+    for (size_t i = 0; i < nitems(auxv); i++)
+      if ((unsigned long)auxv[i].a_type == type)
+        return auxv[i].a_un.a_val;
+
+    errno = ENOENT;
+  }
+  return 0;
+}
+#else
+#define AT_HWCAP                16
+#define getauxval(x)            0
+#endif /* <sys/auxv.h> */
 
 #include <openssl/arm_arch.h>
 
