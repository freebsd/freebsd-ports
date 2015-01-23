--- src/game.cpp.orig	2014-11-17 06:09:38.000000000 +0300
+++ src/game.cpp	2014-11-23 14:15:08.005205207 +0300
@@ -4535,15 +4535,17 @@ std::vector<std::string> game::list_acti
 void game::write_memorial_file(std::string sLastWords)
 {
 
+    std::string memorialdir = FILENAMES["memorialdir"];
+
     //Open the file first
-    DIR *dir = opendir("memorial");
+    DIR *dir = opendir(memorialdir.c_str());
     if (!dir) {
 #if (defined _WIN32 || defined __WIN32__)
-        mkdir("memorial");
+        mkdir(memorialdir.c_str());
 #else
-        mkdir("memorial", 0777);
+        mkdir(memorialdir.c_str(), 0777);
 #endif
-        dir = opendir("memorial");
+        dir = opendir(memorialdir.c_str());
         if (!dir) {
             dbg(D_ERROR) << "game:write_memorial_file: Unable to make memorial directory.";
             debugmsg("Could not make './memorial' directory");
@@ -4581,7 +4583,7 @@ void game::write_memorial_file(std::stri
     }
 
     //Omit the name if too many unusable characters stripped
-    std::string memorial_file_path = string_format("memorial/%s%s.txt",
+    std::string memorial_file_path = string_format((memorialdir + "%s%s.txt").c_str(),
                                      player_name.str().length() <= (u.name.length() / 5) ? "" : player_name.str().c_str(),
                                      timestamp.c_str());
 
