--- ./src/scorched/MainDialog.cpp.orig	Tue May 18 00:45:23 2004
+++ ./src/scorched/MainDialog.cpp	Sun May 30 22:43:49 2004
@@ -25,8 +25,8 @@
 #include <wx/msgdlg.h>
 #define WIN32_LEAN_AND_MEAN
 #include <windows.h>
-#include <SDL/SDL.h>
-#include <SDL/SDL_net.h>
+#include <SDL11/SDL.h>
+#include <SDL11/SDL_net.h>
 #include <scorched/MainDialog.h>
 #include <scorched/HtmlHelpDialog.h>
 #include <scorched/NetDialog.h>
