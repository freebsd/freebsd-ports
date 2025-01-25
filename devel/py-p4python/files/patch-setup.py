--- setup.py.orig	2024-12-30 02:45:50 UTC
+++ setup.py
@@ -245,7 +245,7 @@ class p4build_ext(build_ext_module):
                     pathToFile = os.path.join(p, "openssl")
                     if os.path.exists(pathToFile) and os.access(pathToFile, os.X_OK):
                         entry = subprocess.check_output("ldd {0} | grep libssl".format(pathToFile),
-                                                        executable="/bin/bash", shell="True")
+                                                        executable="/bin/sh", shell="True")
                         if entry is not False:
                             libpath = os.path.dirname(entry.split()[2])
 
@@ -277,23 +277,10 @@ class p4build_ext(build_ext_module):
 
         ssl_ver = ""
         if not p4_ssl_dir:
-            if (not self.ssl) and (sys.platform == "linux" or sys.platform == "linux2"):
+            if (not self.ssl):
                 # check for a version of SSL already installed via 'openssl version'
                 self.ssl, ssl_ver = self.check_installed_ssl()  # return libpath or None
 
-                # we only support 1.0.2 or 1.1.1 using 2019.1 p4api
-                if not (("1.0.2" in ssl_ver) or ("1.1.1" in ssl_ver) or ("3.0" in ssl_ver)):
-                    self.ssl = ""
-
-                if not self.ssl:
-                    # try downloading and building ssl
-                    if self.is_super():
-                        (self.ssl, ssl_src, ssl_tarball, loaded_ssl_from_ftp) = self.build_ssl_lib(ssl_ver)
-                        p4_ssl_dir = self.ssl
-                        p4_ssl_ver = ssl_ver
-                    else:
-                        print("must be root to build and install SSL")
-
         if not self.ssl:
             print("***********************************************", file=sys.stderr)
             print("** Cannot build P4Python without SSL support **", file=sys.stderr)
@@ -315,7 +302,7 @@ class p4build_ext(build_ext_module):
         p4_api_dir = self.apidir
 
         try:
-            apiVersion = VersionInfo(p4_api_dir)
+            apiVersion = VersionInfo(".")
             releaseVersion = VersionInfo(".")
         except IOError:
             print("Cannot find Version file in API dir {0}.".format(p4_api_dir))
@@ -336,9 +323,18 @@ class p4build_ext(build_ext_module):
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
@@ -471,7 +467,7 @@ def cleanup_api(api_dir, tarball):
 
 
 # declare some evil globals
-p4_api_dir = ""
+p4_api_dir = "%%LOCALBASE%%"
 p4_ssl_dir = ""
 p4_ssl_ver = ""
 ssl_tarball = ""
