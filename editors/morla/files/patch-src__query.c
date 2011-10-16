--- ./src/query.c.orig	2011-10-02 23:46:35.559557849 +0200
+++ ./src/query.c	2011-10-02 23:50:37.359563100 +0200
@@ -1400,7 +1400,11 @@
 #endif
 
 	  uri_string = raptor_uri_filename_to_uri_string ("");
+#ifdef USE_RASQAL_OLD
 	  base_uri = raptor_new_uri (uri_string);
+#else
+	  base_uri = raptor_new_uri (rasqal, uri_string);
+#endif
 	  raptor_free_memory (uri_string);
 	}
 
@@ -1419,11 +1423,7 @@
 
       if (query)
 	{
-	  rasqal_query_set_fatal_error_handler (query, NULL,
-						query_rasqal_error);
-	  rasqal_query_set_error_handler (query, NULL, query_rasqal_error);
-	  rasqal_query_set_warning_handler (query, NULL,
-					    query_rasqal_warning);
+	  rasqal_world_set_log_handler (query, NULL, query_rasqal_error);
 
 	  if (rasqal_query_prepare
 	      (query, (const unsigned char *) buf, base_uri))
