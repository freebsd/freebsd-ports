--- ./files.cc.orig	2012-09-30 23:25:31.000000000 +0200
+++ ./files.cc	2012-10-27 20:49:08.839666272 +0200
@@ -618,8 +618,10 @@
 {
     std::vector<player_save_info> chars;
 
+#ifdef WIZARD
     if (Options.no_save)
         return chars;
+#endif
 
 #ifndef DISABLE_SAVEGAME_LISTS
     std::string searchpath = _get_savefile_directory();
@@ -1741,8 +1743,10 @@
 // returns false if a new game should start instead
 static bool _restore_game(const std::string& filename)
 {
+#ifdef WIZARD
     if (Options.no_save)
         return false;
+#endif
 
     you.save = new package((_get_savefile_directory() + filename).c_str(), true);
 
