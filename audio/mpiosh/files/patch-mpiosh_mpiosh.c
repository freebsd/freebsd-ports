--- mpiosh/mpiosh.c.orig	2003-08-25 19:38:57 UTC
+++ mpiosh/mpiosh.c
@@ -39,6 +39,8 @@
 #include "readline.h"
 #include "mpiosh.h"
 
+#define SA_NOMASK     0
+
 /* mpiosh core functions */
 void
 mpiosh_init(void)
@@ -121,7 +123,9 @@ main(int argc, char *argv[]) {
 
   while ((line = readline(mpiosh.prompt))) {
     if ((*line == '\0') || mpiosh_cancel) {
+#if 0
       rl_clear_pending_input ();
+#endif
       mpiosh_cancel = 0;
       mpiosh_cancel_ack = 0;
       continue;
