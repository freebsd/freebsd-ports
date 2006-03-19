--- cli/input.cc.orig	Wed Aug 31 05:57:33 2005
+++ cli/input.cc	Sun Mar 19 20:35:44 2006
@@ -49,7 +49,6 @@
 // temp fix to over come 23jan05 changes to configure script that prevent
 // readline from being found on older systems.
 #define HAVE_READLINE
-#define HAVE_NSCLEAN_READLINE
 
 #endif
 
@@ -899,7 +898,7 @@
   win32_fd_to_raw(fileno(stdin));
 #endif
 
-  rl_getc_function = gpsim_rl_getc;
+  rl_getc_function = (Function *) gpsim_rl_getc;
   channel = g_io_channel_unix_new (fileno(stdin));
 
 #ifdef _WIN32
@@ -915,10 +914,10 @@
 #else
  g_io_add_watch (channel, G_IO_IN, keypressed, NULL);
 #endif
-  rl_callback_handler_install (prompt, have_line);
+  rl_callback_handler_install ((char *) prompt, (VFunction *) have_line);
 
   /* Tell the completer that we want a crack first. */
-  rl_attempted_completion_function = gpsim_completion;
+  rl_attempted_completion_function = (CPPFunction *) gpsim_completion;
 
 #endif //HAVE_READLINE
 }
