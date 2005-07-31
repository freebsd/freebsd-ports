--- eb/book.c.orig	Sun May 29 09:42:54 2005
+++ eb/book.c	Sun Jul 31 16:06:39 2005
@@ -658,8 +658,11 @@
 	    error_code = EB_ERR_FAIL_READ_CAT;
 	    break;
 	}
-	if (*(buffer + 4) == '\0')
+	if (*(buffer + 4) == '\0') {
+	    strcpy(subbook->sound_file_name, subbook->text_file_name);
+	    strcpy(subbook->graphic_file_name, subbook->text_file_name);
 	    continue;
+	}
 
 	/*
 	 * Set a text file name and its compression hint.
