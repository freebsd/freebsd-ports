--- src/scwm_guile.c.orig	2008-03-02 16:15:27.000000000 -0500
+++ src/scwm_guile.c	2008-03-02 16:15:35.000000000 -0500
@@ -78,9 +78,9 @@ scwm_body_apply (void *body_data)
 struct cwssdr_data
 {
   SCM tag;
-  scm_catch_body_t body;
+  scm_t_catch_body body;
   void *data;
-  scm_catch_handler_t handler;
+  scm_t_catch_handler handler;
 };
 
 static SCM
@@ -92,9 +92,9 @@ cwssdr_body (void *data)
 }
 
 SCM
-scm_internal_stack_cwdr (scm_catch_body_t body,
+scm_internal_stack_cwdr (scm_t_catch_body body,
 			 void *body_data,
-			 scm_catch_handler_t handler,
+			 scm_t_catch_handler handler,
 			 void *handler_data,
 			 SCM_STACKITEM *stack_item)
 {
@@ -336,7 +336,7 @@ scwm_handle_error (void *ARG_IGNORE(data
 			   SCM_OPN | SCM_WRTNG,
 			   "error-handler");
 #else
-  SCM port = scm_def_errp;
+  SCM port = scm_i_cur_errp ();
 #endif
 
   /* GJB:FIXME:MS: is this a guile compatibility test that can be dropped
