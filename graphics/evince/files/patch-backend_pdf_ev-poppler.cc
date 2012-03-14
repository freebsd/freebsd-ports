--- ./backend/pdf/ev-poppler.cc.orig	2010-09-28 01:54:34.000000000 +0900
+++ ./backend/pdf/ev-poppler.cc	2011-11-22 20:11:28.000000000 +0900
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
 
