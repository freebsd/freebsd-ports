--- src/example_read.c.orig	Fri Nov  1 23:21:19 2002
+++ src/example_read.c	Fri Nov  1 23:21:47 2002
@@ -3,6 +3,9 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
 #include <puredb_read.h>
 
 int main(void)
