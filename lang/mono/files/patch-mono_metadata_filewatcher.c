--- mono/metadata/filewatcher.c.orig	Wed Jun  1 06:25:57 2005
+++ mono/metadata/filewatcher.c	Wed Jun  1 06:27:17 2005
@@ -97,9 +97,6 @@
 gint
 ves_icall_System_IO_FSW_SupportsFSW (void)
 {
-#if HAVE_KQUEUE
-	return 3;
-#else
 	GModule *fam_module;
 	gchar *filename;
 
@@ -109,13 +106,19 @@
 	fam_module = g_module_open (filename, G_MODULE_BIND_LAZY);
 	g_free (filename);
 	if (fam_module == NULL)
-		return 0;
+		goto nofam;
 
 	g_module_symbol (fam_module, "FAMNextEvent", (gpointer *) &FAMNextEvent);
 	if (FAMNextEvent == NULL)
-		return 0;
+		goto nofam;
 
 	return 2;
+
+ nofam:
+#if HAVE_KQUEUE
+	return 3;
+#else
+	return 0;
 #endif
 }
 
