--- src/gps_functions.c	Sat Jul 10 06:54:31 2010 -0700
+++ src/gps_functions.c	Fri Jul 23 06:17:01 2010 -0700
@@ -28,7 +28,6 @@
 #include "wp.h"
 #include "tracks.h"
 #include "livetracks.h"
-#include "hrm_functions.h"
 
 #define BUFSIZE 512
 char * distance2scale(float distance, float *factor);
@@ -363,13 +362,6 @@
 		set_label_nogps();
 	}
 	
-	if(hrm_on && (!hrmdata  || global_reconnect_hrm))
-		get_hrm_data();
-	else if(hrm_on && hrmdata) {
-		osd_hrm(FALSE);
-		if(global_infopane_visible)
-			set_hrm_labels();
-	}
 	
 	return TRUE; 
 }
