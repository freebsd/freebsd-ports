--- gtk/org/eclipse/swt/widgets/DirectoryDialog.java.orig	2008-08-05 22:10:38.000000000 -0400
+++ gtk/org/eclipse/swt/widgets/DirectoryDialog.java	2008-08-05 22:11:13.000000000 -0400
@@ -145,15 +145,15 @@
 		}
 		stringBuffer.append (filterPath);
 		byte [] buffer = Converter.wcsToMbcs (null, stringBuffer.toString (), true);
+		byte [] bufspc = new byte[1024];
 		/*
 		* Bug in GTK. GtkFileChooser may crash on GTK versions 2.4.10 to 2.6
 		* when setting a file name that is not a true canonical path. 
 		* The fix is to use the canonical path.
 		*/
-		int /*long*/ ptr = OS.realpath (buffer, null);
+		int /*long*/ ptr = OS.realpath (buffer, bufspc);
 		if (ptr != 0) {
 			OS.gtk_file_chooser_set_current_folder (handle, ptr);
-			OS.g_free (ptr);
 		}
 	}
 	if (message.length () > 0) {
