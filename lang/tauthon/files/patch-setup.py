# Description: Partial script installation backport from Python3
# Submitted by: mva

# Description: Some modules are installed via other ports

# Description: ossaudiodev detection fix backport

--- setup.py.orig	2017-04-22 03:42:03 UTC
+++ setup.py
@@ -15,6 +15,7 @@ from distutils.core import Extension, se
 from distutils.command.build_ext import build_ext
 from distutils.command.install import install
 from distutils.command.install_lib import install_lib
+from distutils.command.build_scripts import build_scripts
 from distutils.spawn import find_executable
 
 cross_compiling = "_PYTHON_HOST_PLATFORM" in os.environ
@@ -33,7 +34,7 @@ host_platform = get_platform()
 COMPILED_WITH_PYDEBUG = ('--with-pydebug' in sysconfig.get_config_var("CONFIG_ARGS"))
 
 # This global variable is used to hold the list of modules to be disabled.
-disabled_module_list = []
+disabled_module_list = ["_bsddb", "_sqlite3", "_tkinter", "gdbm", "mpz"]
 
 def add_dir_to_list(dirlist, dir):
     """Add the directory 'dir' to the list 'dirlist' (at the front) if
@@ -1234,7 +1235,7 @@ class PyBuildExt(build_ext):
                 sysroot = macosx_sdk_root()
                 f = os.path.join(sysroot, f[1:])
 
-        if os.path.exists(f) and not db_incs:
+        if os.path.exists(f):
             data = open(f).read()
             m = re.search(r"#s*define\s+HASHVERSION\s+2\s*", data)
             if m is not None:
@@ -1624,9 +1625,10 @@ class PyBuildExt(build_ext):
         else:
             missing.append('linuxaudiodev')
 
-        if (host_platform in ('linux2', 'freebsd4', 'freebsd5', 'freebsd6',
-                        'freebsd7', 'freebsd8')
-            or host_platform.startswith("gnukfreebsd")):
+# Initial backport of https://hg.python.org/cpython/rev/50f1922bc1d5
+
+        if any(sys.platform.startswith(prefix)
+               for prefix in ("linux", "freebsd", "gnukfreebsd")):
             exts.append( Extension('ossaudiodev', ['ossaudiodev.c']) )
         else:
             missing.append('ossaudiodev')
@@ -2200,6 +2202,22 @@ class PyBuildInstallLib(install_lib):
     def is_chmod_supported(self):
         return hasattr(os, 'chmod')
 
+class PyBuildScripts(build_scripts):
+    def copy_scripts(self):
+        outfiles = build_scripts.copy_scripts(self)
+        fullversion = '{0[0]}.{0[1]}'.format(sys.version_info)
+        newoutfiles = []
+        for filename in outfiles:
+            if filename.endswith('2to3'):
+                newfilename = filename + '-' + fullversion
+            else:
+                newfilename = filename + fullversion
+            log.info('renaming {} to {}'.format(filename, newfilename))
+            os.rename(filename, newfilename)
+            newoutfiles.append(newfilename)
+        return newoutfiles
+
+
 SUMMARY = """
 Python is an interpreted, interactive, object-oriented programming
 language. It is often compared to Tcl, Perl, Scheme or Java.
@@ -2245,7 +2263,9 @@ def main():
           platforms = ["Many"],
 
           # Build info
-          cmdclass = {'build_ext':PyBuildExt, 'install':PyBuildInstall,
+          cmdclass = {'build_ext':PyBuildExt,
+                      'build_scripts':PyBuildScripts,
+                      'install':PyBuildInstall,
                       'install_lib':PyBuildInstallLib},
           # The struct module is defined here, because build_ext won't be
           # called unless there's at least one extension module defined.
@@ -2253,8 +2273,7 @@ def main():
 
           # Scripts to install
           scripts = ['Tools/scripts/pydoc', 'Tools/scripts/idle',
-                     'Tools/scripts/2to3',
-                     'Lib/smtpd.py']
+                     'Tools/scripts/2to3']
         )
 
 # --install-platlib
