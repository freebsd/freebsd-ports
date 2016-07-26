--- yell.c.orig	2011-03-31 15:21:37 UTC
+++ yell.c
@@ -1,5 +1,6 @@
 #include <stdio.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include <fcntl.h>
 #include <dev/speaker/speaker.h>
 #include <string.h>
