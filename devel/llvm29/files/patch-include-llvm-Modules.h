--- include/llvm/Module.h.orig	Wed Mar  8 18:38:51 2006
+++ include/llvm/Module.h	Tue Aug  8 11:26:39 2006
@@ -24,6 +24,53 @@
 #include "llvm/ADT/SetVector.h"
 #include "llvm/Support/DataTypes.h"
 
+// Workarounds for FreeBSD 4
+#include <osreldate.h>
+#if __FreeBSD_version < 500000
+#ifndef INT8_MIN
+#define INT8_MIN        (-0x7f-1)
+#endif
+#ifndef INT16_MIN
+#define INT16_MIN       (-0x7fff-1)
+#endif
+#ifndef INT32_MIN
+#define INT32_MIN       (-0x7fffffff-1)
+#endif
+#ifndef INT64_MIN
+#define INT64_MIN       (-0x7fffffffffffffffL-1)
+#endif
+#ifndef INT8_MAX
+#define INT8_MAX        0x7f
+#endif
+#ifndef INT16_MAX
+#define INT16_MAX       0x7fff
+#endif
+#ifndef INT32_MAX
+#define INT32_MAX       0x7fffffff
+#endif
+#ifndef INT64_MAX
+#define INT64_MAX       0x7fffffffffffffffL
+#endif
+#ifndef UINT8_MAX
+#define UINT8_MAX       0xff
+#endif
+#ifndef UINT16_MAX
+#define UINT16_MAX      0xffff
+#endif
+#ifndef UINT32_MAX
+#define UINT32_MAX      0xffffffffU
+#endif
+#ifndef UINT64_MAX
+#define UINT64_MAX      0xffffffffffffffffUL
+#endif
+
+static inline long long
+llabs(long long x)
+{
+	return x > 0 ? x : -x;
+}
+#endif
+
 namespace llvm {
 
 class GlobalVariable;
