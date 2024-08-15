--- tog/tog.c.orig	2024-07-12 06:14:53 UTC
+++ tog/tog.c
@@ -42,6 +42,7 @@
 #include <pthread.h>
 #include <libgen.h>
 #include <regex.h>
+#include <sched.h>
 
 #include "got_version.h"
 #include "got_error.h"
@@ -1720,6 +1721,15 @@ view_input(struct tog_view **new, int *done, struct to
 	}
 
 	if (view->searching && !view->search_next_done) {
+		errcode = pthread_mutex_unlock(&tog_mutex);
+		if (errcode)
+			return got_error_set_errno(errcode,
+			    "pthread_mutex_unlock");
+		sched_yield();
+		errcode = pthread_mutex_lock(&tog_mutex);
+		if (errcode)
+			return got_error_set_errno(errcode,
+			    "pthread_mutex_lock");
 		view->search_next(view);
 		return NULL;
 	}
