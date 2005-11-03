--- bin/install.pike.orig	Tue Nov  1 09:58:59 2005
+++ bin/install.pike	Tue Nov  1 09:59:20 2005
@@ -1707,7 +1707,7 @@
 
     if(file_stat(vars->MANDIR_SRC))
     {
-      install_dir(vars->MANDIR_SRC,combine_path(man_prefix,"man1"),0);
+      //install_dir(vars->MANDIR_SRC,combine_path(man_prefix,"man1"),0);
     }
   };
 
