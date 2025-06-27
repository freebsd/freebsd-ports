--- setup.py.orig	2025-06-27 04:06:21 UTC
+++ setup.py
@@ -305,7 +305,7 @@ class p4build_ext(build_ext_module):
 
         ssl_ver = ""
         if not p4_ssl_dir:
-            if (not self.ssl) and (sys.platform == "linux" or sys.platform == "linux2"):
+            if (not self.ssl):
                 # check for a version of SSL already installed via 'openssl version'
                 self.ssl, ssl_ver = self.check_installed_ssl()  # return libpath or None
 
@@ -346,7 +346,7 @@ class p4build_ext(build_ext_module):
         p4_api_dir = self.apidir
 
         try:
-            apiVersion = VersionInfo(p4_api_dir)
+            apiVersion = VersionInfo(".")
             releaseVersion = VersionInfo(".")
         except IOError:
             print("Cannot find Version file in API dir {0}.".format(p4_api_dir))
@@ -367,8 +367,8 @@ class p4build_ext(build_ext_module):
         #spawn._nt_quote_args = monkey_nt_quote_args
 
         # add the paths for p4 headers and library
-        inc_path = [str(os.path.join(p4_api_dir, "include", "p4"))]
-        lib_path = [str(os.path.join(p4_api_dir, "lib")), str(p4_ssl_dir)]
+        inc_path = [str(os.path.join(p4_api_dir, "include", "perforce"))]
+        lib_path = [str(os.path.join(p4_api_dir, "lib", "perforce")), str(p4_ssl_dir)]
 
         # check if the interpreter is mayapy.exe
         namedir = os.path.dirname(os.path.dirname(sys.executable))
@@ -502,7 +502,7 @@ def cleanup_api(api_dir, tarball):
 
 
 # declare some evil globals
-p4_api_dir = ""
+p4_api_dir = "%%LOCALBASE%%"
 p4_ssl_dir = ""
 p4_ssl_ver = ""
 ssl_tarball = ""
