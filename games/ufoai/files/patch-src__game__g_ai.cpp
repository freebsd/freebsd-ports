--- ./src/game/g_ai.cpp.orig	2014-06-05 06:18:39.000000000 +0200
+++ ./src/game/g_ai.cpp	2014-08-07 16:49:53.698302816 +0200
@@ -35,6 +35,8 @@
 #include "g_vis.h"
 #include "g_reaction.h"
 
+#include <cstdlib>
+
 typedef struct aiAction_s {
 	pos3_t to;			/**< grid pos to walk to for performing the action */
 	pos3_t stop;		/**< grid pos to end turn at (e.g. hiding spots) */
