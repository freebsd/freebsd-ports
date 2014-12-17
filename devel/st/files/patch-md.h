--- md.h	2009-10-01 20:46:43.000000000 +0200
+++ md.h	2014-12-16 22:52:34.000000000 +0100
@@ -161,6 +161,19 @@
 #define MD_JB_SP  34
 #elif defined(__amd64__)
 #define MD_JB_SP   2
+/*
+ * The following comment is taken from src/lib/libc/amd64/gen/makecontext.c
+ * It explains why we specifically break the alignment to 64 byte boundary
+ * that is unconditionally enforced by sched.c, by setting MD_STACK_PAD_SIZE
+ * to this funky value.
+ * Without this, anything using va_start() & friends fails unpredictably.
+ */
+        /*
+         * Account for arguments on stack and do the funky C entry alignment.
+         * This means that we need an 8-byte-odd alignment since the ABI expects
+         * the return address to be pushed, thus breaking the 16 byte alignment.
+         */
+#define MD_STACK_PAD_SIZE 8
 #else
 #error Unknown CPU architecture
 #endif
