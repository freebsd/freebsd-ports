--- config/auto-aux/endian.c.orig	Fri Jan 21 11:07:13 2000
+++ config/auto-aux/endian.c	Sat Jan 29 21:40:20 2005
@@ -1,3 +1,5 @@
+#include <sys/endian.h>
+
 main()
 {
   long n[2];
@@ -6,9 +8,11 @@
   n[0] = 0x41424344;
   n[1] = 0;
   p = (char *) n;
-  if (strcmp(p, "ABCD") == 0)
+#if BYTE_ORDER == BIG_ENDIAN
     exit(0);
-  if (strcmp(p, "DCBA") == 0)
+#elif BYTE_ORDER == LITTLE_ENDIAN
     exit(1);
+#else
   exit(2);
+#endif
 }
