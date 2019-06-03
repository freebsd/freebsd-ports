--- lib/isc/include/isc/endian.h.orig	2019-06-03 12:08:25 UTC
+++ lib/isc/include/isc/endian.h
@@ -43,14 +43,26 @@
 
 # include <sys/endian.h>
 
+#ifndef be16toh
 # define be16toh(x) betoh16(x)
+#endif
+#ifndef le16toh
 # define le16toh(x) letoh16(x)
+#endif
 
+#ifndef be32toh
 # define be32toh(x) betoh32(x)
+#endif
+#ifndef le32toh
 # define le32toh(x) letoh32(x)
+#endif
 
+#ifndef be64toh
 # define be64toh(x) betoh64(x)
+#endif
+#ifndef le64toh
 # define le64toh(x) letoh64(x)
+#endif
 
 #elif defined(_WIN32)
 /* Windows is always little endian */
