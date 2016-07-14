--- libctf.c.orig	2012-03-20 16:17:25 UTC
+++ libctf.c
@@ -1,7 +1,8 @@
+#include <sys/stat.h>
+
 #include <fcntl.h>
 #include <gelf.h>
 #include <limits.h>
-#include <malloc.h>
 #include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
