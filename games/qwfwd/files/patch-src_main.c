--- src/main.c.orig	2025-02-21 06:10:33 UTC
+++ src/main.c
@@ -174,6 +174,12 @@ int main(int _argc, char *_argv[])
 
 	srand((unsigned) time (NULL));
 
+	// Disable buffering for stdout and stderr to avoid issues when output
+	// is redirected to a file or pipe instead of being displayed in a
+	// terminal.
+	setbuf(stdout, NULL);
+	setbuf(stderr, NULL);
+
 	// show help ffs
 	if (argc > 1 && (	   !stricmp("-h", argv[1])
 						|| !stricmp("-?", argv[1])
