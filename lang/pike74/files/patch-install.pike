--- ../bin/install.pike.orig	Sat Feb 21 19:48:27 2004
+++ ../bin/install.pike	Sat Feb 21 19:48:47 2004
@@ -1332,7 +1332,7 @@
 
     if(file_stat(vars->MANDIR_SRC))
     {
-      install_dir(vars->MANDIR_SRC,combine_path(man_prefix,"man1"),0);
+      //install_dir(vars->MANDIR_SRC,combine_path(man_prefix,"man1"),0);
     }
   };
 
