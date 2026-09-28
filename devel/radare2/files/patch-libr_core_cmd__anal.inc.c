--- libr/core/cmd_anal.inc.c.orig	2026-06-23 11:48:36 UTC
+++ libr/core/cmd_anal.inc.c
@@ -9923,8 +9923,7 @@ static void cmd_anal_esil(RCore *core, const char *inp
 #if defined(__APPLE__) && !TARGET_OS_IPHONE
 					cmd_debug_stack_init (core, argc, argv, (*_NSGetEnviron()));
 #else
-					extern char **environ;
-					cmd_debug_stack_init (core, argc, argv, environ);
+					cmd_debug_stack_init (core, argc, argv, r_sys_get_environ ());
 #endif
 				} else {
 					cmd_debug_stack_init (core, argc, argv, envp);
