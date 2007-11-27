--- XMotif/param_w.c.orig	1992-10-07 04:16:18.000000000 +0100
+++ XMotif/param_w.c	2007-11-23 22:12:20.000000000 +0100
@@ -444,7 +444,7 @@
 					     XmNrightAttachment, XmATTACH_POSITION,
 					     XmNset, (parameter->p_flags & LogMask)? True : False,
 					     NULL);
-	  XtAddCallback(log_toggle, XmNvalueChangedCallback, comp_param_log_toggle, window_data);
+	  XtAddCallback(log_toggle, XmNvalueChangedCallback, (XtCallbackProc)comp_param_log_toggle, window_data);
 	  SetWidgetUserData(log_toggle,p_textf);
 	  p_textf->log_toggle=log_toggle;
 	}
@@ -459,7 +459,7 @@
 					       XmNrightAttachment, XmATTACH_POSITION,					       
 					       XmNset, (parameter->p_flags & MeterMask)? True : False,
 					       NULL);
-	  XtAddCallback(meter_toggle, XmNvalueChangedCallback, comp_param_meter_toggle, window_data);
+	  XtAddCallback(meter_toggle, XmNvalueChangedCallback, (XtCallbackProc)comp_param_meter_toggle, window_data);
 	  SetWidgetUserData(meter_toggle,p_textf);
 	  p_textf->meter_toggle=meter_toggle;
        }
@@ -479,8 +479,8 @@
 		      NULL);
 
 	if (parameter->p_flags & (InputMask | ModifyMask) && i!=0) { /* The name parameter is not editable from this window. */
-	  XtAddCallback(p_textf->textfield,XmNvalueChangedCallback,set_changed_by_user_flag,window_data);
-	  XtAddCallback(p_textf->textfield,XmNactivateCallback,change_parameter_cb,window_data);
+	  XtAddCallback(p_textf->textfield,XmNvalueChangedCallback,(XtCallbackProc)set_changed_by_user_flag,window_data);
+	  XtAddCallback(p_textf->textfield,XmNactivateCallback,(XtCallbackProc)change_parameter_cb,window_data);
 	  p_textf->initial_value=new_string(value);
 	  p_textf->current_value=new_string(value);
 	}
