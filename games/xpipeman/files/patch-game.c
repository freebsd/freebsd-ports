--- game.c.orig	1991-09-13 20:32:11 UTC
+++ game.c
@@ -35,6 +35,7 @@
  */
 
 #include <X11/Intrinsic.h>
+#include <stdlib.h>
 #include "xpipeman.h"
 
 /* some of these are global */
@@ -442,7 +443,7 @@ new_level()
       blkrstart=0;
       blkfull = STARTFULL;
 
-      if (current_callback != NULL)
+      if (current_callback != 0)
 	XtRemoveTimeOut(current_callback);
       current_callback = XtAddTimeOut(flow_time_start,show_when_flow,NULL);
       
@@ -458,7 +459,7 @@ new_level()
 void
 speed_up_flow()
 { int i;
- if (current_callback != NULL)
+ if (current_callback != 0)
    XtRemoveTimeOut(current_callback);
  flow_time = FASTFLOW;
  current_callback= XtAddTimeOut(flow_time,draw_flow,NULL);
@@ -515,13 +516,13 @@ XtIntervalId *id;
     }
    if (start_flowing)
      {
-      if (current_callback != NULL)
+      if (current_callback != 0)
 	XtRemoveTimeOut(current_callback);
       current_callback = XtAddTimeOut(flow_time_start,draw_flow,NULL);
     }
   else
     {
-      if (current_callback != NULL)
+      if (current_callback != 0)
 	XtRemoveTimeOut(current_callback);
       current_callback = XtAddTimeOut(flow_time_start,show_when_flow,NULL);
     }
@@ -533,7 +534,7 @@ draw_flow(data,id)
 caddr_t data;
 XtIntervalId *id;
 {
-  current_callback = NULL;
+  current_callback = 0;
   if (blktime < 2)
     {
       pipe_board[flow_x][flow_y] = blkrstart++;
@@ -584,7 +585,7 @@ increment_flow()
 
       if (failed) {
 	buttons_disabled = 1;
-	if (current_callback != NULL)
+	if (current_callback != 0)
 	  XtRemoveTimeOut(current_callback);
 	current_callback = XtAddTimeOut(3000,level_over,NULL);
       }
