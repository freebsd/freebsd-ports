--- plugins/platform-launcher/library/motif/eclipseMotif.c.orig	Fri Nov  8 05:17:00 2002
+++ plugins/platform-launcher/library/motif/eclipseMotif.c	Fri Nov 29 05:55:57 2002
@@ -323,7 +323,11 @@
 	if (jvmProcess != 0)
 	{
 		wait( &exitCode );
+#if !defined(__FreeBSD__)
 		jvmExitCode = ((exitCode & 0x00ff) == 0 ? (exitCode >> 8) : exitCode); /* see wait(2) */
+#else
+		jvmExitCode = WIFEXITED(exitCode) ? WEXITSTATUS(exitCode) : exitCode; /* see wait(2) */
+#endif
 	}
 	
 	/* Return the exit code from the JVM. */
