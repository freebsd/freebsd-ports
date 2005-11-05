--- src/sim-engine.c.orig	Tue Aug  9 00:26:23 2005
+++ src/sim-engine.c	Tue Aug  9 00:26:46 2005
@@ -265,7 +265,7 @@
 	/* TODO Would be recomendable to use pthread? */
 	engine->child_pid = fork();
 	if (engine->child_pid == 0) {
-		setpgrp ();
+		setpgrp(0, getpid());
 		/* Now oregano.simtype has gnucap or ngspice */
 		gchar *simexec = oregano.simexec;
         /* !!!!!!!!!!! "-s" "-n" */
