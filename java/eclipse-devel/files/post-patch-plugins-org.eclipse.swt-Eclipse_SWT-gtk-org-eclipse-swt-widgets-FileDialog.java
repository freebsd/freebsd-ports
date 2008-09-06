--- gtk/org/eclipse/swt/widgets/FileDialog.java.orig	2008-08-03 13:33:18.285923896 -0400
+++ gtk/org/eclipse/swt/widgets/FileDialog.java	2008-08-03 13:36:14.527006003 -0400
@@ -474,42 +474,42 @@
 			}
 			stringBuffer.append (fileName);
 			byte [] buffer = Converter.wcsToMbcs (null, stringBuffer.toString (), true);
+			byte [] bufspc = new byte[1024];
 			/*
 			* Bug in GTK. GtkFileChooser may crash on GTK versions 2.4.10 to 2.6
 			* when setting a file name that is not a true canonical path. 
 			* The fix is to use the canonical path.
 			*/
-			int /*long*/ ptr = OS.realpath (buffer, null);
+			int /*long*/ ptr = OS.realpath (buffer, bufspc);
 			if (ptr != 0) {
 				OS.gtk_file_chooser_set_filename (handle, ptr);
-				OS.g_free (ptr);
 			}
 		} else {
 			byte [] buffer = Converter.wcsToMbcs (null, stringBuffer.toString (), true);
+			byte [] bufspc = new byte[1024];
 			/*
 			* Bug in GTK. GtkFileChooser may crash on GTK versions 2.4.10 to 2.6
 			* when setting a file name that is not a true canonical path. 
 			* The fix is to use the canonical path.
 			*/
-			int /*long*/ ptr = OS.realpath (buffer, null);
+			int /*long*/ ptr = OS.realpath (buffer, bufspc);
 			if (ptr != 0) {
 				OS.gtk_file_chooser_set_current_folder (handle, ptr);
-				OS.g_free (ptr);
 			}
 		}
 	} else {
 		if (fileName.length () > 0) {
 			if (fileName.charAt (0) == SEPARATOR) {
 				byte [] buffer = Converter.wcsToMbcs (null, fileName, true);
+				byte [] bufspc = new byte[1024];
 				/*
 				* Bug in GTK. GtkFileChooser may crash on GTK versions 2.4.10 to 2.6
 				* when setting a file name that is not a true canonical path. 
 				* The fix is to use the canonical path.
 				*/
-				int /*long*/ ptr = OS.realpath (buffer, null);
+				int /*long*/ ptr = OS.realpath (buffer, bufspc);
 				if (ptr != 0) {
 					OS.gtk_file_chooser_set_filename (handle, ptr);
-					OS.g_free (ptr);
 				}
 			}
 		}
