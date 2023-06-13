--- setup.py.orig	2021-06-02 16:51:18.000000000 +0200
+++ setup.py	2023-06-09 19:32:17.812240000 +0200
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
 
 def add_dir_to_list(dirlist, dir):
     """Add the directory 'dir' to the list 'dirlist' (at the front) if
@@ -886,7 +887,10 @@
             missing.append('_ssl')
 
         # find out which version of OpenSSL we have
+        openssl_major = -1
         openssl_ver = 0
+        openssl_major_re = re.compile(
+            '^\s*#\s*define\s+OPENSSL_VERSION_MAJOR\s+([0-9]+)' )
         openssl_ver_re = re.compile(
             '^\s*#\s*define\s+OPENSSL_VERSION_NUMBER\s+(0x[0-9a-fA-F]+)' )
 
@@ -900,17 +904,22 @@
             try:
                 incfile = open(name, 'r')
                 for line in incfile:
+                    m = openssl_major_re.match(line)
+                    if m:
+                        openssl_major = int(m.group(1))
                     m = openssl_ver_re.match(line)
                     if m:
-                        openssl_ver = eval(m.group(1))
+                        openssl_ver = int(m.group(1), 0)
             except IOError, msg:
                 print "IOError while reading opensshv.h:", msg
                 pass
 
+        min_openssl_major = 1
         min_openssl_ver = 0x00907000
         have_any_openssl = ssl_incs is not None and ssl_libs is not None
         have_usable_openssl = (have_any_openssl and
-                               openssl_ver >= min_openssl_ver)
+                               (openssl_ver >= min_openssl_ver or
+                                openssl_major >= min_openssl_major))
 
         if have_any_openssl:
             if have_usable_openssl:
@@ -935,7 +944,9 @@
                             depends = ['md5.h']) )
 
         min_sha2_openssl_ver = 0x00908000
-        if COMPILED_WITH_PYDEBUG or openssl_ver < min_sha2_openssl_ver:
+        if COMPILED_WITH_PYDEBUG or \
+           (openssl_ver < min_sha2_openssl_ver and
+            openssl_major < min_openssl_major):
             # OpenSSL doesn't do these until 0.9.8 so we'll bring our own hash
             exts.append( Extension('_sha256', ['sha256module.c']) )
             exts.append( Extension('_sha512', ['sha512module.c']) )
@@ -1284,7 +1295,7 @@
                 sysroot = macosx_sdk_root()
                 f = os.path.join(sysroot, f[1:])
 
-        if os.path.exists(f) and not db_incs:
+        if os.path.exists(f):
             data = open(f).read()
             m = re.search(r"#s*define\s+HASHVERSION\s+2\s*", data)
             if m is not None:
@@ -1669,9 +1680,10 @@
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
@@ -2294,6 +2306,22 @@
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
@@ -2343,7 +2371,9 @@
           platforms = ["Many"],
 
           # Build info
-          cmdclass = {'build_ext':PyBuildExt, 'install':PyBuildInstall,
+          cmdclass = {'build_ext':PyBuildExt,
+                      'build_scripts':PyBuildScripts,
+                      'install':PyBuildInstall,
                       'install_lib':PyBuildInstallLib},
           # The struct module is defined here, because build_ext won't be
           # called unless there's at least one extension module defined.
@@ -2351,8 +2381,7 @@
 
           # Scripts to install
           scripts = ['Tools/scripts/pydoc', 'Tools/scripts/idle',
-                     'Tools/scripts/2to3',
-                     'Lib/smtpd.py']
+                     'Tools/scripts/2to3']
         )
 
 # --install-platlib
