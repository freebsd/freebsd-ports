--- ../bin/install.pike.orig	Sat Feb 21 03:14:53 2004
+++ ../bin/install.pike	Sat Feb 21 03:12:41 2004
@@ -1380,7 +1380,7 @@
 
     if(file_stat(vars->MANDIR_SRC))
     {
-      install_dir(vars->MANDIR_SRC,combine_path(man_prefix,"man1"),0);
+      //install_dir(vars->MANDIR_SRC,combine_path(man_prefix,"man1"),0);
     }
   };
 
