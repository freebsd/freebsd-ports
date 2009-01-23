--- initfile.cc.orig	2009-01-19 20:08:34.000000000 +0000
+++ initfile.cc	2009-01-19 20:09:20.000000000 +0000
@@ -2196,12 +2196,12 @@
 #endif
     else BOOL_OPTION(show_gold_turns);
     else BOOL_OPTION(show_beam);
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
