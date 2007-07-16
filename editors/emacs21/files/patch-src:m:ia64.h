--- src/m/ia64.h.orig	Fri Sep 29 06:00:37 2000
+++ src/m/ia64.h	Sun Sep  5 11:57:57 2004
@@ -147,7 +147,7 @@
 
 #ifndef NOT_C_CODE
 /* We need these because pointers are larger than the default ints.  */
-# if !defined(__NetBSD__) && !defined(__OpenBSD__)
+# if !defined(__NetBSD__) && !defined(__OpenBSD__)  && !defined(__FreeBSD__)
 #  include <alloca.h>
 # else
 #  include <stdlib.h>
@@ -178,6 +178,6 @@
 
 #endif /* not NOT_C_CODE */
 
-#define DATA_SEG_BITS	0x6000000000000000
+#define DATA_SEG_BITS	0x2000000000000000
 
 #define HAVE_TEXT_START
