--- calendar/backends/groupwise/e-cal-backend-groupwise.c.orig	Wed Sep 29 13:51:58 2004
+++ calendar/backends/groupwise/e-cal-backend-groupwise.c	Wed Sep 29 13:52:10 2004
@@ -518,7 +518,7 @@
 	                          CAL_STATIC_CAPABILITY_NO_THISANDPRIOR "," \
 				  CAL_STATIC_CAPABILITY_NO_THISANDFUTURE "," \
 				  CAL_STATIC_CAPABILITY_NO_CONV_TO_ASSIGN_TASK "," \
-				  CAL_STATIC_CAPABILITY_NO_CONV_TO_RECUR "," \ 
+				  CAL_STATIC_CAPABILITY_NO_CONV_TO_RECUR "," \
 				  CAL_STATIC_CAPABILITY_SAVE_SCHEDULES);
 
 	return GNOME_Evolution_Calendar_Success;
