--- setup.py.orig	2024-07-06 14:55:44 UTC
+++ setup.py
@@ -15,6 +15,7 @@
 from distutils.command.build_ext import build_ext
 from distutils.command.install import install
 from distutils.command.install_lib import install_lib
+from distutils.command.build_scripts import build_scripts
 from distutils.spawn import find_executable
 
 cross_compiling = "_PYTHON_HOST_PLATFORM" in os.environ
@@ -33,7 +34,7 @@
 COMPILED_WITH_PYDEBUG = ('--with-pydebug' in sysconfig.get_config_var("CONFIG_ARGS"))
 
 # This global variable is used to hold the list of modules to be disabled.
-disabled_module_list = []
+disabled_module_list = [%%DISABLED_MODULES%%]
 
 exit_status = 0
 
@@ -1308,7 +1309,7 @@
                 sysroot = macosx_sdk_root()
                 f = os.path.join(sysroot, f[1:])
 
-        if os.path.exists(f) and not db_incs:
+        if os.path.exists(f):
             data = open(f).read()
             m = re.search(r"#s*define\s+HASHVERSION\s+2\s*", data)
             if m is not None:
@@ -1693,9 +1694,10 @@
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
@@ -2294,6 +2296,22 @@
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
@@ -2343,7 +2361,9 @@
           platforms = ["Many"],
 
           # Build info
-          cmdclass = {'build_ext':PyBuildExt, 'install':PyBuildInstall,
+          cmdclass = {'build_ext':PyBuildExt,
+                      'build_scripts':PyBuildScripts,
+                      'install':PyBuildInstall,
                       'install_lib':PyBuildInstallLib},
           # The struct module is defined here, because build_ext won't be
           # called unless there's at least one extension module defined.
@@ -2351,8 +2371,7 @@
 
           # Scripts to install
           scripts = ['Tools/scripts/pydoc', 'Tools/scripts/idle',
-                     'Tools/scripts/2to3',
-                     'Lib/smtpd.py']
+                     'Tools/scripts/2to3']
         )
     sys.exit(exit_status)
 
