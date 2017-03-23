--- biff.c.orig	2017-03-22 15:54:32 UTC
+++ biff.c
@@ -6,6 +6,8 @@
 
 #include	<stdio.h>
 #include	<stdlib.h>
+#include	<string.h>
+#include	<unistd.h>
 #include	<pwd.h>			/* for passwd */
 #include	<sys/stat.h>	/* for stat, needs types.h */
 
