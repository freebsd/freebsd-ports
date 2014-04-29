--- freebsd-settings.py.orig	2006-07-14 12:14:52.000000000 +0200
+++ freebsd-settings.py	2014-04-29 10:49:21.918250680 +0200
@@ -10,6 +10,7 @@
 	global prefix
 	prefix = args.get('prefix','/usr/local')
 
+def get_include(args): return "%%LOCALBASE%%/include"
 def get_libpath(args): return prefix+"/lib"
 def get_pluginpath(args): return prefix+"/lib/yafray"
 def get_binpath(args): return prefix+"/bin"
@@ -22,7 +23,7 @@
 	if debug:
 		flags+=' -O3 -ffast-math -ggdb'
 	else:
-		flags+=' -O3 -ffast-math -fomit-frame-pointer'
+		flags+=' %%CXXFLAGS%%'
 	if arch!='':
 		flags+=' -march='+arch
 	if tune!='':
@@ -46,9 +47,9 @@
 class jpeg(globalinfo.library):
 	C_ID = 'JPEG'
 
-	def present(args): return os.path.exists("/usr/include/jpeglib.h")
-	def get_include(args): return []
-	def get_libpath(args): return []
+	def present(args): return os.path.exists("%%LOCALBASE%%/include/jpeglib.h")
+	def get_include(args): return ['%%LOCALBASE%%/include']
+	def get_libpath(args): return ['%%LOCALBASE%%/lib']
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
