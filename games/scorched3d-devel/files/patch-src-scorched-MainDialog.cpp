--- ./src/scorched/MainDialog.cpp.orig	Fri Dec  3 19:36:32 2004
+++ ./src/scorched/MainDialog.cpp	Tue Jan 25 19:34:29 2005
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
