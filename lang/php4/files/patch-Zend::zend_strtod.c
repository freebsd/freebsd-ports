--- Zend/zend_strtod.c.orig	2004/12/14 08:35:26
+++ Zend/zend_strtod.c	2004/12/21 01:08:09
@@ -91,22 +91,21 @@

 #include <zend_strtod.h>

-#if defined(LIBC_SCCS) && !defined(lint)
-static char *rcsid = "$OpenBSD: strtod.c,v 1.19 2004/02/03 16:52:11 drahn Exp $";
-#endif /* LIBC_SCCS and not lint */
-
-#if defined(__m68k__) || defined(__sparc__) || defined(__i386__) || \
-    defined(__mips__) || defined(__ns32k__) || defined(__alpha__) || \
-    defined(__powerpc__) || defined(__ppc__) || defined(__m88k__) || \
-    defined(__hppa__) || defined(__x86_64__) || (defined(__arm__) && \
-    defined(__VFP_FP__))
+#if defined(HAVE_INTTYPES_H)
+#include <inttypes.h>
+#elif defined(HAVE_STDINT_H)
+#include <stdint.h>
+#endif
+
+#ifdef HAVE_SYS_TYPES_H
 #include <sys/types.h>
-#if BYTE_ORDER == BIG_ENDIAN
+#endif
+
+#ifdef WORDS_BIGENDIAN
 #define IEEE_BIG_ENDIAN
 #else
 #define IEEE_LITTLE_ENDIAN
 #endif
-#endif

 #if defined(__arm__) && !defined(__VFP_FP__)
 /*
@@ -123,20 +122,16 @@ static char *rcsid = "$OpenBSD: strtod.c

 #if defined(_MSC_VER)
 #define int32_t __int32
-#define u_int32_t unsigned __int32
+#define uint32_t unsigned __int32
 #define IEEE_LITTLE_ENDIAN
 #endif

-#if defined(__sparc__) || defined(__ppc__)
-#define u_int32_t uint32_t
-#endif
-
 #ifdef HAVE_SYS_BITYPES_H
 #include <sys/bitypes.h>
 #endif

 #define Long	int32_t
-#define ULong	u_int32_t
+#define ULong	uint32_t

 #ifdef __cplusplus
 #include "malloc.h"
