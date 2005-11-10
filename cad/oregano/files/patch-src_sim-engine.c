
$FreeBSD$

--- src/sim-engine.c.orig
+++ src/sim-engine.c
@@ -265,9 +265,9 @@
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
 
@@ -298,6 +298,7 @@
 		 * path y todo
 		 */
 		execvp(simexec, args);
+		}
 
 		/* We should never get here. */
 		g_warning ("Error executing the simulation engine.");
