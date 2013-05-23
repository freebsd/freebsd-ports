--- ./yell.c.orig	2013-05-23 04:57:00.948543624 +0200
+++ ./yell.c	2013-05-23 04:57:26.400583853 +0200
@@ -1,5 +1,6 @@
 #include <stdio.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include <fcntl.h>
 #include <dev/speaker/speaker.h>
 #include <string.h>
