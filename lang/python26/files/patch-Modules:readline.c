--- Modules/readline.c.orig	Mon Oct 16 21:49:34 2000
+++ Modules/readline.c	Wed Apr 25 06:23:47 2001
@@ -17,32 +17,13 @@
 #endif
 
 /* GNU readline definitions */
-/* If you have string.h, you might need to add yourself to this #if... [cjh] */
-#if defined(__BEOS__)
-#undef HAVE_CONFIG_H
-/* At max warnings, we need protos for everything. [cjh] */
+#undef HAVE_CONFIG_H /* Else readline/chardefs.h includes strings.h */
 #include <readline/readline.h>
 #include <readline/history.h>
-#include <unistd.h>
-#else
-#include <readline/readline.h> /* You may need to add an -I option to Setup */
-
-extern int rl_parse_and_bind(char *);
-extern int rl_read_init_file(char *);
-extern int rl_insert_text(char *);
-extern int rl_bind_key(int, Function *);
-extern int rl_bind_key_in_map(int, Function *, Keymap);
-extern int rl_initialize(void);
-extern int add_history(char *);
-extern int read_history(char *);
-extern int write_history(char *);
-extern int history_truncate_file(char *, int);
-extern Function *rl_event_hook;
-#endif
 
 /* Pointers needed from outside (but not declared in a header file). */
-extern int (*PyOS_InputHook)(void);
-extern char *(*PyOS_ReadlineFunctionPointer)(char *);
+extern DL_IMPORT(int) (*PyOS_InputHook)(void);
+extern DL_IMPORT(char) *(*PyOS_ReadlineFunctionPointer)(char *);
 
 
 /* Exported function to send one line to readline's init file parser */
