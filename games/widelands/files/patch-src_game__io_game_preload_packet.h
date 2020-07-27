--- src/game_io/game_preload_packet.h.orig	2020-07-12 19:33:44 UTC
+++ src/game_io/game_preload_packet.h
@@ -20,6 +20,8 @@
 #ifndef WL_GAME_IO_GAME_PRELOAD_PACKET_H
 #define WL_GAME_IO_GAME_PRELOAD_PACKET_H
 
+#include <ctime>
+
 #include "game_io/game_data_packet.h"
 #include "logic/game_controller.h"
 
