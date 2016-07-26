--- mp3_check.c.orig	2000-07-29 06:51:38 UTC
+++ mp3_check.c
@@ -60,6 +60,7 @@ GOALS:		Initially, making a higly accura
 
 #include <errno.h>
 #include <stdio.h>
+#include <getopt.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <getopt.h>
