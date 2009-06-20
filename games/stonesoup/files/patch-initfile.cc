--- ./initfile.cc.orig	2009-06-12 12:32:16.000000000 +0200
+++ ./initfile.cc	2009-06-19 13:54:51.000000000 +0200
@@ -2333,12 +2333,12 @@
 #ifndef USE_TILE
     else BOOL_OPTION(show_beam);
 #endif
-#ifndef SAVE_DIR_PATH
+// #ifndef SAVE_DIR_PATH
     else if (key == "morgue_dir")
     {
         morgue_dir = field;
     }
-#endif
+// #endif
     else if (key == "hp_warning")
     {
         hp_warning = atoi( field.c_str() );
