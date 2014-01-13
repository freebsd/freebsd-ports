--- jfsw_src_20051009/source/jaudiolib/platform.h.orig	1970-01-01 01:00:00.000000000 +0100
+++ jfsw_src_20051009/source/jaudiolib/platform.h	2005-10-10 15:02:08.000000000 +0200
@@ -0,0 +1,60 @@
+#ifndef _INCLUDE_PLATFORM_H_
+#define _INCLUDE_PLATFORM_H_
+
+#if (!defined __EXPORT__)
+#define __EXPORT__
+#endif
+
+#if (defined __WATCOMC__)
+#define snprintf _snprintf
+#endif
+
+static __inline unsigned short _swap16(unsigned short D)
+{
+#if PLATFORM_MACOSX
+    register unsigned short returnValue;
+    __asm__ volatile("lhbrx %0,0,%1"
+        : "=r" (returnValue)
+        : "r" (&D)
+    );
+    return returnValue;
+#else
+    return((D<<8)|(D>>8));
+#endif
+}
+
+static __inline unsigned int _swap32(unsigned int D)
+{
+#if PLATFORM_MACOSX
+    register unsigned int returnValue;
+    __asm__ volatile("lwbrx %0,0,%1"
+        : "=r" (returnValue)
+        : "r" (&D)
+    );
+    return returnValue;
+#else
+    return((D<<24)|((D<<8)&0x00FF0000)|((D>>8)&0x0000FF00)|(D>>24));
+#endif
+}
+
+#if PLATFORM_MACOSX
+#define PLATFORM_BIGENDIAN 1
+#define BUILDSWAP_INTEL16(x) _swap16(x)
+#define BUILDSWAP_INTEL32(x) _swap32(x)
+#else
+#if __BYTE_ORDER == __LITTLE_ENDIAN
+#define PLATFORM_LITTLEENDIAN 1
+#define BUILDSWAP_INTEL16(x) (x)
+#define BUILDSWAP_INTEL32(x) (x)
+#else
+#define PLATFORM_BIGENDIAN 1
+#define BUILDSWAP_INTEL16(x) _swap16(x)
+#define BUILDSWAP_INTEL32(x) _swap32(x)
+#endif
+#endif
+
+extern int has_altivec;  /* PowerPC-specific. */
+
+#endif  /* !defined _INCLUDE_PLATFORM_H_ */
+
+/* end of platform.h ... */
