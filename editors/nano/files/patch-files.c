
$FreeBSD$

--- files.c.orig	Sun Oct  5 02:30:55 2003
+++ files.c	Sun Oct  5 02:35:06 2003
@@ -1701,16 +1701,17 @@
 #ifdef NANO_EXTRA
     static int did_cred = 0;
 #endif
+    static char *writepath = NULL;
 
 #if !defined(DISABLE_BROWSER) || (!defined(DISABLE_MOUSE) && defined(NCURSES_MOUSE_VERSION))
     currshortcut = writefile_list;
 #endif
 
-    answer = mallocstrcpy(answer, path);
+    writepath = mallocstrcpy(writepath, path);
 
     if (exiting && ISSET(TEMP_OPT)) {
 	if (filename[0] != '\0') {
-	    i = write_file(answer, 0, 0, 0);
+	    i = write_file(writepath, 0, 0, 0);
 	    display_main_list();
 	    return i;
 	} else {
@@ -1751,24 +1752,24 @@
 		    "%s%s%s", _("Write Selection to File"), formatstr, backupstr);
 	} else {
 	    if (append == 2)
-		i = statusq(1, writefile_list, answer, 0,
+		i = statusq(1, writefile_list, writepath, 0,
 		    "%s%s%s", _("File Name to Prepend to"), formatstr, backupstr);
 	    else if (append == 1)
-		i = statusq(1, writefile_list, answer, 0,
+		i = statusq(1, writefile_list, writepath, 0,
 		    "%s%s%s", _("File Name to Append to"), formatstr, backupstr);
 	    else
-		i = statusq(1, writefile_list, answer, 0,
+		i = statusq(1, writefile_list, writepath, 0,
 		    "%s%s%s", _("File Name to Write"), formatstr, backupstr);
 	}
 #else
 	if (append == 2)
-	    i = statusq(1, writefile_list, answer,
+	    i = statusq(1, writefile_list, writepath,
 		"%s", _("File Name to Prepend to"));
 	else if (append == 1)
-	    i = statusq(1, writefile_list, answer,
+	    i = statusq(1, writefile_list, writepath,
 		"%s", _("File Name to Append to"));
 	else
-	    i = statusq(1, writefile_list, answer,
+	    i = statusq(1, writefile_list, writepath,
 		"%s", _("File Name to Write"));
 #endif /* !NANO_SMALL */
 
