--- include/libEMF/wine/winnt.h.orig	2022-10-27 16:15:39 UTC
+++ include/libEMF/wine/winnt.h
@@ -69,6 +69,10 @@
 # define  WORDS_BIGENDIAN
 # define  BITFIELDS_BIGENDIAN
 # undef  ALLOW_UNALIGNED_ACCESS
+#elif defined(__riscv)
+# undef  WORDS_BIGENDIAN
+# undef  BITFIELDS_BIGENDIAN
+# define ALLOW_UNALIGNED_ACCESS
 #elif !defined(RC_INVOKED)
 # error Unknown CPU architecture!
 #endif
@@ -1581,6 +1585,71 @@ typedef struct _CONTEXT {
 } CONTEXT;
 
 #endif /* __e2k__ */
+
+#if __riscv_xlen == 64
+/*
+ * FIXME:
+ *
+ * There is not yet an official CONTEXT structure defined for 
+ * RV64, so I just made one up.
+ *
+ */
+
+#define CONTEXT_RV64            0x4000000
+#define CONTEXT_CONTROL         (CONTEXT_RV64 | 0x00000001)
+#define CONTEXT_INTEGER         (CONTEXT_RV64 | 0x00000002)
+#define CONTEXT_FLOATING_POINT  (CONTEXT_RV64 | 0x00000004)
+
+#define CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_POINT)
+
+#define EXCEPTION_READ_FAULT    0
+#define EXCEPTION_WRITE_FAULT   1
+#define EXCEPTION_EXECUTE_FAULT 8
+
+typedef struct _CONTEXT {
+    ULONG ContextFlags;
+
+    /* This section is specified/returned if the ContextFlags word contains
+       the flag CONTEXT_INTEGER. */
+    ULONGLONG R1;
+    ULONGLONG R2;
+    ULONGLONG R3;
+    ULONGLONG R4;
+    ULONGLONG R5;
+    ULONGLONG R6;
+    ULONGLONG R7;
+    ULONGLONG R8;
+    ULONGLONG R9;
+    ULONGLONG R10;
+    ULONGLONG R12;
+    ULONGLONG R13;
+    ULONGLONG R14;
+    ULONGLONG R15;
+    ULONGLONG R16;
+    ULONGLONG R17;
+    ULONGLONG R18;
+    ULONGLONG R19;
+    ULONGLONG R20;
+    ULONGLONG R21;
+    ULONGLONG R22;
+    ULONGLONG R23;
+    ULONGLONG R24;
+    ULONGLONG R25;
+    ULONGLONG R26;
+    ULONGLONG R27;
+    ULONGLONG R28;
+    ULONGLONG R29;
+    ULONGLONG R30;
+    ULONGLONG R31;
+
+    /* These are selected by CONTEXT_CONTROL */
+    ULONGLONG Pc;
+
+    /* These are selected by CONTEXT_FLOATING_POINT */
+
+} CONTEXT;
+
+#endif /* __riscv */
 
 #if !defined(CONTEXT_FULL) && !defined(RC_INVOKED)
 #error You need to define a CONTEXT for your CPU
