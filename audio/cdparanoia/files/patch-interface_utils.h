Index: interface/utils.h
===================================================================
RCS file: /home/cvs/cdparanoia/interface/utils.h,v
retrieving revision 1.1.1.1
retrieving revision 1.3
--- interface/utils.h.orig	2000-04-19 22:41:04 UTC
+++ interface/utils.h
@@ -1,4 +1,9 @@
+#ifdef LINUX
 #include <endian.h>
+#elif defined(__FreeBSD__)
+#include <machine/endian.h>
+#endif
+
 #include <stdio.h>
 #include <errno.h>
 #include <string.h>
