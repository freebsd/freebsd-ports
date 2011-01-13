--- libmysqld/lib_sql.cc.orig	2011-01-13 09:53:29.000000000 +0100
+++ libmysqld/lib_sql.cc	2011-01-13 09:54:03.000000000 +0100
@@ -510,8 +510,8 @@
     return 1;
   defaults_argc= *argcp;
   defaults_argv= *argvp;
-  remaining_argc= argc;
-  remaining_argv= argv;
+  remaining_argc= *argcp;
+  remaining_argv= *argvp;
 
   /* Must be initialized early for comparison of options name */
   system_charset_info= &my_charset_utf8_general_ci;
