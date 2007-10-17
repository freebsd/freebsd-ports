Index: src/main.c
@@ -126,7 +126,8 @@
 	gtk_init (&argc, &argv);
 	/* Restore DESKTOP_STARTUP_ID since, appearently, gtk_init() sometimes clears it */
 	// FIXME: Do we need to check if setenv() is available?
-	setenv ("DESKTOP_STARTUP_ID", startup_id, TRUE);
+	if (startup_id)
+		setenv ("DESKTOP_STARTUP_ID", startup_id, TRUE);
 	
 	if (getuid() != 0)
 	{
