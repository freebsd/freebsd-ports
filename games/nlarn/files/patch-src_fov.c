--- src/fov.c.orig	2020-05-23 06:13:27 UTC
+++ src/fov.c
@@ -21,7 +21,7 @@
 #include "fov.h"
 #include "game.h"
 #include "map.h"
-#include "nlarn.h"
+#include "extdefs.h"
 #include "position.h"
 
 static void fov_calculate_octant(fov *fv, map *m, position center,
