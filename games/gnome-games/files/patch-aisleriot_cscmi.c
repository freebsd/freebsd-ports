--- aisleriot/cscmi.c.orig	Tue Nov  7 17:49:43 2006
+++ aisleriot/cscmi.c	Tue Nov  7 17:49:53 2006
@@ -637,8 +637,8 @@ cscmi_drop_cards (int start_slot, GList 
 			    cscmi_call_lambda,
 			    call_data, cscmi_catch_handler, NULL);
   retval = call_data->retval;
-  g_free (call_data);
   scm_gc_unprotect_object (call_data->arg2);
+  g_free (call_data);
 
   return SCM_NFALSEP (retval);
 }
