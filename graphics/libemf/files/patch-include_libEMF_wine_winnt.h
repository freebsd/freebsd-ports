--- include/libEMF/wine/winnt.h.orig	2012-11-06 12:40:59 UTC
+++ include/libEMF/wine/winnt.h
@@ -57,6 +57,22 @@
 # define WORDS_BIGENDIAN
 # define BITFIELDS_BIGENDIAN
 # undef  ALLOW_UNALIGNED_ACCESS
+#elif defined(__AARCH64EB__)
+# define WORDS_BIGENDIAN
+# define BITFIELDS_BIGENDIAN
+# undef  ALLOW_UNALIGNED_ACCESS
+#elif defined(__AARCH64EL__) || defined(__aarch64__)
+# undef  WORDS_BIGENDIAN
+# undef  BITFIELDS_BIGENDIAN
+# undef  ALLOW_UNALIGNED_ACCESS
+#elif defined(__MIPSEB__)
+# define WORDS_BIGENDIAN
+# define BITFIELDS_BIGENDIAN
+# undef  ALLOW_UNALIGNED_ACCESS
+#elif defined(__MIPSEL__)
+# undef  WORDS_BIGENDIAN
+# undef  BITFIELDS_BIGENDIAN
+# undef  ALLOW_UNALIGNED_ACCESS
 #elif !defined(RC_INVOKED)
 # error Unknown CPU architecture!
 #endif
@@ -1425,6 +1441,176 @@ ULONG Cpsr;
 
 #endif /* __arm__ */
 
+#ifdef __aarch64__
+/*
+ * FIXME:
+ *
+ * There is not yet an official CONTEXT structure defined for the AArch64
+ * architecture, so I just made one up.
+ *
+ */
+
+#define CONTEXT_ARM64           0x400000
+#define CONTEXT_CONTROL         (CONTEXT_ARM64 | 0x00000001)
+#define CONTEXT_INTEGER         (CONTEXT_ARM64 | 0x00000002)
+#define CONTEXT_FLOATING_POINT  (CONTEXT_ARM64 | 0x00000004)
+#define CONTEXT_DEBUG_REGISTERS (CONTEXT_ARM64 | 0x00000008)
+
+#define CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_INTEGER)
+
+#define EXCEPTION_READ_FAULT    0
+#define EXCEPTION_WRITE_FAULT   1
+#define EXCEPTION_EXECUTE_FAULT 8
+
+typedef struct _CONTEXT {
+    ULONG ContextFlags;
+    ULONG Cpsr;
+
+    /* This section is specified/returned if the ContextFlags word contains
+       the flag CONTEXT_INTEGER. */
+    ULONGLONG X0;
+    ULONGLONG X1;
+    ULONGLONG X2;
+    ULONGLONG X3;
+    ULONGLONG X4;
+    ULONGLONG X5;
+    ULONGLONG X6;
+    ULONGLONG X7;
+    ULONGLONG X8;
+    ULONGLONG X9;
+    ULONGLONG X10;
+    ULONGLONG X11;
+    ULONGLONG X12;
+    ULONGLONG X13;
+    ULONGLONG X14;
+    ULONGLONG X15;
+    ULONGLONG X16;
+    ULONGLONG X17;
+    ULONGLONG X18;
+    ULONGLONG X19;
+    ULONGLONG X20;
+    ULONGLONG X21;
+    ULONGLONG X22;
+    ULONGLONG X23;
+    ULONGLONG X24;
+    ULONGLONG X25;
+    ULONGLONG X26;
+    ULONGLONG X27;
+    ULONGLONG X28;
+
+    /* These are selected by CONTEXT_CONTROL */
+    ULONGLONG Fp;
+    ULONGLONG Lr;
+    ULONGLONG Sp;
+    ULONGLONG Pc;
+
+    /* These are selected by CONTEXT_FLOATING_POINT */
+    /* FIXME */
+} CONTEXT;
+
+#endif /* __aarch64__ */
+
+/* Mips context definitions */
+#if defined(_MIPS_) || defined(__MIPS__) || defined(__mips__)
+
+#define CONTEXT_R4000   0x00010000
+
+#define CONTEXT_CONTROL         (CONTEXT_R4000 | 0x00000001)
+#define CONTEXT_FLOATING_POINT  (CONTEXT_R4000 | 0x00000002)
+#define CONTEXT_INTEGER         (CONTEXT_R4000 | 0x00000004)
+
+#define CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_FLOATING_POINT | CONTEXT_INTEGER)
+
+#define EXCEPTION_READ_FAULT    0
+#define EXCEPTION_WRITE_FAULT   1
+#define EXCEPTION_EXECUTE_FAULT 8
+
+typedef struct _CONTEXT
+{
+    DWORD Argument[4];
+    /* These are selected by CONTEXT_FLOATING_POINT */
+    DWORD FltF0;
+    DWORD FltF1;
+    DWORD FltF2;
+    DWORD FltF3;
+    DWORD FltF4;
+    DWORD FltF5;
+    DWORD FltF6;
+    DWORD FltF7;
+    DWORD FltF8;
+    DWORD FltF9;
+    DWORD FltF10;
+    DWORD FltF11;
+    DWORD FltF12;
+    DWORD FltF13;
+    DWORD FltF14;
+    DWORD FltF15;
+    DWORD FltF16;
+    DWORD FltF17;
+    DWORD FltF18;
+    DWORD FltF19;
+    DWORD FltF20;
+    DWORD FltF21;
+    DWORD FltF22;
+    DWORD FltF23;
+    DWORD FltF24;
+    DWORD FltF25;
+    DWORD FltF26;
+    DWORD FltF27;
+    DWORD FltF28;
+    DWORD FltF29;
+    DWORD FltF30;
+    DWORD FltF31;
+
+    /* These are selected by CONTEXT_INTEGER */
+    DWORD IntZero;
+    DWORD IntAt;
+    DWORD IntV0;
+    DWORD IntV1;
+    DWORD IntA0;
+    DWORD IntA1;
+    DWORD IntA2;
+    DWORD IntA3;
+    DWORD IntT0;
+    DWORD IntT1;
+    DWORD IntT2;
+    DWORD IntT3;
+    DWORD IntT4;
+    DWORD IntT5;
+    DWORD IntT6;
+    DWORD IntT7;
+    DWORD IntS0;
+    DWORD IntS1;
+    DWORD IntS2;
+    DWORD IntS3;
+    DWORD IntS4;
+    DWORD IntS5;
+    DWORD IntS6;
+    DWORD IntS7;
+    DWORD IntT8;
+    DWORD IntT9;
+    DWORD IntK0;
+    DWORD IntK1;
+    DWORD IntGp;
+    DWORD IntSp;
+    DWORD IntS8;
+    DWORD IntRa;
+    DWORD IntLo;
+    DWORD IntHi;
+
+    /* These are selected by CONTEXT_FLOATING_POINT */
+    DWORD Fsr;
+
+    /* These are selected by CONTEXT_CONTROL */
+    DWORD Fir;
+    DWORD Psr;
+
+    DWORD ContextFlags;
+    DWORD Fill[2];
+} CONTEXT;
+
+#endif  /* _MIPS_ */
+
 #if !defined(CONTEXT_FULL) && !defined(RC_INVOKED)
 #error You need to define a CONTEXT for your CPU
 #endif
