--- src/tup/platform.c.orig	2021-05-14 16:20:52 UTC
+++ src/tup/platform.c
@@ -58,6 +58,8 @@ const char *tup_arch = "arm64";
 const char *tup_arch = "arm";
 #elif __aarch64__
 const char *tup_arch = "arm64";
+#elif __riscv
+const char *tup_arch = "riscv";
 #else
 #error Unsupported cpu architecture. Please add support in tup/platform.c
 #endif
