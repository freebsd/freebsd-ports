--- include/ogle_endian.h.orig	Thu Oct  4 05:42:11 2001
+++ include/ogle_endian.h	Sat Sep 21 17:47:15 2002
@@ -38,7 +38,22 @@
 #  define FROM_BE_32(x) (bswap32(x))
 #elif defined(HAVE_SYS_ENDIAN_H)
 #  include <sys/endian.h>
+#if defined(__FreeBSD__)
+#if __FreeBSD_version >= 500000
+#  define FROM_BE_32(x) (bswap32(x))
+#else
 #  define FROM_BE_32(x) (swap32(x))
+#endif
+#else
+#  define FROM_BE_32(x) (swap32(x))
+#endif
+#elif defined(__FreeBSD__)
+#  define _KERNEL
+#  define I486_CPU	/* Will crash unless 486+ */
+#  include <machine/endian.h>
+#  undef _KERNEL
+#  undef I486_CPU
+#  define FROM_BE_32(x) (ntohl(x))
 #else
 #  warning "No accelerated byte swap found. Using slow c version."
 #  include <inttypes.h>
