--- src/test/tester.c.orig	2015-01-19 15:43:11.000000000 +0100
+++ src/test/tester.c	2015-01-19 15:43:31.000000000 +0100
@@ -1,10 +1,10 @@
-#include <alloca.h>
 #include <errno.h>
 #include <fcntl.h>
 #include <stdarg.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/endian.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
