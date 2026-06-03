--- ./tetris/screen.c.ORIG	2024-09-17 22:29:09.000000000 +0200
+++ ./tetris/screen.c	2026-05-12 07:56:04.845628000 +0200
@@ -48,6 +48,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <term.h>
+#include <termios.h>
 #include <unistd.h>

 #include "screen.h"
