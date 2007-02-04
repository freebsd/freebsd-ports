--- mcs/class/Managed.Windows.Forms/System.Windows.Forms/MimeIcon.cs.orig	Wed Dec  6 15:06:58 2006
+++ mcs/class/Managed.Windows.Forms/System.Windows.Forms/MimeIcon.cs	Wed Dec  6 15:27:58 2006
@@ -394,7 +394,7 @@
 		[DllImport(librsvg)]
 		static extern IntPtr rsvg_pixbuf_from_file_at_size (string file_name, int  width, int  height, out IntPtr error);
 		
-		[DllImport(libgdk)]
+		[DllImport("libgdk_pixbuf-2.0.so")]
 		static extern bool gdk_pixbuf_save_to_buffer (IntPtr pixbuf, out IntPtr buffer, out UIntPtr buffer_size, string type, out IntPtr error, IntPtr option_dummy);
 		
 		[DllImport(libglib)]
