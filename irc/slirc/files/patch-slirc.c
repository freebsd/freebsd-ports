--- slirc.c.orig	Tue Aug 24 00:15:11 1999
+++ slirc.c	Sun Jan  7 03:17:46 2001
@@ -242,7 +242,7 @@
 {
    char secs[8];
 	 
-	 sprintf(Status, "%s -> %s  Server[%s]  %s",
+	 snprintf(Status, sizeof(Status), "%s -> %s  Server[%s]  %s",
 	   NickName, Target, ServerName, StatMsg);
    
    SLsmg_gotorc(start, 0);
@@ -339,13 +339,15 @@
    
    /* now for scripts search-path */
    if((q = getenv("HOME")))
-     sprintf(SLirc_Load_Path,"%s/.slirc/scripts:",q);
+     snprintf(SLirc_Load_Path, 196, "%s/.slirc/scripts",q);
    else
-     sprintf(SLirc_Load_Path,"/home/%s/.slirc/scripts:",p);
+     snprintf(SLirc_Load_Path, 196, "/home/%s/.slirc/scripts",p);
 
 	 if (2 != SLpath_file_exists(SLirc_Load_Path))
 	   SLirc_Load_Path[0] = '\0';
-   
+   	 else
+	   strcat(SLirc_Load_Path, ":");
+
 	 strcat(SLirc_Load_Path,SCRIPTPATH); /* SCRIPTPATH defined in Makefile */
 }
 
