--- glib/tests/include.c.orig	2012-03-06 12:11:39.000000000 +0100
+++ glib/tests/include.c	2012-03-06 12:13:17.000000000 +0100
@@ -3,6 +3,7 @@
 #define _POSIX_C_SOURCE 0
 #undef _GNU_SOURCE
 #undef _XOPEN_SOURCE
+#include <sys/types.h>
 #include <pthread.h>
 #include <glib.h>
 
