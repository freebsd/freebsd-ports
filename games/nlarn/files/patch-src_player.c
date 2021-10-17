--- src/player.c.orig	2020-05-23 06:13:27 UTC
+++ src/player.c
@@ -27,13 +27,13 @@
 #include "display.h"
 #include "fov.h"
 #include "game.h"
-#include "nlarn.h"
+#include "extdefs.h"
 #include "player.h"
 #include "random.h"
 #include "scoreboard.h"
 #include "sobjects.h"
 
-const char *player_sex_str[] = {"not defined", "male", "female"};
+const char *player_sex_str[PS_MAX] = {"not defined", "male", "female"};
 
 static const char aa1[] = "mighty evil master";
 static const char aa2[] = "apprentice demi-god";
