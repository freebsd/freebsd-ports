--- Library/gg_class.m.orig	2008-03-02 14:19:31.000000000 -0500
+++ Library/gg_class.m	2008-03-02 14:20:22.000000000 -0500
@@ -414,8 +414,8 @@ gstep_send_msg_to_guile(id rcv, SEL sel,
   data.selname = gh_str02scm((char*)selname);
   data.argslist = argsList;
 
-  val = gh_catch(SCM_BOOL_T, (scm_catch_body_t)proc_wrapper, (void*)&data,
-			(scm_catch_handler_t)proc_error, (void*)procname);
+  val = gh_catch(SCM_BOOL_T, (scm_t_catch_body)proc_wrapper, (void*)&data,
+			(scm_t_catch_handler)proc_error, (void*)procname);
 
   /*
    *	Now decode the Guile return value into the correct ObjectiveC
