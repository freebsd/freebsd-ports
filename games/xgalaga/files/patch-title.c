--- title.c.orig	2008-03-06 06:58:16.000000000 +0900
+++ title.c	2012-04-23 14:28:39.000000000 +0900
@@ -5,6 +5,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #ifdef HAVE_FCNTL_H
 # include <fcntl.h>
 #endif
