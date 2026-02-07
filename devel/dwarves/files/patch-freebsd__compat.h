--- freebsd_compat.h.orig	2020-05-07 14:22:21 UTC
+++ freebsd_compat.h
@@ -0,0 +1,53 @@
+#pragma once
+
+#include <sys/cdefs.h>
+#include <sys/stat.h>
+#include <errno.h>
+#include <limits.h>
+#include <stdint.h>
+#include <stdlib.h>
+
+#include <libintl.h>
+
+/* asm/bitsperlong.h */
+/*
+ * In FreeBSD, __ILP32__ / __LP64__ are canonical, but gcc does not correctly
+ * emit __ILP32__ in 32-bit mode, at least on i386.
+ */
+#if __SIZEOF_LONG__ == 4 /* defined(__ILP32__) */
+#define	__BITS_PER_LONG	32
+#elif __SIZEOF_LONG__ == 8 /* defined(__LP64__) */
+#define	__BITS_PER_LONG	64
+#else
+#error "I'm a teapot"
+#endif
+
+/* asm/types.h */
+typedef uint8_t __u8;
+typedef uint16_t __u16;
+typedef uint32_t __u32;
+typedef uint64_t __u64;
+typedef int8_t __s8;
+typedef int16_t __s16;
+typedef int32_t __s32;
+typedef int64_t __s64;
+
+/* linux/types.h */
+typedef uint16_t __be16;
+typedef uint32_t __be32;
+typedef uint64_t __be64;
+typedef uint16_t __le16;
+typedef uint32_t __le32;
+typedef uint64_t __le64;
+#define	__aligned_u64	__u64 __attribute__((aligned(8)))
+
+/* "exitfail.h" */
+#define	exit_failure	EXIT_FAILURE
+
+/* search.h */
+static inline void
+tdestroy(void *vroot __unused, void (*freefct)(void *) __unused)
+{
+
+	/* XXX: Just leak the memory for now. */
+}
