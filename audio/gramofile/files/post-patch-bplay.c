Index: bplaysrc/bplay.c
@@ -33,23 +33,30 @@
 /* Needed for BYTE_ORDER and BIG/LITTLE_ENDIAN macros. */
 #ifndef _BSD_SOURCE
 # define _BSD_SOURCE
-# include <endian.h>
+# include <sys/endian.h>
 # undef  _BSD_SOURCE
 #else
 # include <endian.h>
 #endif
 
 #include <sys/types.h>
+#ifndef __FreeBSD__
 #include <byteswap.h>
+#endif
 
 /* Adapted from the byteorder macros in the Linux kernel. */
 #if BYTE_ORDER == LITTLE_ENDIAN
 #define cpu_to_le32(x) (x)
 #define cpu_to_le16(x) (x)
 #else
+#ifdef __FreeBSD__
+#define cpu_to_le32(x) bswap32((x))
+#define cpu_to_le16(x) bswap16((x))
+#else
 #define cpu_to_le32(x) bswap_32((x))
 #define cpu_to_le16(x) bswap_16((x))
+#endif
 #endif
 
 #define le32_to_cpu(x)	cpu_to_le32((x))
