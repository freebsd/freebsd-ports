https://git.gameoftrees.org/gitweb/?p=got.git;a=commitdiff;h=22403ab7111504d4c33872ec85a46d2eaf21a95b

--- lib/deltify.c.orig	2021-03-22 16:14:59 UTC
+++ lib/deltify.c
@@ -19,6 +19,7 @@
 #include <sys/queue.h>
 
 #include <assert.h>
+#include <endian.h>
 #include <errno.h>
 #include <limits.h>
 #include <stdint.h>
