--- src/Compiler.h.orig	2017-01-27 07:46:51 UTC
+++ src/Compiler.h
@@ -86,7 +86,7 @@
 #define gcc_noreturn __attribute__((noreturn))
 #define gcc_packed __attribute__((packed))
 #define gcc_printf(a,b) __attribute__((format(printf, a, b)))
-#define gcc_pure __attribute__((pure))
+#define gcc_pure
 #define gcc_sentinel __attribute__((sentinel))
 #define gcc_unused __attribute__((unused))
 #define gcc_warn_unused_result __attribute__((warn_unused_result))
