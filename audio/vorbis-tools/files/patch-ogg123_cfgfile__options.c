
$FreeBSD$

--- ogg123/cfgfile_options.c.orig	Sun Dec 14 00:26:21 2003
+++ ogg123/cfgfile_options.c	Sun Dec 14 00:26:41 2003
@@ -441,7 +441,7 @@
   char filename[FILENAME_MAX];
   char *homedir = getenv("HOME");
 
-  parse_config_file(opts, "/etc/ogg123rc");
+  parse_config_file(opts, SYSCONFDIR "/ogg123rc");
   if (homedir && strlen(homedir) < FILENAME_MAX - 10) {
     /* Try ~/.ogg123 */
     strncpy(filename, homedir, FILENAME_MAX);
