Index: utils.h
===================================================================
RCS file: /home/cvs/cdparanoia/utils.h,v
retrieving revision 1.1.1.1
retrieving revision 1.3
--- utils.h.orig	2000-04-19 22:41:04 UTC
+++ utils.h
@@ -1,5 +1,9 @@
 #include <stdlib.h>
+#ifdef Linux
 #include <endian.h>
+#elif defined(__FreeBSD__)
+#include <machine/endian.h>
+#endif
 #include <stdio.h>
 #include <errno.h>
 #include <string.h>
