--- ecasound/eca-curses.cpp.orig	Thu Apr  3 19:52:32 2003
+++ ecasound/eca-curses.cpp	Thu Apr  3 19:54:32 2003
@@ -114,11 +114,7 @@
   rl_readline_name = "ecasound";
 
   /* we want to attempt completion first */
-#if RL_READLINE_VERSION >= 0x0402
   rl_attempted_completion_function = (rl_completion_func_t*)ecasound_completion;
-#else
-  rl_attempted_completion_function = (CPPFunction *)ecasound_completion;
-#endif
 }
 
 /* **************************************************************** */
@@ -149,11 +145,7 @@
   /* complete only the first command, otherwise complete files in 
    * the current directory */
   if (start == 0) {
-#if RL_READLINE_VERSION >= 0x0402
     matches = rl_completion_matches (text, (rl_compentry_func_t *)ecasound_command_generator);
-#else
-    matches = completion_matches (text, (CPFunction *)ecasound_command_generator);
-#endif
   }
   return (matches);
 }
