--- bin/install.pike.orig	Mon Sep 24 17:52:22 2001
+++ bin/install.pike	Thu Oct 12 19:53:38 2006
@@ -986,12 +986,12 @@
 	lnk=combine_path(vars->exec_prefix || combine_path(vars->prefix, "bin"),"pike");
 	old_exec_prefix=vars->exec_prefix; // to make the directory for pike link
       }
+      man_prefix=combine_path(prefix,"man");
       prefix=combine_path("/",getcwd(),prefix,"pike",
 			  replace(version()-"Pike v"," release ","."));
       exec_prefix=combine_path(prefix,"bin");
       lib_prefix=combine_path(prefix,"lib");
       include_prefix=combine_path(prefix,"include","pike");
-      man_prefix=combine_path(prefix,"man");
       break;
   }
   break;
