--- configure.py.orig	Mon Jul 30 18:11:39 2007
+++ configure.py	Fri Aug 10 22:22:34 2007
@@ -29,6 +29,10 @@
 
 import sipconfig
 
+# FreeBSD check and which component (port)
+freebsd, freebsd_port = False, ''
+if sys.platform[:-1] == 'freebsd': freebsd = True
+if freebsd: freebsd_port = os.environ['PYQT4_COMPONENT']
 
 # Initialise the globals.
 pyqt_version = 0x040300
@@ -62,7 +66,6 @@
 dbuslibdirs = []
 dbuslibs = []
 
-
 # Under Windows qmake and the Qt DLLs must be into the system PATH otherwise
 # the dynamic linker won't be able to resolve the symbols.  On other systems we
 # assume we can just run qmake by using its full pathname.
@@ -276,14 +279,23 @@
         elif sipcfg.universal:
             sipconfig.inform("QtDesigner module disabled with universal binaries.")
         else:
-            check_module("QtDesigner", "QExtensionFactory",
-                    "new QExtensionFactory()")
+            if freebsd:
+                if freebsd_port.startswith('designer'):
+                    check_module("QtDesigner", "QExtensionFactory",
+                            "new QExtensionFactory()")
+            else:
+                 check_module("QtDesigner", "QExtensionFactory",
+                         "new QExtensionFactory()")
 
         check_module("QAxContainer", "qaxobject.h", "new QAxObject()",
                 extra_libs=["QAxContainer"])
 
         if os.path.isdir("dbus"):
-            check_dbus()
+            if freebsd:
+                if freebsd_port == 'dbus': 
+                    check_dbus()
+            else: 
+                check_dbus()
 
     def code(self):
         cons_xtra_incdirs = []
@@ -304,6 +316,10 @@
             cons_xtra_libs.extend(sp_libs)
 
             generate_code("QtCore")
+        elif freebsd:
+            if freebsd_port == 'core':
+                generate_code("QtCore", extra_include_dirs=sp_incdirs,
+                            extra_lib_dirs=sp_libdirs, extra_libs=sp_libs)
         else:
             generate_code("QtCore", extra_include_dirs=sp_incdirs,
                         extra_lib_dirs=sp_libdirs, extra_libs=sp_libs)
@@ -472,19 +488,28 @@
             sipconfig.inform("Unable to find the following static plugins: %s" % ", ".join(opts.staticplugins))
 
         # Generate the QScintilla API file.
-        sipconfig.inform("Creating QScintilla API file...")
-        f = open("PyQt4.api", "w")
+        if freebsd:
+            if not freebsd_port in ('dbus', 'designerplugin', 'demo', 'doc'):
+                sipconfig.inform("Creating QScintilla API file...")
+                
+        else:
+            sipconfig.inform("Creating QScintilla API file...")
 
-        for m in pyqt_modules:
-            api = open(m + ".api")
+        if not freebsd:
+            # aggregating like below would kill packaging
+            # instead the port installs the seperate module APIs
+            f = open("PyQt4.api", "w")
 
-            for l in api:
-                f.write("PyQt4." + l)
+            for m in pyqt_modules:
+                api = open(m + ".api")
 
-            api.close()
-            os.remove(m + ".api")
+                for l in api:
+                    f.write("PyQt4." + l)
 
-        f.close()
+                api.close()
+                os.remove(m + ".api")
+
+            f.close()
 
     def _static_plugins(self, mname):
         """Return a tuple of the libraries (in platform neutral format) and the
@@ -555,7 +580,13 @@
         return libs, libdirs
 
     def module_installs(self):
-        return ["__init__.py", "pyqtconfig.py"]
+        if freebsd:
+            if freebsd_port == 'core':
+                return ["__init__.py", "pyqtconfig.py"]
+            else:
+                return []
+        else:
+            return ["__init__.py", "pyqtconfig.py"]
 
     def qpylibs(self):
         # See which QPy libraries to build.
@@ -641,23 +672,43 @@
         # Create the pyuic4 wrapper.  Use the GUI version on MacOS (so that
         # previews work properly and normal console use will work anyway), but
         # not on Windows (so that normal console use will work).
-        sipconfig.inform("Creating pyuic4 wrapper...")
+        if freebsd:
+            if freebsd_port == 'core':
+                sipconfig.inform("Creating pyuic4 wrapper...")
+                 
+                uicdir=os.path.join(pyqt_modroot, "uic")
+                wrapper = sipconfig.create_wrapper(os.path.join(uicdir, "pyuic.py"), os.path.join("pyuic", "pyuic4"), (sys.platform == "darwin"))
+                 
+                sipconfig.inform("Creating pyuic4 Makefile...")
+                 
+                makefile = sipconfig.PythonModuleMakefile(
+                    configuration=sipcfg,
+                    dstdir=uicdir,
+                    srcdir="uic",
+                    dir="pyuic",
+                    installs=[[os.path.basename(wrapper), opts.pyqtbindir]]
+                )
+                  
+                makefile.generate()
+                tool.append("pyuic")
+        else:
+            sipconfig.inform("Creating pyuic4 wrapper...")
 
-        uicdir=os.path.join(pyqt_modroot, "uic")
-        wrapper = sipconfig.create_wrapper(os.path.join(uicdir, "pyuic.py"), os.path.join("pyuic", "pyuic4"), (sys.platform == "darwin"))
+            uicdir=os.path.join(pyqt_modroot, "uic")
+            wrapper = sipconfig.create_wrapper(os.path.join(uicdir, "pyuic.py"), os.path.join("pyuic", "pyuic4"), (sys.platform == "darwin"))
 
-        sipconfig.inform("Creating pyuic4 Makefile...")
+            sipconfig.inform("Creating pyuic4 Makefile...")
 
-        makefile = sipconfig.PythonModuleMakefile(
-            configuration=sipcfg,
-            dstdir=uicdir,
-            srcdir="uic",
-            dir="pyuic",
-            installs=[[os.path.basename(wrapper), opts.pyqtbindir]]
-        )
+            makefile = sipconfig.PythonModuleMakefile(
+                configuration=sipcfg,
+                dstdir=uicdir,
+                srcdir="uic",
+                dir="pyuic",
+                installs=[[os.path.basename(wrapper), opts.pyqtbindir]]
+            )
 
-        makefile.generate()
-        tool.append("pyuic")
+            makefile.generate()
+            tool.append("pyuic")
 
         if "QtXml" in pyqt_modules:
             sipconfig.inform("Creating pylupdate4 Makefile...")
@@ -694,7 +745,10 @@
             makefile.generate()
             tool.append("pyrcc")
         else:
-            sipconfig.inform("pylupdate4 and pyrcc4 will not be built because the Qt XML module is missing.")
+            if freebsd:
+                pass
+            else:
+                sipconfig.inform("pylupdate4 and pyrcc4 will not be built because the Qt XML module is missing.")
 
         if "QtDesigner" in pyqt_modules:
             enabled = True
@@ -719,6 +773,12 @@
                       glob.glob("%s/lib/libpython%d.%d*" % (ducfg["prefix"], py_major, py_minor))):
                     lib_dir_flag = quote("-L%s/lib" % ducfg["prefix"])
                     link = "%s -lpython%d.%d" % (lib_dir_flag, py_major, py_minor)
+                elif freebsd:
+                    # We do have shared libpython, but also static. Alas
+                    # static is built *first*, and to distutils it looks as 
+                    # if we have static py only
+                    lib_dir_flag = quote("-L%s/lib" % ducfg["prefix"])
+                    link = "%s -lpython%d.%d" % (lib_dir_flag, py_major, py_minor)
                 else:
                     sipconfig.inform("Qt Designer plugin disabled because Python library is static")
                     enabled = False
@@ -791,19 +851,44 @@
     sipconfig.inform("The %s %s library is in %s." % (lib_type, qt_lib, qt_libdir))
     sipconfig.inform("The Qt binaries are in %s." % qt_bindir)
     sipconfig.inform("The Qt mkspecs directory is in %s." % qt_datadir)
-    sipconfig.inform("These PyQt modules will be built: %s." % string.join(pyqt_modules))
-    sipconfig.inform("The PyQt Python package will be installed in %s." % opts.pyqtmoddir)
-    sipconfig.inform("The Designer plugin will be installed in %s." % os.path.join(opts.plugindir, "designer"))
+    if freebsd:
+        if not freebsd_port in ('dbus', 'demo', 'designerplugin'):
+            sipconfig.inform("This PyQt module will be built: %s." % pyqt_modules[-1])
+            sipconfig.inform("The PyQt Python package will be installed in %s." % opts.pyqtmoddir)
+        if freebsd_port == 'designerplugin':
+            sipconfig.inform("The Designer plugin will be installed in %s." % os.path.join(opts.plugindir, "designer"))
+    else:
+        sipconfig.inform("These PyQt modules will be built: %s." % string.join(pyqt_modules))
+        sipconfig.inform("The PyQt Python package will be installed in %s." % opts.pyqtmoddir)
+        sipconfig.inform("The Designer plugin will be installed in %s." % os.path.join(opts.plugindir, "designer"))
 
     if opts.api:
-        sipconfig.inform("The QScintilla API file will be installed in %s." % os.path.join(opts.qscidir, "api", "python"))
+        if freebsd:
+            if not freebsd_port in ('dbus', 'demo', 'doc', 'designerplugin'):
+                sipconfig.inform("The QScintilla API file will be installed in %s." % os.path.join(opts.qscidir, "api", "python"))
+        else:
+            sipconfig.inform("The QScintilla API file will be installed in %s." %  os.path.join(opts.qscidir, "api", "python"))
 
     if pydbusmoddir:
-        sipconfig.inform("The dbus support module will be installed in %s." % pydbusmoddir)
+        if freebsd:
+            if freebsd_port == 'dbus':
+                sipconfig.inform("The dbus support module will be installed in %s." % pydbusmoddir)
+        else:
+            sipconfig.inform("The dbus support module will be installed in %s." % pydbusmoddir)
 
-    sipconfig.inform("The PyQt .sip files will be installed in %s." % opts.pyqtsipdir)
+    if freebsd:
+        if not freebsd_port in ('dbus', 'demo', 'designerplugin'):
+            sipconfig.inform("The PyQt .sip files will be installed in %s." % opts.pyqtsipdir)
+    else:
+        sipconfig.inform("The PyQt .sip files will be installed in %s." % opts.pyqtsipdir)
 
-    sipconfig.inform("pyuic4, pyrcc4 and pylupdate4 will be installed in %s." % opts.pyqtbindir)
+    if freebsd:
+        if freebsd_port == 'core':
+            sipconfig.inform("pyuic4 will be installed in %s." % opts.pyqtbindir)
+        elif freebsd_port == 'xml':
+            sipconfig.inform("pyrcc4 and pylupdate4 will be installed in %s." % opts.pyqtbindir)
+    else:
+        sipconfig.inform("pyuic4, pyrcc4 and pylupdate4 will be installed in %s." % opts.pyqtbindir)
 
     if opts.vendorcheck:
         sipconfig.inform("PyQt will only be usable with signed interpreters.")
@@ -1171,7 +1256,11 @@
     of libraries.
     extra_sip_flags is an optional list of additional flags to pass to SIP.
     """
-    sipconfig.inform("Generating the C++ source for the %s module..." % mname)
+    if freebsd:
+        if mname != 'Qt':
+            sipconfig.inform("Generating the C++ source for the %s module..." % mname)
+    else:
+        sipconfig.inform("Generating the C++ source for the %s module..." % mname)
 
     mk_clean_dir(mname)
 
@@ -1243,7 +1332,11 @@
         sipconfig.error("Unable to create the C++ code.")
 
     # Generate the Makefile.
-    sipconfig.inform("Creating the Makefile for the %s module..." % mname)
+    if freebsd:
+        if mname != 'Qt':
+            sipconfig.inform("Creating the Makefile for the %s module..." % mname)
+    else:
+        sipconfig.inform("Creating the Makefile for the %s module..." % mname)
 
     installs = []
 
@@ -1786,13 +1879,25 @@
         p.print_help()
         sys.exit(2)
 
+    if freebsd:
+        # avoid picking up the Qt3 headers instead
+        macros['INCDIR'] = '.'
+    
     sipcfg.set_build_macros(macros)
 
     # Check Qt is what we need.
     pyqt = check_qt_installation(macros)
 
     # Check the licenses are compatible.
-    check_license()
+    if not freebsd:
+        check_license()
+    else:
+        print
+        sipconfig.inform("NOTE: This port uses the GPL licensed version of PyQt4.")
+        sipconfig.inform("If you require a commercial license or are unsure, please")
+        sipconfig.inform("read http://www.riverbankcomputing.co.uk/pyqt/index.php\n")
+        print
+        # Sorry, we can't hang auto builds for confirmation and GPL doesn't need it
 
     # Check which modules to build.
     pyqt.check_modules()
@@ -1815,9 +1920,18 @@
     installs=[(pyqt.module_installs(), pyqt_modroot)]
 
     if opts.api:
-        installs.append(("PyQt4.api", os.path.join(opts.qscidir, "api", "python")))
+        if freebsd:
+            # Don't break package lists
+            if not freebsd_port in ('dbus', 'designerplugin', 'demo', 'doc'):
+                apifile = pyqt_modules[-1] + '.api'
+                installs.append((apifile, os.path.join(opts.qscidir, "api", "python")))
+        else:
+            installs.append(("PyQt4.api", os.path.join(opts.qscidir, "api", "python")))
 
-    xtra_modules = ["Qt"]
+    if freebsd:
+        xtra_modules = []
+    else:
+        xtra_modules = ["Qt"]
 
     if opts.bigqt:
         xtra_modules.append("_qt")
@@ -1828,14 +1942,31 @@
         if opts.mwg_qwt_dir:
             xtra_modules.append("Qwt5")
 
+    if freebsd:
+        if freebsd_port == 'dbus':
+            s = pyqt.tools()
+        elif freebsd_port == 'designer':
+            s = pyqt.qpylibs() + [pyqt_modules[-1]]
+        elif freebsd_port == 'designerplugin':
+            s = pyqt.tools()
+        else:
+            s = [pyqt_modules[-1]]
+            if freebsd_port in ('core', 'xml'):
+                s += pyqt.tools()
+    else: s = pyqt.qpylibs() + pyqt_modules + xtra_modules + pyqt.tools()
+
     sipconfig.ParentMakefile(
         configuration=sipcfg,
-        subdirs=pyqt.qpylibs() + pyqt_modules + xtra_modules + pyqt.tools(),
+        subdirs=s,
         installs=installs
     ).generate()
 
     # Install the configuration module.
-    create_config("pyqtconfig.py", "pyqtconfig.py.in", macros)
+    if freebsd:
+        if freebsd_port == 'core':
+            create_config("pyqtconfig.py", "pyqtconfig.py.in", macros)
+    else:
+        create_config("pyqtconfig.py", "pyqtconfig.py.in", macros)
 
 
 ###############################################################################
