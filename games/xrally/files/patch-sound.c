--- sound.c.orig	2009-02-22 14:43:06.000000000 +1100
+++ sound.c	2009-02-22 15:00:36.000000000 +1100
@@ -19,6 +19,7 @@
 #include <stdio.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
@@ -563,6 +564,7 @@
 			}
 
 skip_extended:
+			while (0) {};
 		} else {
 			/*
 			 * In the rest of the frames we slide volume, pitch,
