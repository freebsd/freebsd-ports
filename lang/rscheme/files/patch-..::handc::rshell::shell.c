
$FreeBSD$

--- ../handc/rshell/shell.c	2001/07/31 08:24:33	1.1
+++ ../handc/rshell/shell.c	2001/07/31 08:25:25
@@ -43,7 +43,7 @@
   {
     char temp[1024];
 
-    sprintf( temp, "%s/resource/system.img", rs_install_dir );
+    sprintf( temp, "%s/share/rscheme/resource/system.img", rs_install_dir );
     return rscheme_std_main( argc, argv, std_modules, temp );
   }
 #endif
