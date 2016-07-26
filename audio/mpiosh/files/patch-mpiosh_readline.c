--- mpiosh/readline.c.orig	2003-04-23 08:34:16 UTC
+++ mpiosh/readline.c
@@ -26,6 +26,8 @@
 #include "command.h"
 #include "mpiosh.h"
 
+#define rl_completion_matches completion_matches
+
 /* readline extensions */
 void
 mpiosh_readline_init(void)
