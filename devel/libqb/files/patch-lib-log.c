--- lib/log.c.orig	2015-08-18 19:55:43 UTC
+++ lib/log.c
@@ -47,9 +47,15 @@ static int32_t logger_inited = QB_FALSE;
 static pthread_rwlock_t _listlock;
 static qb_log_filter_fn _custom_filter_fn = NULL;
 
+static QB_LIST_DECLARE(dlnames);
 static QB_LIST_DECLARE(tags_head);
 static QB_LIST_DECLARE(callsite_sections);
 
+struct dlname {
+	char *dln_name;
+	struct qb_list_head list;
+};
+
 struct callsite_section {
 	struct qb_log_callsite *start;
 	struct qb_log_callsite *stop;
@@ -739,23 +745,45 @@ qb_log_filter_ctl(int32_t t, enum qb_log
 }
 
 #ifdef QB_HAVE_ATTRIBUTE_SECTION
+/* Some platforms (eg. FreeBSD 10+) don't support calling dlopen() from
+ * within a dl_iterate_phdr() callback; so save all of the dlpi_names to
+ * a list and iterate over them afterwards. */
 static int32_t
 _log_so_walk_callback(struct dl_phdr_info *info, size_t size, void *data)
 {
+	struct dlname *dlname;
+
 	if (strlen(info->dlpi_name) > 0) {
-		void *handle;
-		void *start;
-		void *stop;
-		const char *error;
+		dlname = calloc(1, sizeof(struct dlname));
+		if (!dlname)
+			return 0;
+		dlname->dln_name = strdup(info->dlpi_name);
+		qb_list_add_tail(&dlname->list, &dlnames);
+	}
 
-		handle = dlopen(info->dlpi_name, RTLD_LAZY);
+	return 0;
+}
+
+static void
+_log_so_walk_dlnames(void)
+{
+	struct dlname *dlname;
+	struct qb_list_head *iter;
+	struct qb_list_head *next;
+
+	void *handle;
+	void *start;
+	void *stop;
+	const char *error;
+
+	qb_list_for_each_safe(iter, next, &dlnames) {
+		dlname = qb_list_entry(iter, struct dlname, list);
+
+		handle = dlopen(dlname->dln_name, RTLD_LAZY);
 		error = dlerror();
 		if (!handle || error) {
 			qb_log(LOG_ERR, "%s", error);
-			if (handle) {
-				dlclose(handle);
-			}
-			return 0;
+			goto done;
 		}
 
 		start = dlsym(handle, "__start___verbose");
@@ -773,9 +801,13 @@ _log_so_walk_callback(struct dl_phdr_inf
 			qb_log_callsites_register(start, stop);
 		}
 done:
-		dlclose(handle);
+		if (handle)
+			dlclose(handle);
+		qb_list_del(iter);
+		if (dlname->dln_name)
+			free(dlname->dln_name);
+		free(dlname);
 	}
-	return 0;
 }
 #endif /* QB_HAVE_ATTRIBUTE_SECTION */
 
@@ -823,6 +855,7 @@ qb_log_init(const char *name, int32_t fa
 #ifdef QB_HAVE_ATTRIBUTE_SECTION
 	qb_log_callsites_register(__start___verbose, __stop___verbose);
 	dl_iterate_phdr(_log_so_walk_callback, NULL);
+	_log_so_walk_dlnames();
 #endif /* QB_HAVE_ATTRIBUTE_SECTION */
 
 	conf[QB_LOG_STDERR].state = QB_LOG_STATE_DISABLED;
