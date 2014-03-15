--- src/os/pl-rl.c.orig	2014-03-15 18:04:05.000000000 +0100
+++ src/os/pl-rl.c	2014-03-15 18:04:29.000000000 +0100
@@ -96,7 +96,6 @@ extern void add_history(char *);	/* shou
 					/* readline.h versions */
 extern int rl_begin_undo_group(void);	/* delete when conflict arrises! */
 extern int rl_end_undo_group(void);
-extern Function *rl_event_hook;
 #ifndef HAVE_RL_FILENAME_COMPLETION_FUNCTION
 #define rl_filename_completion_function filename_completion_function
 extern char *filename_completion_function(const char *, int);
