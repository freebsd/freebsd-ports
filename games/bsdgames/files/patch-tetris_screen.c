--- tetris/screen.c.orig	2026-09-26 10:54:51 UTC
+++ tetris/screen.c
@@ -48,6 +48,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <term.h>
+#include <termios.h>
 #include <unistd.h>
 
 #include "screen.h"
