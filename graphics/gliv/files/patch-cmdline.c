--- cmdline.c.orig	Fri Jun  8 10:59:27 2001
+++ cmdline.c	Wed Jun 13 19:41:21 2001
@@ -44,7 +44,6 @@
    -s      --shuffle          Show images in random order (default=off)\n\
    -l      --load-requested   Load only when requested (default=off)\n\
    -v      --verbose          Verbose mode (default=off)\n\
-   -R      --recursive        Process directories recursively (default=off)\n\
    -i      --info             Show infos about displayed image (default=off)\n\
    -m      --maximize         Maximize image to fit screen (default=off)\n\
    -dINT   --delay=INT        Delay before hiding the cursor\n\
@@ -80,7 +79,6 @@
   args_info->shuffle_given = 0 ;
   args_info->load_requested_given = 0 ;
   args_info->verbose_given = 0 ;
-  args_info->recursive_given = 0 ;
   args_info->info_given = 0 ;
   args_info->maximize_given = 0 ;
   args_info->delay_given = 0 ;
@@ -89,7 +87,6 @@
   args_info->shuffle_flag = 0;\
   args_info->load_requested_flag = 0;\
   args_info->verbose_flag = 0;\
-  args_info->recursive_flag = 0;\
   args_info->info_flag = 0;\
   args_info->maximize_flag = 0;\
 }
@@ -109,7 +106,6 @@
         { "shuffle",	0, NULL, 's' },
         { "load-requested",	0, NULL, 'l' },
         { "verbose",	0, NULL, 'v' },
-        { "recursive",	0, NULL, 'R' },
         { "info",	0, NULL, 'i' },
         { "maximize",	0, NULL, 'm' },
         { "delay",	1, NULL, 'd' },
@@ -146,10 +142,6 @@
 
         case 'v':	/* Verbose mode.  */
           args_info->verbose_flag = !(args_info->verbose_flag);
-          break;
-
-        case 'R':	/* Process directories recursively.  */
-          args_info->recursive_flag = !(args_info->recursive_flag);
           break;
 
         case 'i':	/* Show infos about displayed image.  */
