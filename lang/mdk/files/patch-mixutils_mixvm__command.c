--- mixutils/mixvm_command.c.orig	2008-03-20 13:44:32.000000000 +0000
+++ mixutils/mixvm_command.c
@@ -80,7 +80,7 @@ mix_vm_command_info_t commands[] = {
   { "prompt", cmd_prompt_, N_("Set command prompt"), "prompt PROMPT" },
   { "shell", cmd_shell_, N_("Execute shell command"), "shell COMMAND" },
   { "quit", cmd_quit_, N_("Quit the program"), "quit" },
-  { (char *)NULL, (Function *)NULL, (char *)NULL }
+  { (char *)NULL, (rl_hook_func_t *)NULL, (char *)NULL }
 };
 
 
@@ -217,7 +217,7 @@ mixvm_cmd_init (mix_config_t *config, ch
 
 #ifdef HAVE_LIBREADLINE
   /* Tell the completer that we want a crack first. */
-  rl_attempted_completion_function = (CPPFunction *)mixvm_cmd_completion_;
+  rl_attempted_completion_function = (rl_completion_func_t *)mixvm_cmd_completion_;
 #endif /* HAVE_LIBREADLINE */
 
   /* initialise the dispatcher */
