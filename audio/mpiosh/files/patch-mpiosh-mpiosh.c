--- mpiosh/mpiosh.c.orig       Thu Nov 14 02:05:28 2002
+++ mpiosh/mpiosh.c    Thu Jun 19 19:59:10 2003
@@ -39,6 +39,8 @@
 #include "readline.h"
 #include "mpiosh.h"

+#define SA_NOMASK     0
+
 /* mpiosh core functions */
 void
 mpiosh_init(void)
@@ -113,7 +115,9 @@

   while ((line = readline(mpiosh.prompt))) {
     if ((*line == '\0') || mpiosh_cancel) {
+#if 0
       rl_clear_pending_input ();
+#endif
       mpiosh_cancel = 0;
       mpiosh_cancel_ack = 0;
       continue;
