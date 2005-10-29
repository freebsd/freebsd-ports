--- src/new_highscore_dialog.h.orig	Sun Oct 30 00:51:13 2005
+++ src/new_highscore_dialog.h	Sun Oct 30 00:51:28 2005
@@ -20,6 +20,7 @@
 #define _NEW_HIGHSCORE_DIALOG_H
 
 #include <string>
+using namespace std;
 #include "dialog.h"
 
 class Game;
@@ -28,7 +29,7 @@
    Game*	_game;
    GtkWidget*	_name;
    char*	GetLoginName();
-   std::string	GetUserName();
+   string	GetUserName();
 protected:
    void OnOk();
 public:
