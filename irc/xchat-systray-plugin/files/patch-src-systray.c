--- src/systray.c.orig	Fri Apr 30 14:38:10 2004
+++ src/systray.c	Sun May  2 01:02:59 2004
@@ -117,16 +117,18 @@
 	edit=TRUE;
 	go_change=TRUE;
 	go_identify=TRUE;
-	strcpy(imagepath,xchat_get_info(ph, "xchatdir"));
+	strcpy(imagepath,"/usr/X11R6/lib/xchat/plugins");
 
 }
 // events handling
  void tray_init_xchat(void)
 {
-	initialize_shared_vars();
-	//show warning if version is too old
 	const char *str;
 	int i;
+
+	initialize_shared_vars();
+
+	//show warning if version is too old
 	if (xchat_get_prefs (ph, "away_size_max", &str, &i) == 0)
 	version_warning();
 
@@ -191,7 +193,7 @@
 	if (filename && type) 
 	{
 		if (imagepath) sprintf(temp,"%s/%s/%s", imagepath ,type,filename);
-		else sprintf(temp,"%s/%s/%s", xchat_get_info(ph, "xchatdir"),type,filename);
+		else sprintf(temp,"%s/%s/%s", "/usr/X11R6/lib/xchat/plugins",type,filename);
 #ifdef _WIN32_			
 		tempbuffer= ((HICON)LoadImage( tray_inst, temp, IMAGE_ICON, 16, 16, LR_LOADFROMFILE ));
 #else	
