--- src/effects.c.orig	2020-05-23 06:13:27 UTC
+++ src/effects.c
@@ -22,7 +22,7 @@
 #include "cJSON.h"
 #include "effects.h"
 #include "game.h"
-#include "nlarn.h"
+#include "extdefs.h"
 #include "random.h"
 
 static const effect_data effects[ET_MAX] =
