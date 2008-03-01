--- source/Parser.C.orig	2008-03-01 18:34:26.000000000 -0500
+++ source/Parser.C	2008-03-01 18:34:45.000000000 -0500
@@ -991,8 +991,8 @@ Parser::parseScriptFunction(ServerConnec
   wd.func = scmFunc;
   wd.args = args_list;
 
-  gh_catch(SCM_BOOL_T, (scm_catch_body_t) scm_apply_wrapper,
-           (void *)&wd, (scm_catch_handler_t) Interp::ErrorHandler,
+  gh_catch(SCM_BOOL_T, (scm_t_catch_body) scm_apply_wrapper,
+           (void *)&wd, (scm_t_catch_handler) Interp::ErrorHandler,
            0);
 }
 #endif
