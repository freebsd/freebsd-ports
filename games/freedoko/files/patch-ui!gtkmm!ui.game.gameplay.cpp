--- /home/tg/.BACKUP/!home!tg!work!FreeBSD!ports!local!freedoko!work!FreeDoko_0.6.4!src!ui!gtkmm!ui.game.gameplay.cpp~	Mon May 31 16:38:45 2004
+++ ui/gtkmm/ui.game.gameplay.cpp	Tue Jun  8 18:59:56 2004
@@ -175,7 +175,7 @@
 	}
 #endif
 
-      } while (false);
+      } while (player.hand().requested_position() == UINT_MAX);
 
       this->main_window->menu->card_got();
       this->table->card_got();
