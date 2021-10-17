--- src/game.c.orig	2020-05-23 06:13:27 UTC
+++ src/game.c
@@ -28,6 +28,7 @@
 #include <string.h>
 #include <zlib.h>
 #include <glib/gstdio.h>
+#include <unistd.h>
 
 #if (defined __unix) || (defined __unix__) || (defined __APPLE__)
 # include <sys/file.h>
@@ -42,7 +43,7 @@
 #include "config.h"
 #include "display.h"
 #include "game.h"
-#include "nlarn.h"
+#include "extdefs.h"
 #include "player.h"
 #include "spheres.h"
 #include "random.h"
