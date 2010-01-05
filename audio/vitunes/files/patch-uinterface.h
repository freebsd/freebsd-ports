--- ./uinterface.h.orig	2010-01-04 03:17:55.000000000 +0100
+++ ./uinterface.h	2010-01-05 18:33:14.000000000 +0100
@@ -17,11 +17,11 @@
 #define UINTERFACE_H
 
 #include <sys/ioctl.h>
-#include <sys/ioctl_compat.h>
 #include <ncurses.h>
 #include <ctype.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <stdint.h>
 #include <string.h>
 #include <stdbool.h>
 #include <termios.h>
