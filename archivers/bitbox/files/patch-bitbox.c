--- bitbox.c.orig	Mon Apr  2 02:26:37 2001
+++ bitbox.c	Mon Apr  9 01:44:53 2001
@@ -36,7 +36,8 @@
 #include <errno.h>
 
 /* Needed for the size-invariant integer types, like int32_t. */
-#include <stdint.h>
+/* #include <stdint.h> */
+#include <sys/types.h>
 
 /* We're not doing any networking, but we need the endian-swapping
    macros, like htonl(). */
