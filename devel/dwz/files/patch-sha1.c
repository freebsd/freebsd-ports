--- sha1.c.orig	2019-10-02 10:26:03.003230419 -0400
+++ sha1.c	2020-04-05 14:12:16.269464000 -0400
@@ -27,9 +27,9 @@
 
 #include <stddef.h>
 #include <string.h>
-#include <endian.h>
+#include <sys/endian.h>
 
-#if __BYTE_ORDER == __BIG_ENDIAN
+#if _BYTE_ORDER == _BIG_ENDIAN
 # define SWAP(n) (n)
 #else
 # define SWAP(n) \
