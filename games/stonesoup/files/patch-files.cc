--- ./files.cc.orig	2013-09-30 20:32:00.000000000 +0200
+++ ./files.cc	2013-10-11 22:07:08.172887580 +0200
@@ -626,8 +626,10 @@
 {
     vector<player_save_info> chars;
 
+#ifdef WIZARD
     if (Options.no_save)
         return chars;
+#endif
 
 #ifndef DISABLE_SAVEGAME_LISTS
     string searchpath = _get_savefile_directory();
@@ -1792,8 +1794,10 @@
 // returns false if a new game should start instead
 static bool _restore_game(const string& filename)
 {
+#ifdef WIZARD
     if (Options.no_save)
         return false;
+#endif
 
     you.save = new package((_get_savefile_directory() + filename).c_str(), true);
 
