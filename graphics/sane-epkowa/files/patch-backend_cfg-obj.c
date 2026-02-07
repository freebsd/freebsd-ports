--- backend/cfg-obj.c	2008-12-08 02:11:49.000000000 +0100
+++ backend/cfg-obj.c	2008-12-26 22:17:45.000000000 +0100
@@ -487,6 +487,7 @@
 static FILE *
 _cfg_fopen_conf (const char *name)
 {
+return sanei_config_open(name);
   const char *default_path = "." PATH_SEP_STR SANE_CONFIG_DIR_NAME;
 
   char *path = getenv ("SANE_CONFIG_DIR");
