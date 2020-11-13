-----------------------------------------------
commit 276b94a1f9ff915aab767e558957527ccddf43e9 (main)
from: Christian Weisgerber <naddy@mips.inka.de>
date: Fri Nov 13 21:09:10 2020 UTC
 
 Call pthread_cond_destroy(cond) exactly once when closing a view.
 
 This moves the pthread_cond_destroy(need_commits) from stop_log_thread(),
 which can be called twice, to close_log_view(), which is called
 once.  It also destroys the commit_loaded condition variable, which
 is created in open_log_view() but was never destroyed.
 
 ok stsp
 
blob - 3895e44e1cc2bd3dcc96dbcbd7369ecad839c9b0
blob + 200352838ae37181b0bce33796fd9bfa11c66d34
--- tog/tog.c.orig	2020-11-13 21:13:34 UTC
+++ tog/tog.c
@@ -2035,10 +2035,6 @@ stop_log_thread(struct tog_log_view_state *s)
 		s->thread = NULL;
 	}
 
-	errcode = pthread_cond_destroy(&s->thread_args.need_commits);
-	if (errcode && err == NULL)
-		err = got_error_set_errno(errcode, "pthread_cond_destroy");
-
 	if (s->thread_args.repo) {
 		got_repo_close(s->thread_args.repo);
 		s->thread_args.repo = NULL;
@@ -2057,8 +2053,18 @@ close_log_view(struct tog_view *view)
 {
 	const struct got_error *err = NULL;
 	struct tog_log_view_state *s = &view->state.log;
+	int errcode;
 
 	err = stop_log_thread(s);
+
+	errcode = pthread_cond_destroy(&s->thread_args.need_commits);
+	if (errcode && err == NULL)
+		err = got_error_set_errno(errcode, "pthread_cond_destroy");
+
+	errcode = pthread_cond_destroy(&s->thread_args.commit_loaded);
+	if (errcode && err == NULL)
+		err = got_error_set_errno(errcode, "pthread_cond_destroy");
+
 	free_commits(&s->commits);
 	free(s->in_repo_path);
 	s->in_repo_path = NULL;
