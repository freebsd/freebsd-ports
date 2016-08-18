--- src/example_read.c.orig	2002-03-08 13:09:50 UTC
+++ src/example_read.c
@@ -3,6 +3,9 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
 #include <puredb_read.h>
 
 int main(void)
