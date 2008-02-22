$FreeBSD$

--- plugins/org.eclipse.swt/Eclipse SWT/gtk/org/eclipse/swt/widgets/FileDialog.java.orig	2007-09-21 18:58:07.000000000 +0200
+++ plugins/org.eclipse.swt/Eclipse SWT/gtk/org/eclipse/swt/widgets/FileDialog.java	2008-02-05 20:49:58.000000000 +0100
@@ -378,29 +378,29 @@
 			stringBuffer.append ('.');
 		}
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
 			OS.gtk_file_chooser_set_filename (handle, ptr);
-			OS.g_free (ptr);
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
