--- plugins/symbol-db/symbol-db-engine-core.c.orig	2009-03-18 04:24:07.000000000 -0400
+++ plugins/symbol-db/symbol-db-engine-core.c	2009-04-20 00:40:52.000000000 -0400
@@ -1486,7 +1486,7 @@ sdb_engine_ctags_output_thread (gpointer
 
 			/* found out a new marker */ 
 			marker_ptr = strstr (marker_ptr + len_marker, CTAGS_MARKER);
-		} while (remaining_chars + len_marker < len_chars || marker_ptr != NULL);
+		} while (remaining_chars > 0 || marker_ptr != NULL);
 	}
 	else 
 	{
@@ -1644,7 +1644,7 @@ sdb_engine_ctags_launcher_create (Symbol
 	anjuta_launcher_set_encoding (priv->ctags_launcher, NULL);
 		
 	g_signal_connect (G_OBJECT (priv->ctags_launcher), "child-exited",
-						  G_CALLBACK (on_scan_files_end_1), NULL);
+						  G_CALLBACK (on_scan_files_end_1), dbe);
 
 	exe_string = g_strdup_printf ("%s --sort=no --fields=afmiKlnsStz --c++-kinds=+p "
 								  "--filter=yes --filter-terminator='"CTAGS_MARKER"'",
@@ -1810,8 +1810,8 @@ sdb_engine_scan_files_1 (SymbolDBEngine 
 		gchar *temp_file;
 		while (TRUE)
 		{
-			temp_file = g_strdup_printf ("/anjuta-%d_%ld.tags", getpid (),
-								 time (NULL));
+			temp_file = g_strdup_printf ("%s/anjuta-%d_%ld.tags", SHARED_MEMORY_PREFIX, getpid (),
+								 (long) time (NULL));
 			gchar *test;
 			test = g_strconcat (SHARED_MEMORY_PREFIX, temp_file, NULL);
 			if (g_file_test (test, G_FILE_TEST_EXISTS) == TRUE)
@@ -1831,12 +1831,12 @@ sdb_engine_scan_files_1 (SymbolDBEngine 
 		priv->shared_mem_str = temp_file;
 		
 		if ((priv->shared_mem_fd = 
-			 shm_open (temp_file, O_CREAT|O_RDWR, S_IRUSR|S_IWUSR)) < 0)
+			 open (temp_file, O_CREAT|O_RDWR, S_IRUSR|S_IWUSR)) < 0)
 		{
 			g_warning ("Error while trying to open a shared memory file. Be"
 					   "sure to have "SHARED_MEMORY_PREFIX" mounted with tmpfs");
 		}
-	
+
 		priv->shared_mem_file = fdopen (priv->shared_mem_fd, "a+b");
 		/*DEBUG_PRINT ("temp_file %s", temp_file);*/
 
@@ -2419,7 +2419,7 @@ sdb_engine_init (SymbolDBEngine * object
 static void
 sdb_engine_unlink_shared_files (gpointer key, gpointer value, gpointer user_data)
 {
-	shm_unlink (key);
+	unlink (key);
 }
 
 static void 
@@ -2508,7 +2508,7 @@ sdb_engine_finalize (GObject * object)
 	
 	if (priv->shared_mem_str)
 	{
-		shm_unlink (priv->shared_mem_str);
+		unlink (priv->shared_mem_str);
 		g_free (priv->shared_mem_str);
 		priv->shared_mem_str = NULL;
 	}
@@ -5834,12 +5834,12 @@ symbol_db_engine_update_buffer_symbols (
 		 * target buffer one */
 		base_filename = g_filename_display_basename (relative_path);
 		
-		shared_temp_file = g_strdup_printf ("/anjuta-%d-%ld-%s", getpid (),
-						 time (NULL), base_filename);
+		shared_temp_file = g_strdup_printf ("%s/anjuta-%d-%ld-%s", SHARED_MEMORY_PREFIX, getpid (),
+						 (long) time (NULL), base_filename);
 		g_free (base_filename);
 		
 		if ((buffer_mem_fd = 
-			 shm_open (shared_temp_file, O_CREAT|O_RDWR, S_IRUSR|S_IWUSR)) < 0)
+			 open (shared_temp_file, O_CREAT|O_RDWR, S_IRUSR|S_IWUSR)) < 0)
 		{
 			g_warning ("Error while trying to open a shared memory file. Be"
 					   "sure to have "SHARED_MEMORY_PREFIX" mounted with tmpfs");
