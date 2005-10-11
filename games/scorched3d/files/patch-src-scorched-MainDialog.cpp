--- ./src/scorched/MainDialog.cpp.orig	Sat Aug  6 13:57:39 2005
+++ ./src/scorched/MainDialog.cpp	Tue Aug  9 23:21:23 2005
@@ -26,8 +26,8 @@
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
