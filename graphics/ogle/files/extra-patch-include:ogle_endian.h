--- include/ogle_endian.h.orig	Thu Oct 10 12:20:03 2002
+++ include/ogle_endian.h	Thu Oct 10 12:21:47 2002
@@ -39,6 +39,18 @@
 #elif defined(HAVE_SYS_ENDIAN_H) && !defined(__FreeBSD__)
 #  include <sys/endian.h>
 #  define FROM_BE_32(x) (swap32(x))
+#elif defined(__FreeBSD__)
+#  if defined(HAVE_SYS_ENDIAN_H) && __FreeBSD_version >= 500000
+#    include <sys/endian.h>
+#    define FROM_BE_32(x) (bswap32(x))
+#  else
+#  define _KERNEL
+#  define I486_CPU     /* Will crash unless 486+ */
+#  include <machine/endian.h>
+#  undef _KERNEL
+#  undef I486_CPU
+#  define FROM_BE_32(x) (ntohl(x))
+#  endif
 #else
 #  warning "No accelerated byte swap found. Using slow c version."
 #  include <inttypes.h>
