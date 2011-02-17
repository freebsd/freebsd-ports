--- src/main.c	2011-01-07 06:12:27.000000000 +0100
+++ src/main.c	2011-01-07 06:16:35.000000000 +0100
@@ -72,7 +72,7 @@
 #  define _POSIX_SOURCE 1               /* Solaris needs this */
 #endif
 
-extern char origbotname[], userfile[], botnetnick[];
+extern char origbotname[], userfile[], botnetnick[], tempdir[];
 extern int dcc_total, conmask, cache_hit, cache_miss, max_logs, quick_logs,
            quiet_save;
 extern struct dcc_t *dcc;
@@ -105,7 +105,7 @@
 int term_z = 0;         /* Foreground: use the terminal as a partyline?  */
 int use_stderr = 1;     /* Send stuff to stderr instead of logfiles?     */
 
-char configfile[121] = "eggdrop.conf";  /* Default config file name */
+char configfile[121] = __PREFIX__ "/etc/eggdrop.conf";  /* Default config file name */
 char pid_file[120];                     /* Name of the pid file     */
 char helpdir[121] = "help/";            /* Directory of help files  */
 char textdir[121] = "text/";            /* Directory for text files */
@@ -1064,7 +1064,7 @@
   cache_miss = 0;
   cache_hit = 0;
   if (!pid_file[0])
-    egg_snprintf(pid_file, sizeof pid_file, "pid.%s", botnetnick);
+    egg_snprintf(pid_file, sizeof pid_file, "%s/pid.%s", tempdir, botnetnick);
 
   /* Check for pre-existing eggdrop! */
   f = fopen(pid_file, "r");
