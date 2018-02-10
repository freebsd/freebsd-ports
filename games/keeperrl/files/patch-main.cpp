--- main.cpp.orig	2018-01-31 20:31:47 UTC
+++ main.cpp
@@ -22,6 +22,7 @@
 #include "extern/ProgramOptions.h"
 
 #include <exception>
+#include <sys/stat.h>
 
 #include "view.h"
 #include "options.h"
@@ -285,18 +286,8 @@ static int keeperMain(po::parser& commandLineFlags) {
   DirectoryPath userPath([&] () -> string {
     if (commandLineFlags["user_dir"].was_set())
       return commandLineFlags["user_dir"].get().string;
-#ifdef USER_DIR
-    else if (const char* userDir = USER_DIR)
-      return userDir;
-#endif // USER_DIR
-#ifndef WINDOWS
-    else if (const char* localPath = std::getenv("XDG_DATA_HOME"))
-      return localPath + string("/KeeperRL");
-#endif
-#ifdef ENABLE_LOCAL_USER_DIR // Some environments don't define XDG_DATA_HOME
     else if (const char* homePath = std::getenv("HOME"))
-      return homePath + string("/.local/share/KeeperRL");
-#endif // ENABLE_LOCAL_USER_DIR
+      return homePath + string("/.KeeperRL");
     else
       return ".";
   }());
@@ -311,8 +302,10 @@ static int keeperMain(po::parser& commandLineFlags) {
 #else
     uploadUrl = "http://localhost/~michal/" + serverVersion;
 #endif
-  //userPath.createIfDoesntExist();
-  CHECK(userPath.exists()) << "User directory \"" << userPath << "\" doesn't exist.";
+  if (!userPath.exists()) {
+    auto configDir = userPath.file("");
+    ::mkdir(configDir.getPath(), 0775);
+  }
   auto settingsPath = userPath.file("options.txt");
   if (commandLineFlags["restore_settings"].was_set())
     remove(settingsPath.getPath());
