--- libr/core/cmd_anal.inc.c.orig	2026-06-27 13:15:37 UTC
+++ libr/core/cmd_anal.inc.c
@@ -9238,8 +9238,7 @@ static void cmd_anal_esil(RCore *core, const char *inp
 #if defined(__APPLE__) && !TARGET_OS_IPHONE
 					cmd_debug_stack_init (core, argc, argv, (*_NSGetEnviron()));
 #else
-					extern char **environ;
-					cmd_debug_stack_init (core, argc, argv, environ);
+					cmd_debug_stack_init (core, argc, argv, r_sys_get_environ ());
 #endif
 				} else {
 					cmd_debug_stack_init (core, argc, argv, envp);
