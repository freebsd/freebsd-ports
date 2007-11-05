--- fw/TApplication.cpp.orig	2003-05-15 23:33:23.000000000 +0200
+++ fw/TApplication.cpp	2007-11-04 22:30:57.000000000 +0100
@@ -163,8 +163,8 @@
 	fLeaderWindow = XCreateSimpleWindow(fDisplay, GetRootWindow(), 10, 10, 10, 10, 0, 0, 0);
 	
 	XClassHint* classHint = XAllocClassHint();
-	classHint->res_name = "Zoinks";
-	classHint->res_class = "ZOINKS";
+	classHint->res_name = (char *)"Zoinks";
+	classHint->res_class = (char *)"ZOINKS";
 	
 	XWMHints* wmHints = NULL;
 	TPixmap* icon = GetIcon();
@@ -1154,7 +1154,7 @@
 		}
 		
 		// exec the shell
-		err = execl("/bin/sh", "sh", "-c", commandLine, NULL);
+		err = execl("/bin/sh", "sh", "-c", commandLine, (char *)NULL);
 
 		ASSERT(0);	// should never get here
 	}
