--- ./src/liolib.c.orig	2013-01-05 22:46:54.000000000 +0100
+++ ./src/liolib.c	2013-01-05 22:47:32.000000000 +0100
@@ -19,6 +19,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 
 #define liolib_c
 #define LUA_LIB
