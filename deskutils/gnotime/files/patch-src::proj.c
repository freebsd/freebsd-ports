--- src/proj.c.orig	Fri Sep  2 03:49:22 2005
+++ src/proj.c	Fri Oct 21 11:56:29 2005
@@ -1952,8 +1952,6 @@
 gboolean
 gtt_project_obj_register (void)
 {
-	global_book = qof_book_new();
-
 /* Associate an ASCII name to each getter, as well as the return type */
 static QofParam params[] = {
 		{ GTT_PROJECT_EARLIEST, QOF_TYPE_DATE, (QofAccessFunc)prj_obj_get_earliest, NULL},
@@ -1961,6 +1959,8 @@
 		{ NULL },
 	};
 
+	global_book = qof_book_new();
+
 	qof_class_register (GTT_PROJECT_ID, (QofSortFunc)prj_obj_order, params);
 	return qof_object_register (&prj_object_def);
 }
@@ -2294,9 +2294,10 @@
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
@@ -2358,9 +2359,9 @@
 gtt_task_get_secs_earliest (GttTask *tsk)
 {
 	GList *node;
+	time_t earliest = INT_MAX;
 	if (NULL == tsk->interval_list) return 0;
 
-	time_t earliest = INT_MAX;
 
 	for (node=tsk->interval_list; node; node=node->next)
 	{
@@ -2374,9 +2375,9 @@
 gtt_task_get_secs_latest (GttTask *tsk)
 {
 	GList *node;
+	time_t latest = INT_MIN;
 	if (NULL == tsk->interval_list) return 0;
 
-	time_t latest = INT_MIN;
 
 	for (node=tsk->interval_list; node; node=node->next)
 	{
