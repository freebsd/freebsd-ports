--- camlibs/ptp2/config.c.orig	Tue Dec 12 18:43:53 2006
+++ camlibs/ptp2/config.c	Tue Dec 12 19:00:45 2006
@@ -19,6 +19,8 @@
  */
 #include "config.h"
 
+#include <sys/types.h>
+#include <netinet/in.h>
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
@@ -1739,15 +1741,14 @@
 static int
 _get_nikon_list_wifi_profiles (CONFIG_GET_ARGS)
 {
-	gp_widget_new (GP_WIDGET_SECTION, _(menu->label), widget);
-	gp_widget_set_name (*widget, menu->name);
-
-	CameraWidget *child;
-
 	int ret;
 	char buffer[4096];
 	int i;
+	CameraWidget *child;
 	PTPParams *params = &(camera->pl->params);
+
+        gp_widget_new (GP_WIDGET_SECTION, _(menu->label), widget);
+        gp_widget_set_name (*widget, menu->name);
 
 	if (params->deviceinfo.VendorExtensionID != PTP_VENDOR_NIKON)
 		return (GP_ERROR_NOT_SUPPORTED);
