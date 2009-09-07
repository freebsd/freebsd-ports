
$FreeBSD$

--- src/addins/VersionControl/MonoDevelop.VersionControl.Subversion/MonoDevelop.VersionControl.Subversion/LibSvnClient.cs.orig
+++ src/addins/VersionControl/MonoDevelop.VersionControl.Subversion/MonoDevelop.VersionControl.Subversion/LibSvnClient.cs
@@ -600,6 +600,7 @@
 	
 	public class LibSvnClient0 : LibSvnClient {
 		private const string svnclientlib = "libsvn_client-1.so.0";
+		private const string svnsubrlib = "libsvn_subr-1.so.0";
 		
 		public override void config_ensure (string config_dir, IntPtr pool)
 		{
@@ -843,11 +844,11 @@
 			return svn_client_prop_get (out value, name, target, ref revision, recurse, ctx, pool);
 		}
 		
-		[DllImport(svnclientlib)] static extern void svn_config_ensure (string config_dir, IntPtr pool);
-		[DllImport(svnclientlib)] static extern void svn_config_get_config (ref IntPtr cfg_hash, string config_dir, IntPtr pool);
-		[DllImport(svnclientlib)] static extern void svn_auth_open (out IntPtr auth_baton, IntPtr providers, IntPtr pool);
-		[DllImport(svnclientlib)] static extern void svn_auth_set_parameter (IntPtr auth_baton, string name, IntPtr value);
-		[DllImport(svnclientlib)] static extern IntPtr svn_auth_get_parameter (IntPtr auth_baton, string name);
+		[DllImport(svnsubrlib)] static extern void svn_config_ensure (string config_dir, IntPtr pool);
+		[DllImport(svnsubrlib)] static extern void svn_config_get_config (ref IntPtr cfg_hash, string config_dir, IntPtr pool);
+		[DllImport(svnsubrlib)] static extern void svn_auth_open (out IntPtr auth_baton, IntPtr providers, IntPtr pool);
+		[DllImport(svnsubrlib)] static extern void svn_auth_set_parameter (IntPtr auth_baton, string name, IntPtr value);
+		[DllImport(svnsubrlib)] static extern IntPtr svn_auth_get_parameter (IntPtr auth_baton, string name);
 		[DllImport(svnclientlib)] static extern void svn_client_get_simple_provider (IntPtr item, IntPtr pool);
 		[DllImport(svnclientlib)] static extern void svn_client_get_simple_prompt_provider (IntPtr item, svn_auth_simple_prompt_func_t prompt_func, IntPtr prompt_batton, [MarshalAs (UnmanagedType.SysInt)] int retry_limit, IntPtr pool);
 		[DllImport(svnclientlib)] static extern void svn_client_get_username_provider (IntPtr item, IntPtr pool);
@@ -880,7 +881,7 @@
 		                                                               IntPtr receiver_baton,
 		                                                               IntPtr ctx, IntPtr pool);
 		
-		[DllImport(svnclientlib)] static extern IntPtr svn_time_from_cstring (out long aprtime, string time, IntPtr pool);
+		[DllImport(svnsubrlib)] static extern IntPtr svn_time_from_cstring (out long aprtime, string time, IntPtr pool);
 		
 		[DllImport(svnclientlib)] static extern IntPtr svn_client_url_from_path (ref IntPtr url, string path_or_url, IntPtr pool);
 		
@@ -889,11 +890,11 @@
 		                                                                ref Rev revision,
 		                                                                IntPtr ctx, IntPtr pool);
 		
-		[DllImport(svnclientlib)] static extern IntPtr svn_stream_create (IntPtr baton, IntPtr pool);
+		[DllImport(svnsubrlib)] static extern IntPtr svn_stream_create (IntPtr baton, IntPtr pool);
 		
 		//[DllImport(svnclientlib)] static extern IntPtr svn_stream_set_read (IntPtr stream, svn_readwrite_fn_t reader);
 		
-		[DllImport(svnclientlib)] static extern IntPtr svn_stream_set_write (IntPtr stream, svn_readwrite_fn_t writer);
+		[DllImport(svnsubrlib)] static extern IntPtr svn_stream_set_write (IntPtr stream, svn_readwrite_fn_t writer);
 		
 		[DllImport(svnclientlib)] static extern IntPtr svn_client_update (IntPtr result_rev, string path, ref Rev revision,
 		                                                                  int recurse, IntPtr ctx, IntPtr pool);
