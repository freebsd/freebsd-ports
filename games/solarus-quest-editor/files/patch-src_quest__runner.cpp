--- src/quest_runner.cpp.orig	2015-08-20 11:15:41 UTC
+++ src/quest_runner.cpp
@@ -22,6 +22,7 @@
 #include <solarus/lowlevel/Debug.h>
 #include <solarus/lua/LuaContext.h>
 #include <iostream>
+#include <QApplication>
 #include <QSize>
 
 /**
@@ -88,7 +89,10 @@ void QuestRunner::run() {
 
   try {
 
-    Solarus::Arguments arguments;
+    std::string argv0 = QApplication::arguments().at(0).toStdString();
+    char *argv[1] = {(char *) argv0.c_str()};
+
+    Solarus::Arguments arguments(1, argv);
 
     // no-audio.
     if (settings.get_value_bool(Settings::no_audio)) {
