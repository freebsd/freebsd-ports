--- ./vier.c.orig	1992-07-29 02:04:22.000000000 +0200
+++ ./vier.c	2014-03-30 13:14:36.788587125 +0200
@@ -1,6 +1,8 @@
 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/time.h>
+#include <unistd.h>
+#include <string.h>
 
 time_t time();
 
