--- src/daemon/server.c.orig	Mon Feb 17 15:22:19 2003
+++ src/daemon/server.c	Mon Feb 17 15:23:31 2003
@@ -88,11 +88,12 @@
 	if (strcmp (uts.sysname, LIBGTOP_COMPILE_SYSTEM) ||
 	    strcmp (uts.release, LIBGTOP_COMPILE_RELEASE) ||
 	    strcmp (uts.machine, LIBGTOP_COMPILE_MACHINE)) {
-		fprintf (stderr, "Can only run on %s %s %s\n",
+	    	fprintf (stderr, "This libgtop was compiled on %s %s %s\n",
 			 LIBGTOP_COMPILE_SYSTEM,
 			 LIBGTOP_COMPILE_RELEASE,
 			 LIBGTOP_COMPILE_MACHINE);
-		_exit (1);
+		fprintf (stderr, "If you see strange problems caused by it,\n");
+		fprintf (stderr, "you should recompile libgtop and dependent applications\n");
 	}
 #endif
 	
