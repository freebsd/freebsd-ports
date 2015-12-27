--- config_defaults_inc.php.orig	2015-11-02 10:57:53 UTC
+++ config_defaults_inc.php
@@ -2347,9 +2347,13 @@
 
 	/**
 	 * Threshold needed to view project documentation
+	 * Note: setting this to ANYBODY will let any user download attachments
+	 * from private projects, regardless of their being a member of it.
+	 * @see $g_enable_project_documentation
+	 * @see $g_upload_project_file_threshold
 	 * @global int $g_view_proj_doc_threshold
 	 */
-	$g_view_proj_doc_threshold = ANYBODY;
+	$g_view_proj_doc_threshold = VIEWER;
 
 	/**
 	 * Site manager
