--- fmirror.c.orig	Tue Jun  7 10:39:35 2005
+++ fmirror.c	Tue Jun  7 10:39:44 2005
@@ -642,7 +642,7 @@
     va_list args;
     va_start(args, format);
     vsprintf(buffer, format, args);
-    l = fprintf(out_file, "%s\n", buffer); 
+    l = fprintf(out_file, "%s\r\n", buffer); 
     fflush(out_file);
     buffer[l - 1] = 0;
     LOG(6, cmd, ("---> %s", buffer));
@@ -934,7 +934,7 @@
 
     if (gotodir) {
 	cmd("CWD %s", gotodir);
-	if (!success()) {
+	if (!success() && strcmp(gotodir, "/") != 0) {
 		LOG(4, findtz, ("Cannot CWD %s for timezone", gotodir));
 		gotodir = 0;
 		goto dirdone;
