--- vendor/github.com/tree-sitter/go-tree-sitter/src/portable/endian.h.orig	2026-04-11 04:15:35 UTC
+++ vendor/github.com/tree-sitter/go-tree-sitter/src/portable/endian.h
@@ -55,12 +55,8 @@
 #    include <sys/endian.h>
 
-#    define be16toh(x) betoh16(x)
-#    define le16toh(x) letoh16(x)
-
-#    define be32toh(x) betoh32(x)
-#    define le32toh(x) letoh32(x)
-
-#    define be64toh(x) betoh64(x)
-#    define le64toh(x) letoh64(x)
+#    define __BYTE_ORDER    BYTE_ORDER
+#    define __BIG_ENDIAN    BIG_ENDIAN
+#    define __LITTLE_ENDIAN LITTLE_ENDIAN
+#    define __PDP_ENDIAN    PDP_ENDIAN
 
 #elif defined(__WINDOWS__)
