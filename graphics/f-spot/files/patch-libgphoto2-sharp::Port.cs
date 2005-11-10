--- libgphoto2-sharp/Port.cs.orig	Wed Apr 27 15:38:18 2005
+++ libgphoto2-sharp/Port.cs	Mon Aug 22 22:12:52 2005
@@ -83,49 +83,49 @@
 		PortPrivateLibrary *pl;
 		PortPrivateCore *pc;
 
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_new (out _Port *port);
 
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_free (_Port *port);
 
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_set_info (_Port *port, ref _PortInfo info);
 
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_get_info (_Port *port, out _PortInfo info);
 
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_open (_Port *port);
 
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_close (_Port *port);
 
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_read (_Port *port, [MarshalAs(UnmanagedType.LPTStr)] byte[] data, int size);
 
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_write (_Port *port, [MarshalAs(UnmanagedType.LPTStr)] byte[] data, int size);
 
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_get_settings (_Port *port, out PortSettings settings);
 
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_set_settings (_Port *port, PortSettings settings);
 
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_get_timeout (_Port *port, int *timeout);
 
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_set_timeout (_Port *port, int timeout);
 
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_get_pin (_Port *port, Pin pin, Level *level);
 
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_set_pin (_Port *port, Pin pin, Level level);
 
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern char* gp_port_get_error (_Port *port);
 
 		//[DllImport ("libgphoto2.so")]
@@ -135,7 +135,7 @@
 
 	public class Port : Object
 	{
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_new (out IntPtr port);
 
 		public Port()
@@ -147,7 +147,7 @@
 			this.handle = new HandleRef (this, native);
 		}
 		
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_free (HandleRef port);
 		
 		protected override void Cleanup ()
@@ -155,7 +155,7 @@
 			Error.CheckError (gp_port_free (this.handle));
 		}
 
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_set_info (HandleRef port, ref _PortInfo info);
 
 		public void SetInfo (PortInfo info)
@@ -163,7 +163,7 @@
 		Error.CheckError (gp_port_set_info (this.Handle, ref info.Handle));
 		}
 		
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_get_info (HandleRef port, out _PortInfo info);
 
 		public PortInfo GetInfo ()
@@ -175,7 +175,7 @@
 			return info;
 		}
 		
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_open (HandleRef port);
 
 		public void Open ()
@@ -183,7 +183,7 @@
 			Error.CheckError (gp_port_open (this.Handle));
 		}
 		
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_close (HandleRef port);
 
 		public void Close ()
@@ -191,7 +191,7 @@
 			Error.CheckError (gp_port_close (this.Handle));
 		}
 		
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_read (HandleRef port, [MarshalAs(UnmanagedType.LPTStr)] byte[] data, int size);
 
 		public byte[] Read (int size)
@@ -203,7 +203,7 @@
 			return data;
 		}
 		
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_write (HandleRef port, [MarshalAs(UnmanagedType.LPTStr)] byte[] data, int size);
 
 		public void Write (byte[] data)
@@ -212,7 +212,7 @@
 		}
 		
 
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_set_settings (HandleRef port, PortSettings settings);
 
 		public void SetSettings (PortSettings settings)
@@ -220,7 +220,7 @@
 			Error.CheckError (gp_port_set_settings (this.Handle, settings));
 		}
 		
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_get_settings (HandleRef port, out PortSettings settings);
 
 		public PortSettings GetSettings ()
@@ -232,10 +232,10 @@
 			return settings;
 		}
 		
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_get_timeout (HandleRef port, out int timeout);
 
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_set_timeout (HandleRef port, int timeout);
 
 		public int Timeout
@@ -252,13 +252,13 @@
 			}
 		}
 		
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_get_pin (HandleRef port, Pin pin, out Level level);
 
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern ErrorCode gp_port_set_pin (HandleRef port, Pin pin, Level level);
 
-		[DllImport ("libgphoto2.so")]
+		[DllImport ("libgphoto2_port.so")]
 		internal static extern string gp_port_get_error (HandleRef port);
 	}
 }
