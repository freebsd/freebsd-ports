--- sha1.c.orig	2021-03-08 07:56:18 UTC
+++ sha1.c
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
