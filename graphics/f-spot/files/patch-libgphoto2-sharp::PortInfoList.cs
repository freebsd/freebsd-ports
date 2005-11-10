--- libgphoto2-sharp/PortInfoList.cs.orig	Sun Feb 20 16:37:12 2005
+++ libgphoto2-sharp/PortInfoList.cs	Mon Aug 22 22:01:37 2005
@@ -5,7 +5,7 @@
 {
 	public class PortInfoList : Object 
 	{
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_info_list_new (out IntPtr handle);
 		
 		public PortInfoList()
@@ -17,7 +17,7 @@
 			this.handle = new HandleRef (this, native);
 		}
 		
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_info_list_free (HandleRef handle);
 		
 		protected override void Cleanup ()
@@ -25,7 +25,7 @@
 			Error.CheckError (gp_port_info_list_free (this.Handle));
 		}
 		
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_info_list_load (HandleRef handle);
 
 		public void Load ()
@@ -36,7 +36,7 @@
 				throw Error.ErrorException (result);
 		}
 		
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_info_list_count (HandleRef handle);
 
 		public int Count()
@@ -44,7 +44,7 @@
 			return (int) Error.CheckError (gp_port_info_list_count (this.Handle));
 		}
 		
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal unsafe static extern ErrorCode gp_port_info_list_get_info (HandleRef handle, int n, out _PortInfo info);
 
 		public PortInfo GetInfo (int n)
@@ -56,7 +56,7 @@
 			return info;
 		}
 		
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_info_list_lookup_path (HandleRef handle, [MarshalAs(UnmanagedType.LPTStr)]string path);
 
 		public int LookupPath (string path)
@@ -64,7 +64,7 @@
 			return (int) Error.CheckError (gp_port_info_list_lookup_path(this.handle, path));
 		}
 		
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_info_list_lookup_name (HandleRef handle, string name);
 
 		public int LookupName(string name)
@@ -72,7 +72,7 @@
 			return (int) Error.CheckError (gp_port_info_list_lookup_name (this.Handle, name));
 		}
 		
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal unsafe static extern ErrorCode gp_port_info_list_append (HandleRef handle, _PortInfo info);
 
 		public int Append (PortInfo info)
