--- ./mp3_check.c.orig	2000-07-29 08:51:38.000000000 +0200
+++ ./mp3_check.c	2014-02-14 11:10:48.285958149 +0100
@@ -60,6 +60,7 @@
 
 #include <errno.h>
 #include <stdio.h>
+#include <getopt.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <getopt.h>
