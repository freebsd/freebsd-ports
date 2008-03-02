--- src/rgeval.c.orig	2008-03-02 16:15:23.000000000 -0500
+++ src/rgeval.c	2008-03-02 16:16:35.000000000 -0500
@@ -26,7 +26,6 @@ remote_guile_eval(char *req, char **outp
         unsigned char *ret, *output, *error;
         int rlen, olen, elen;
         SCM o_port, e_port;
-        SCM saved_def_e_port;
         
         /* Temporarily redirect output and error to string ports. 
            Note that the port setting functions return the current previous
@@ -34,10 +33,6 @@ remote_guile_eval(char *req, char **outp
         o_port = scm_set_current_output_port(make_output_strport(FUNC_NAME));
         e_port = scm_set_current_error_port(make_output_strport(FUNC_NAME));
         
-        /* Workaround for a problem with older Guiles */
-        saved_def_e_port = scm_def_errp;
-        scm_def_errp = scm_current_error_port();
-        
         /* Evaluate the request expression and free it. */
         val = scwm_safe_eval_str((char *) req);
 
@@ -48,7 +43,6 @@ remote_guile_eval(char *req, char **outp
            below for getting the strings back */
         o_port = scm_set_current_output_port(o_port);
         e_port = scm_set_current_error_port(e_port);
-        scm_def_errp = saved_def_e_port;
         
         /* Retrieve output and errors */
 	if(outp) {
