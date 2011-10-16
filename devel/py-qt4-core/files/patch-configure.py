--- ./configure.py.orig	2011-08-02 06:18:51.000000000 -0300
+++ ./configure.py	2011-09-11 16:22:52.000000000 -0300
@@ -352,7 +352,7 @@
 
         # Note that the order in which we check is important for the
         # consolidated module - a module's dependencies must be checked first.
-        pyqt_modules.append("QtCore")
+        check_module("QtCore", "qobject.h", "new QObject()")
 
         check_module("QtGui", "qwidget.h", "new QWidget()")
         check_module("QtHelp", "qhelpengine.h", "new QHelpEngine(\"foo\")")
@@ -627,21 +627,6 @@
         if opts.staticplugins:
             sipconfig.inform("Unable to find the following static plugins: %s" % ", ".join(opts.staticplugins))
 
-        # Generate the QScintilla API file.
-        sipconfig.inform("Creating QScintilla API file...")
-        f = open("PyQt4.api", "w")
-
-        for m in pyqt_modules:
-            api = open(m + ".api")
-
-            for l in api:
-                f.write("PyQt4." + l)
-
-            api.close()
-            os.remove(m + ".api")
-
-        f.close()
-
     def _qpy_directories(self, mname, lib_name):
         """Return a 3-tuple of the directories containing the header files, the
         directory containing the library, and the name of the support library
@@ -732,6 +717,9 @@
         return libs, libdirs
 
     def module_installs(self):
+        if "QtCore" not in pyqt_modules:
+            return []
+
         return [os.path.join(src_dir, "__init__.py"), "pyqtconfig.py"]
 
     def qpy_libs(self):
@@ -861,40 +849,41 @@
             makefile.generate()
             tool.append("elementtree")
 
-        # Create the pyuic4 wrapper.  Use the GUI version on MacOS (so that
-        # previews work properly and normal console use will work anyway), but
-        # not on Windows (so that normal console use will work).
-        sipconfig.inform("Creating pyuic4 wrapper...")
-
-        if sys.platform == 'darwin':
-            gui = True
-            use_arch = opts.use_arch
-        else:
-            gui = False
-            use_arch = ''
+        if "QtCore" in pyqt_modules:
+            # Create the pyuic4 wrapper.  Use the GUI version on MacOS (so that
+            # previews work properly and normal console use will work anyway), but
+            # not on Windows (so that normal console use will work).
+            sipconfig.inform("Creating pyuic4 wrapper...")
+
+            if sys.platform == 'darwin':
+                gui = True
+                use_arch = opts.use_arch
+            else:
+                gui = False
+                use_arch = ''
 
-        # The pyuic directory may not exist if we are building away from the
-        # source directory.
-        try:
-            os.mkdir("pyuic")
-        except OSError:
-            pass
+            # The pyuic directory may not exist if we are building away from the
+            # source directory.
+            try:
+                os.mkdir("pyuic")
+            except OSError:
+                pass
 
-        uicdir=os.path.join(pyqt_modroot, "uic")
-        wrapper = sipconfig.create_wrapper(os.path.join(uicdir, "pyuic.py"), os.path.join("pyuic", "pyuic4"), gui, use_arch)
+            uicdir=os.path.join(pyqt_modroot, "uic")
+            wrapper = sipconfig.create_wrapper(os.path.join(uicdir, "pyuic.py"), os.path.join("pyuic", "pyuic4"), gui, use_arch)
 
-        sipconfig.inform("Creating pyuic4 Makefile...")
+            sipconfig.inform("Creating pyuic4 Makefile...")
 
-        makefile = sipconfig.PythonModuleMakefile(
-            configuration=sipcfg,
-            dstdir=uicdir,
-            srcdir=os.path.join(src_dir, "pyuic", "uic"),
-            dir="pyuic",
-            installs=[[os.path.basename(wrapper), opts.pyqtbindir]]
-        )
+            makefile = sipconfig.PythonModuleMakefile(
+                configuration=sipcfg,
+                dstdir=uicdir,
+                srcdir=os.path.join(src_dir, "pyuic", "uic"),
+                dir="pyuic",
+                installs=[[os.path.basename(wrapper), opts.pyqtbindir]]
+            )
 
-        makefile.generate()
-        tool.append("pyuic")
+            makefile.generate()
+            tool.append("pyuic")
 
         if "QtXml" in pyqt_modules:
             sipconfig.inform("Creating pylupdate4 Makefile...")
@@ -945,7 +934,7 @@
                     # We need to work out how to specify the right framework
                     # version.
                     link = "-framework Python"
-                elif "--enable-shared" in ducfg.get("CONFIG_ARGS", ""):
+                else:
                     if glob.glob("%s/lib/libpython%d.%d*" % (ducfg["exec_prefix"], py_major, py_minor)):
                         lib_dir_flag = quote("-L%s/lib" % ducfg["exec_prefix"])
                     elif glob.glob("%s/libpython%d.%d*" % (ducfg["LIBDIR"], py_major, py_minor)):
@@ -955,9 +944,6 @@
                         opts.designer_plugin = False
 
                     link = "%s -lpython%d.%d%s" % (lib_dir_flag, py_major, py_minor, abi)
-                else:
-                    sipconfig.inform("Qt Designer plugin disabled because Python library is static")
-                    opts.designer_plugin = False
 
                 pysh_lib = ducfg.get("LDLIBRARY", "")
 
@@ -2205,6 +2191,9 @@
         p.print_help()
         sys.exit(2)
 
+    # Avoid picking up the Qt3 headers instead
+    macros['INCDIR'] = '.'
+
     sipcfg.set_build_macros(macros)
 
     # Check Qt is what we need.
@@ -2234,9 +2223,9 @@
     installs=[(pyqt.module_installs(), pyqt_modroot)]
 
     if opts.api:
-        installs.append(("PyQt4.api", os.path.join(opts.qscidir, "api", "python")))
+        installs.append(("%s.api" % pyqt_modules[-1], os.path.join(opts.qscidir, "api", "python")))
 
-    xtra_modules = ["Qt"]
+    xtra_modules = []
 
     if opts.bigqt:
         xtra_modules.append("_qt")
@@ -2249,7 +2238,7 @@
 
     sipconfig.ParentMakefile(
         configuration=sipcfg,
-        subdirs=pyqt.qpy_libs() + pyqt_modules + xtra_modules + pyqt.tools(),
+        subdirs=pyqt.qpy_libs() + [pyqt_modules[-1]] + xtra_modules + pyqt.tools(),
         installs=installs
     ).generate()
 
