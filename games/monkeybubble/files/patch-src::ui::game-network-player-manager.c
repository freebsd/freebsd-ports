--- src/ui/game-network-player-manager.c.orig	Tue Aug 24 22:56:44 2004
+++ src/ui/game-network-player-manager.c	Tue Aug 24 22:57:00 2004
@@ -125,11 +125,12 @@
 gboolean start_timeout(gpointer data) {
     GameNetworkPlayerManager * manager;
     GameNetworkPlayer * game;
+    UiMain * ui_main;
 
     manager = GAME_NETWORK_PLAYER_MANAGER(data);
 
 
-    UiMain * ui_main =  ui_main_get_instance();
+    ui_main =  ui_main_get_instance();
 
     PRIVATE(manager)->playing = TRUE;
 
