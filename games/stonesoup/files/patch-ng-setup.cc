--- ./ng-setup.cc.orig	2013-09-30 20:32:18.000000000 +0200
+++ ./ng-setup.cc	2013-10-11 22:07:08.174888114 +0200
@@ -1430,9 +1430,11 @@
     init_companions();
 
     // Create the save file.
+#ifdef WIZARD
     if (Options.no_save)
         you.save = new package();
     else
+#endif
         you.save = new package(get_savedir_filename(you.your_name).c_str(),
                                true, true);
 }
