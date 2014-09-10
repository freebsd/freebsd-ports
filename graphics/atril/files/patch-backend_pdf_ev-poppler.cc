--- backend/pdf/ev-poppler.cc.orig	2012-07-28 17:20:48.000000000 -0500
+++ backend/pdf/ev-poppler.cc	2012-07-28 17:20:50.000000000 -0500
@@ -640,6 +640,7 @@
 	PopplerPermissions permissions;
 	EvPage *page;
 	char *metadata;
+	gboolean linearized;
 
 	info = g_new0 (EvDocumentInfo, 1);
 
@@ -676,7 +677,7 @@
 		      "producer", &(info->producer),
 		      "creation-date", &(info->creation_date),
 		      "mod-date", &(info->modified_date),
-		      "linearized", &(info->linearized),
+		      "linearized", &linearized,
 		      "metadata", &metadata,
 		      NULL);
 
@@ -782,6 +783,8 @@
 		info->security = g_strdup (_("No"));
 	}
 
+	info->linearized = linearized ? g_strdup (_("Yes")) : g_strdup (_("No"));
+
 	return info;
 }
 
