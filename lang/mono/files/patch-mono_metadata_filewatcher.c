--- mono/metadata/filewatcher.c.orig	Thu Dec  1 18:51:19 2005
+++ mono/metadata/filewatcher.c	Sun Dec 18 01:54:10 2005
@@ -99,9 +99,6 @@
 gint
 ves_icall_System_IO_FSW_SupportsFSW (void)
 {
-#if HAVE_KQUEUE
-	return 3;
-#else
 	GModule *fam_module;
 	gchar *filename;
 	int lib_used = 4; /* gamin */
@@ -119,13 +116,19 @@
 	}
 
 	if (fam_module == NULL)
-		return 0;
+		goto nofam;
 
 	g_module_symbol (fam_module, "FAMNextEvent", (gpointer *) &FAMNextEvent);
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
 
