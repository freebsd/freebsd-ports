--- freebsd-settings.py.orig	Sat Sep 23 00:21:17 2006
+++ freebsd-settings.py	Sat Sep 23 00:21:29 2006
@@ -10,6 +10,7 @@
 	global prefix
 	prefix = args.get('prefix','/usr/local')
 
+def get_include(args): return prefix+"/usr/local/include"
 def get_libpath(args): return prefix+"/lib"
 def get_pluginpath(args): return prefix+"/lib/yafray"
 def get_binpath(args): return prefix+"/bin"
@@ -46,9 +47,9 @@
 class jpeg(globalinfo.library):
 	C_ID = 'JPEG'
 
-	def present(args): return os.path.exists("/usr/include/jpeglib.h")
-	def get_include(args): return []
-	def get_libpath(args): return []
+	def present(args): return os.path.exists("/usr/local/include/jpeglib.h")
+	def get_include(args): return ['/usr/local/include']
+	def get_libpath(args): return ['/usr/local/lib']
 	def get_libs(args): return ['jpeg']
 
 class pthread(globalinfo.library):
@@ -73,7 +74,7 @@
 	def present(args): return True
 	def get_include(args): return []
 	def get_libpath(args): return []
-	def get_libs(args): return ['dl']
+	def get_libs(args): return ['']
 
 def derive_shared_env(common_env):
 	return common_env.Copy()
