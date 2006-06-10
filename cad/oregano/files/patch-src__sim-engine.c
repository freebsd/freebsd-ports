--- src/sim-engine.c.orig	Wed May 24 14:16:30 2006
+++ src/sim-engine.c	Wed May 24 21:39:29 2006
@@ -268,9 +268,9 @@
 	/* TODO Would be recomendable to use pthread? */
 	engine->child_pid = fork();
 	if (engine->child_pid == 0) {
-		setpgrp ();
+		setpgrp(0, getpid());
 		/* Now oregano.simtype has gnucap or ngspice */
-		gchar *simexec = oregano.simexec;
+		{ gchar *simexec = oregano.simexec;
         /* !!!!!!!!!!! "-s" "-n" */
 		gchar *args[4] = { simexec, oregano.simtype, (gchar *)netlist, NULL };
 	
@@ -300,6 +300,7 @@
 		 * path y todo
 		 */
 		execvp(simexec, args);
+		}
 
 		/* We should never get here. */
 		g_warning ("Error executing the simulation engine.");
