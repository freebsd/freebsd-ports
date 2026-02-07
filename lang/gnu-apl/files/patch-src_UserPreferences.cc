--- src/UserPreferences.cc.orig	2019-06-23 12:39:20 UTC
+++ src/UserPreferences.cc
@@ -1299,7 +1299,25 @@ int file_profile = 0;   // the current profile in the 
             }
          else if (!strcasecmp(opt, "READLINE_HISTORY_PATH"))
             {
-              line_history_path = UTF8_string(arg);
+              // If 'arg' starts with "~/", expand ~ -> $HOME
+              if (arg[0] == '~' && arg[1] == '/') 
+                 {
+                   const char * HOME = getenv("HOME");
+                   if (HOME == 0)
+                      {
+                        if (log_startup)
+                           CERR << "environment variable 'HOME' is not "
+                                   "defined for '~' expansion, will use "
+                                << (arg + 2) << endl;
+                        line_history_path = UTF8_string(arg + 2);
+                      }
+                   else
+                      {
+                        line_history_path = UTF8_string(HOME);
+                        line_history_path.append_ASCII(arg + 1);
+                      }
+                 }
+              else line_history_path = UTF8_string(arg);
             }
          else if (!strcasecmp(opt, "NABLA-TO-HISTORY"))
             {
