--- setup.py.orig	2023-04-04 23:31:58 UTC
+++ setup.py
@@ -243,7 +243,7 @@ class p4build_ext(build_ext_module):
                     pathToFile = os.path.join(p, "openssl")
                     if os.path.exists(pathToFile) and os.access(pathToFile, os.X_OK):
                         entry = subprocess.check_output("ldd {0} | grep libssl".format(pathToFile),
-                                                        executable="/bin/bash", shell="True")
+                                                        executable="/bin/sh", shell="True")
                         if entry is not False:
                             libpath = os.path.dirname(entry.split()[2])
 
@@ -275,7 +275,7 @@ class p4build_ext(build_ext_module):
 
         ssl_ver = ""
         if not p4_ssl_dir:
-            if (not self.ssl) and (sys.platform == "linux" or sys.platform == "linux2"):
+            if (not self.ssl):
                 # check for a version of SSL already installed via 'openssl version'
                 self.ssl, ssl_ver = self.check_installed_ssl()  # return libpath or None
 
@@ -313,7 +313,7 @@ class p4build_ext(build_ext_module):
         p4_api_dir = self.apidir
 
         try:
-            apiVersion = VersionInfo(p4_api_dir)
+            apiVersion = VersionInfo(".")
             releaseVersion = VersionInfo(".")
         except IOError:
             print("Cannot find Version file in API dir {0}.".format(p4_api_dir))
@@ -334,9 +334,18 @@ class p4build_ext(build_ext_module):
         #spawn._nt_quote_args = monkey_nt_quote_args
 
         # add the paths for p4 headers and library
-        inc_path = [str(os.path.join(p4_api_dir, "include", "p4"))]
-        lib_path = [str(os.path.join(p4_api_dir, "lib")), str(p4_ssl_dir)]
+        inc_dir = os.path.join(p4_api_dir, "include", "p4")
+        if not os.path.exists(inc_dir):
+            inc_dir = os.path.join(p4_api_dir, "include", "perforce")
 
+        lib_dir = os.path.join(p4_api_dir, "lib", "perforce")
+        if not os.path.exists(lib_dir):
+            lib_dir = os.path.join(p4_api_dir, "lib")
+
+        inc_path = [p4_api_dir, inc_dir]
+        lib_path = [p4_api_dir, lib_dir]
+
+
         # check if the interpreter is mayapy.exe
         namedir = os.path.dirname(os.path.dirname(sys.executable))
         if "maya" in namedir.lower():
@@ -469,7 +478,7 @@ def cleanup_api(api_dir, tarball):
 
 
 # declare some evil globals
-p4_api_dir = ""
+p4_api_dir = "%%LOCALBASE%%"
 p4_ssl_dir = ""
 p4_ssl_ver = ""
 ssl_tarball = ""
