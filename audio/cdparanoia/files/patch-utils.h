Index: utils.h
===================================================================
RCS file: /home/cvs/cdparanoia/utils.h,v
retrieving revision 1.1.1.1
retrieving revision 1.3
diff -u -r1.1.1.1 -r1.3
--- utils.h	2003/01/05 09:46:26	1.1.1.1
+++ utils.h	2003/01/06 23:34:21	1.3
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
