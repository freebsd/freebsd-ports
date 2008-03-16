--- ScriptKit/Library/GuileInterpreter.m.orig	2008-03-16 01:31:01.000000000 -0400
+++ ScriptKit/Library/GuileInterpreter.m	2008-03-16 01:31:26.000000000 -0400
@@ -349,9 +349,9 @@ add_let_script(NSMutableString * script,
       NS_DURING
 	{
 	  ret = gh_catch (SCM_BOOL_T, 
-			  (scm_catch_body_t) eval_str_wrapper, 
+			  (scm_t_catch_body) eval_str_wrapper, 
 			  c_script, 
-			  (scm_catch_handler_t) gopenstep_batch_handler, 
+			  (scm_t_catch_handler) gopenstep_batch_handler, 
 			  // Pass a script as nsstring to the handler
 			  script); 
 	}
@@ -365,9 +365,9 @@ add_let_script(NSMutableString * script,
     {
       // Only print message
       ret = gh_catch (SCM_BOOL_T, 
-		      (scm_catch_body_t) eval_str_wrapper, 
+		      (scm_t_catch_body) eval_str_wrapper, 
 		      c_script, 
-		      (scm_catch_handler_t) gopenstep_interactive_handler, 
+		      (scm_t_catch_handler) gopenstep_interactive_handler, 
 		      // Pass a script as cstring to the handler
 		      c_script);
     }
