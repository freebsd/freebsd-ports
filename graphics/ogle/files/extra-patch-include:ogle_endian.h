--- include/ogle_endian.h.orig	Thu Oct  4 05:42:11 2001
+++ include/ogle_endian.h	Wed Apr 10 01:16:32 2002
@@ -39,6 +39,13 @@
 #elif defined(HAVE_SYS_ENDIAN_H)
 #  include <sys/endian.h>
 #  define FROM_BE_32(x) (swap32(x))
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
