--- mpiosh/readline.c.orig     Thu Jun 19 19:57:05 2003
+++ mpiosh/readline.c  Thu Jun 19 19:57:32 2003
@@ -26,6 +26,8 @@
 #include "command.h"
 #include "mpiosh.h"

+#define rl_completion_matches completion_matches
+
 /* readline extensions */
 void
 mpiosh_readline_init(void)
