--- src/game.cc.orig	Sun May  5 04:30:51 2002
+++ src/game.cc	Sun Oct 30 00:48:40 2005
@@ -18,10 +18,15 @@
 
 #include <config.h>
 
-#include <strstream.h>
+#include <sstream>
+#include <iostream>
+#include <string>
+
 #include <time.h>
 #include <unistd.h>
 
+using namespace std;
+
 #include "about_dialog.h"
 #include "ball.h"
 #include "game.h"
@@ -193,21 +198,19 @@
 void
 Game::DisplayMoves()
 {
-   char info[128];
-   ostrstream ost(info, sizeof(info));
-
-   ost << _("Moves: ") << _nr_of_moves << std::ends;
-   gtk_label_set(GTK_LABEL(_moves), info);
+   ostringstream ost;
+   ost << _("Moves: ") << _nr_of_moves << ends;	// format string
+   string info = ost.str();	// retrieve formatted string
+   gtk_label_set(GTK_LABEL(_moves), info.c_str());
 }
 
 void
 Game::DisplayTime()
 {
-   char info[128];
-   ostrstream ost(info, sizeof(info));
-
-   ost << _("Time: ") << _seconds << std::ends;
-   gtk_label_set(GTK_LABEL(_time), info);
+   ostringstream ost;
+   ost << _("Time: ") << _seconds << ends;	// format string
+   string info = ost.str();						// retrieve formatted string
+   gtk_label_set(GTK_LABEL(_time), info.c_str());
 }
 
 void
