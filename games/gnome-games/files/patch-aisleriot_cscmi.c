--- aisleriot/cscmi.c.orig	Wed Oct 18 17:51:31 2006
+++ aisleriot/cscmi.c	Wed Oct 18 17:51:13 2006
@@ -603,8 +603,8 @@ cscmi_drag_valid(int slot_id, GList *car
 			    cscmi_catch_handler,
 			    NULL);
   retval = call_data->retval;
-  g_free (call_data);
   scm_gc_unprotect_object (call_data->arg2);
+  g_free (call_data);
 
   return SCM_NFALSEP(retval);
 }
@@ -698,8 +698,8 @@ cscmi_drop_valid(int start_slot, GList *
 			    cscmi_catch_handler,
 			    NULL);
   retval = call_data->retval;
-  g_free (call_data);
   scm_gc_unprotect_object (call_data->arg2);
+  g_free (call_data);
 
   return SCM_NFALSEP(retval);
 }
