Index: bplaysrc/bplay.c
@@ -33,14 +33,16 @@
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
