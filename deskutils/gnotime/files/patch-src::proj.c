--- src/proj.c.orig	Thu Jul  8 00:27:36 2004
+++ src/proj.c	Thu Jul  8 00:28:32 2004
@@ -1948,8 +1948,6 @@
 gboolean 
 gtt_project_obj_register (void)
 {
-	global_book = qof_book_new();
-
 /* Associate an ASCII name to each getter, as well as the return type */
 static QofParam params[] = {
 		{ GTT_PROJECT_EARLIEST, QOF_TYPE_DATE, (QofAccessFunc)prj_obj_get_earliest, NULL},
@@ -1957,6 +1955,8 @@
 		{ NULL },
 	};
 
+	global_book = qof_book_new();
+
 	qof_class_register (GTT_PROJECT_ID, (QofSortFunc)prj_obj_order, params);
 	return qof_object_register (&prj_object_def);
 }
@@ -2290,9 +2290,10 @@
 gboolean
 gtt_task_is_last_task (GttTask *tsk)
 {
+	GList *last;
 	if (!tsk || !tsk->parent || !tsk->parent->task_list) return TRUE;
 	
-	GList *last = g_list_last (tsk->parent->task_list);
+	last = g_list_last (tsk->parent->task_list);
 	if ((GttTask *) last->data == tsk) return TRUE;
 	return FALSE;
 }
@@ -2354,9 +2355,9 @@
 gtt_task_get_secs_earliest (GttTask *tsk)
 {
 	GList *node;
+	time_t earliest = INT_MAX;
 	if (NULL == tsk->interval_list) return 0;
 
-	time_t earliest = INT_MAX;
 
 	for (node=tsk->interval_list; node; node=node->next)
 	{
@@ -2370,9 +2371,9 @@
 gtt_task_get_secs_latest (GttTask *tsk)
 {
 	GList *node;
+	time_t latest = INT_MIN;
 	if (NULL == tsk->interval_list) return 0;
 
-	time_t latest = INT_MIN;
 
 	for (node=tsk->interval_list; node; node=node->next)
 	{
