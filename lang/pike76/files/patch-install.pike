--- bin/install.pike.orig	2007-01-01 01:28:18.000000000 +0100
+++ bin/install.pike	2011-03-11 10:35:16.000000000 +0100
@@ -1707,7 +1707,7 @@ void do_install()
 
     if(file_stat(vars->MANDIR_SRC))
     {
-      install_dir(vars->MANDIR_SRC,combine_path(man_prefix,"man1"),0);
+      //install_dir(vars->MANDIR_SRC,combine_path(man_prefix,"man1"),0);
     }
   };
 
