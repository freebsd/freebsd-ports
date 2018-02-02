--- setup.py.orig	2018-02-02 16:50:17 UTC
+++ setup.py
@@ -102,7 +102,12 @@ class P4APIFtp:
 
         elif system == "FreeBSD":
             platform_str += "freebsd"
-            release = uname.release
+            if sys.version_info.major == 3:
+                release = uname.release
+            elif sys.version_info.major == 2:
+                release = uname[2]
+            else:
+                raise Exception("Unknown python version %s" % sys.version)
 
             value = int(''.join(itertools.takewhile(lambda s: s.isdigit(), release)))
 
@@ -217,6 +222,8 @@ class VersionInfo:
     verFile = os.path.join(p4ApiDir, "sample", "Version")
     if not os.path.exists(verFile):
         verFile = os.path.join(p4ApiDir, "Version")
+        if not os.path.exists(verFile):
+            verFile = os.path.join(p4ApiDir, "share", "examples", "p4api", "Version")
     input = open(verFile)
     for line in input:
       for pattern, handler in self.patterns:
@@ -398,9 +405,16 @@ class PlatformInfo:
         arch = self.architecture(unameOut[4])
       elif unameOut[0] == 'FreeBSD':
         unix = "FREEBSD"
-        release = unameOut[2][0]
-        if release == '5':
-            release += unameOut[2][2]
+        if sys.version_info.major == 3:
+            release = unameOut.release.split(".")[0]
+            if release == '5':
+                release += unameOut.release.split(".")[1]
+        elif sys.version_info.major == 2:
+            release = unameOut[2].split(".")[0]
+            if release == '5':
+                release += unameOut[2].split(".")[1]
+        else:
+            raise Exception("Unknown python version %s" % sys.version)
 
         arch = self.architecture(unameOut[4])
       elif unameOut[0] == 'CYGWIN_NT-5.1':
@@ -475,8 +489,16 @@ def do_setup(p4_api_dir, ssl):
     else:
       print ("API Release %s.%s" % (ryear, rversion))
 
-    inc_path = [p4_api_dir, os.path.join(p4_api_dir, "include", "p4")]
-    lib_path = [p4_api_dir, os.path.join(p4_api_dir, "lib")]
+    inc_dir = os.path.join(p4_api_dir, "include", "p4")
+    if not os.path.exists(inc_dir):
+        inc_dir = os.path.join(p4_api_dir, "include", "perforce")
+
+    lib_dir = os.path.join(p4_api_dir, "lib", "perforce")
+    if not os.path.exists(lib_dir):
+        lib_dir = os.path.join(p4_api_dir, "lib")
+
+    inc_path = [p4_api_dir, inc_dir]
+    lib_path = [p4_api_dir, lib_dir]
     if ssl:
         lib_path.append( ssl )
 
@@ -608,7 +630,7 @@ if __name__ == "__main__":
         if os.path.exists(distdir):
             shutil.rmtree(distdir, False, force_remove_file)
 
-    p4_api_dir = get_api_dir()
+    p4_api_dir = "%%LOCALBASE%%"
 
     ssl = None
     if '--ssl' in sys.argv:
