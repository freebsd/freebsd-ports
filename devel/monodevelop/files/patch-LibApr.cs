--- src/addins/VersionControl/MonoDevelop.VersionControl.Subversion/MonoDevelop.VersionControl.Subversion/LibApr.cs.orig	2008-12-22 19:02:40.000000000 -0300
+++ src/addins/VersionControl/MonoDevelop.VersionControl.Subversion/MonoDevelop.VersionControl.Subversion/LibApr.cs	2008-12-22 19:02:53.000000000 -0300
@@ -65,7 +65,7 @@
 
 	public class LibApr0: LibApr
 	{
-		private const string aprlib = "libapr-0.so.0";
+		private const string aprlib = "libapr-1.so.4";
 		
 		public override void initialize() { apr_initialize (); }
 		public override IntPtr pool_create_ex (out IntPtr pool, IntPtr parent, IntPtr abort, IntPtr allocator) { return apr_pool_create_ex(out pool, parent, abort, allocator); }
