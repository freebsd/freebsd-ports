--- src/guile-compat.h.orig	2008-03-02 16:22:11.000000000 -0500
+++ src/guile-compat.h	2008-03-02 16:22:22.000000000 -0500
@@ -33,8 +33,8 @@ extern "C" {
 #define DEREF_LAST_STACK scm_fluid_ref(SCM_VARIABLE_REF (scm_the_last_stack_fluid_var))
 
 SCM 
-scm_internal_cwdr_no_unwind (scm_catch_body_t body, void *body_data,
-			     scm_catch_handler_t handler, void *handler_data,
+scm_internal_cwdr_no_unwind (scm_t_catch_body body, void *body_data,
+			     scm_t_catch_handler handler, void *handler_data,
 			     SCM_STACKITEM *stack_start);
 
 SCM make_output_strport(char *fname);
