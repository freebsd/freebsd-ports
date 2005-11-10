--- libgphoto2-sharp/ErrorCodes.cs.orig	Sun Feb 20 16:37:12 2005
+++ libgphoto2-sharp/ErrorCodes.cs	Mon Aug 22 22:15:18 2005
@@ -79,7 +79,7 @@
 		[DllImport ("libgphoto2.so")]
 		internal static extern IntPtr gp_result_as_string (ErrorCode result);
 		
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern IntPtr gp_port_result_as_string (ErrorCode result);
 	}
 	
