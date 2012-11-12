--- ./ng-setup.cc.orig	2012-09-30 23:25:31.000000000 +0200
+++ ./ng-setup.cc	2012-10-27 20:49:08.841950945 +0200
@@ -1427,9 +1427,11 @@
         you.nemelex_sacrificing = true;
 
     // Create the save file.
+#ifdef WIZARD
     if (Options.no_save)
         you.save = new package();
     else
+#endif
         you.save = new package(get_savedir_filename(you.your_name).c_str(),
                                true, true);
 }
