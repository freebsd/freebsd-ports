--- src/ircd.c.orig	Wed May 28 23:13:26 2003
+++ src/ircd.c	Wed Jan 28 01:50:45 2004
@@ -662,8 +662,8 @@
   read_conf_files(YES);         /* cold start init conf files */
 #ifndef STATIC_MODULES
 
-  mod_add_path(IRCD_PREFIX "/modules");
-  mod_add_path(IRCD_PREFIX "/modules/autoload");
+  mod_add_path(MODPATH);
+  mod_add_path(AUTOMODPATH);
 #endif
    
   initialize_server_capabs();   /* Set up default_server_capabs */
