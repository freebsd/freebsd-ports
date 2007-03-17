--- mono/metadata/filewatcher.c.orig	Fri Dec 29 19:52:48 2006
+++ mono/metadata/filewatcher.c	Fri Dec 29 20:25:18 2006
@@ -44,9 +44,6 @@
 gint
 ves_icall_System_IO_FSW_SupportsFSW (void)
 {
-#if HAVE_KQUEUE
-	return 3;
-#else
 	MonoDl *fam_module;
 	gchar *filename;
 	int lib_used = 4; /* gamin */
@@ -76,14 +73,20 @@
 	}
 
 	if (fam_module == NULL)
-		return 0;
+		goto nofam;
 
 	err = mono_dl_symbol (fam_module, "FAMNextEvent", (gpointer *) &FAMNextEvent);
 	g_free (err);
 	if (FAMNextEvent == NULL)
-		return 0;
+		goto nofam;
 
 	return lib_used;
+
+ nofam:
+#if HAVE_KQUEUE
+	return 3;
+#else
+	return 0;
 #endif
 }
 
