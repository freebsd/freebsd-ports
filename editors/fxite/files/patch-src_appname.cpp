Fix build with clang 6

appname.cpp:145:32: error: invalid suffix on literal; C++11 requires a space between literal and identifier [-Wreserved-user-defined-literal]
    dlg=new FxAsqWin(_("About "EXE_NAME), btns, i++);

--- src/appname.cpp.orig	2018-02-16 06:02:39 UTC
+++ src/appname.cpp
@@ -142,7 +142,7 @@ void AppAbout::AboutBox()
     FxAsqWin*dlg=NULL;
     FXString msg;
     int rv=-1;
-    dlg=new FxAsqWin(_("About "EXE_NAME), btns, i++);
+    dlg=new FxAsqWin(_("About " EXE_NAME), btns, i++);
     msg.format(App_About, _("Version"), VERSION, "yetanothergeek@gmail.com",
       _("  This program is free software, under the terms of the  \n"),
       _("Running"),
