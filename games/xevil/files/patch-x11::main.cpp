--- x11/main.cpp.orig	2012-05-27 06:52:29.000000000 +0900
+++ x11/main.cpp	2012-05-27 06:52:58.000000000 +0900
@@ -25,6 +25,7 @@
 #include "utils.h"
 
 extern "C" {
+#include <stdlib.h>
 #include <X11/Xutil.h>
 
 #ifdef OPENWOUND_XOS_STRLEN_HACK
@@ -33,13 +34,13 @@
 #include <X11/Xos.h>
 }
 
-#include <iostream.h>
+#include <iostream>
 
 #include "utils.h"
 #include "neth.h"
 #include "game.h"
 
-
+GameP g_game;
 
 class TurnStarter: public ITurnStarter {
 public:
@@ -68,6 +69,7 @@
   Utils::seed_random();
 
   GameP game = new Game(&argc,argv);
+	g_game = game;
 
   //  assert (clock() != -1);
 
