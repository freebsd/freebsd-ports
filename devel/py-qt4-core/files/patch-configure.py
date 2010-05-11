--- configure.py.orig	2010-03-18 04:29:19.000000000 +1000
+++ configure.py	2010-03-18 14:07:20.613873966 +1000
@@ -36,6 +36,10 @@
 
 import sipconfig
 
+# FreeBSD check and which component (port)
+freebsd, freebsd_port = False, ''
+if sys.platform[:-1] == 'freebsd': freebsd = True
+if freebsd: freebsd_port = os.environ['PYQT4_COMPONENT']
 
 # Initialise the globals.
 pyqt_version = 0x040702
@@ -70,7 +74,6 @@
 dbuslibdirs = []
 dbuslibs = []
 
-
 # Under Windows qmake and the Qt DLLs must be into the system PATH otherwise
 # the dynamic linker won't be able to resolve the symbols.  On other systems we
 # assume we can just run qmake by using its full pathname.
@@ -375,14 +378,23 @@
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
 
         if os.path.isdir(os.path.join(src_dir, "dbus")):
-            check_dbus()
+            if freebsd:
+                if freebsd_port == 'dbus': 
+                    check_dbus()
+            else: 
+                check_dbus()
 
     def code(self):
         cons_xtra_incdirs = []
@@ -408,6 +420,10 @@
             cons_xtra_libs.extend(sp_libs)
 
             generate_code("QtCore")
+        elif freebsd:
+            if freebsd_port == 'core':
+                generate_code("QtCore", extra_include_dirs=sp_incdirs,
+                            extra_lib_dirs=sp_libdirs, extra_libs=sp_libs)
         else:
             generate_code("QtCore", extra_include_dirs=sp_incdirs,
                         extra_lib_dirs=sp_libdirs, extra_libs=sp_libs)
@@ -596,19 +612,28 @@
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
+
+            for m in pyqt_modules:
+                api = open(m + ".api")
 
-            for l in api:
-                f.write("PyQt4." + l)
+                for l in api:
+                    f.write("PyQt4." + l)
 
-            api.close()
-            os.remove(m + ".api")
+                api.close()
+                os.remove(m + ".api")
 
-        f.close()
+            f.close()
 
     def _qpy_directories(self, mname, lib_name):
         """Return a 3-tuple of the directories containing the header files, the
@@ -700,19 +725,25 @@
         return libs, libdirs
 
     def module_installs(self):
-        return [os.path.join(src_dir, "__init__.py"), "pyqtconfig.py"]
+        if freebsd:
+            if freebsd_port == 'core':
+                return [os.path.join(src_dir, "__init__.py"), "pyqtconfig.py"]
+            else:
+                return []
+        else:
+            return [os.path.join(src_dir, "__init__.py"), "pyqtconfig.py"]
 
     def qpy_libs(self):
         # See which QPy support libraries to build.
         qpylibs = {}
 
-        if "QtCore" in pyqt_modules:
+        if freebsd_port == 'core':
             qpylibs["QtCore"] = "qpycore.pro"
 
-        if "QtGui" in pyqt_modules:
+        if freebsd_port == 'gui':
             qpylibs["QtGui"] = "qpygui.pro"
 
-        if "QtDesigner" in pyqt_modules:
+        if freebsd_port == 'designer':
             qpylibs["QtDesigner"] = "qpydesigner.pro"
 
         # Run qmake to generate the Makefiles.
@@ -822,30 +853,58 @@
         # Create the pyuic4 wrapper.  Use the GUI version on MacOS (so that
         # previews work properly and normal console use will work anyway), but
         # not on Windows (so that normal console use will work).
-        sipconfig.inform("Creating pyuic4 wrapper...")
+        if freebsd:
+            if freebsd_port == 'core':
+                sipconfig.inform("Creating pyuic4 wrapper...")
+
+                if sys.platform == 'darwin':
+                    gui = True
+                    use_arch = opts.use_arch
+                else:
+                    gui = False
+                    use_arch = ''
+
+                uicdir=os.path.join(pyqt_modroot, "uic")
+                wrapper = sipconfig.create_wrapper(os.path.join(uicdir, "pyuic.py"), os.path.join("pyuic", "pyuic4"), gui, use_arch)
+
+                sipconfig.inform("Creating pyuic4 Makefile...")
+
+                makefile = sipconfig.PythonModuleMakefile(
+                    configuration=sipcfg,
+                    dstdir=uicdir,
+                    srcdir=os.path.join(src_dir, "pyuic", "uic"),
+                    dir="pyuic",
+                    installs=[[os.path.basename(wrapper), opts.pyqtbindir]]
+                )
+
+                makefile.generate()
+                tool.append("pyuic")
 
-        if sys.platform == 'darwin':
-            gui = True
-            use_arch = opts.use_arch
         else:
-            gui = False
-            use_arch = ''
+            sipconfig.inform("Creating pyuic4 wrapper...")
 
-        uicdir=os.path.join(pyqt_modroot, "uic")
-        wrapper = sipconfig.create_wrapper(os.path.join(uicdir, "pyuic.py"), os.path.join("pyuic", "pyuic4"), gui, use_arch)
+            if sys.platform == 'darwin':
+                gui = True
+                use_arch = opts.use_arch
+            else:
+                gui = False
+                use_arch = ''
 
-        sipconfig.inform("Creating pyuic4 Makefile...")
+            uicdir=os.path.join(pyqt_modroot, "uic")
+            wrapper = sipconfig.create_wrapper(os.path.join(uicdir, "pyuic.py"), os.path.join("pyuic", "pyuic4"), gui, use_arch)
 
-        makefile = sipconfig.PythonModuleMakefile(
-            configuration=sipcfg,
-            dstdir=uicdir,
-            srcdir=os.path.join(src_dir, "pyuic", "uic"),
-            dir="pyuic",
-            installs=[[os.path.basename(wrapper), opts.pyqtbindir]]
-        )
+            sipconfig.inform("Creating pyuic4 Makefile...")
+
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
@@ -873,7 +932,10 @@
             makefile.generate()
             tool.append("pyrcc")
         else:
-            sipconfig.inform("pylupdate4 and pyrcc4 will not be built because the Qt XML module is missing.")
+            if freebsd:
+                pass
+            else:
+                sipconfig.inform("pylupdate4 and pyrcc4 will not be built because the Qt XML module is missing.")
 
         if opts.designer_plugin and "QtDesigner" in pyqt_modules:
             py_major = sipcfg.py_version >> 16
@@ -896,11 +958,17 @@
                       glob.glob("%s/lib/libpython%d.%d*" % (ducfg["exec_prefix"], py_major, py_minor))):
                     lib_dir_flag = quote("-L%s/lib" % ducfg["exec_prefix"])
                     link = "%s -lpython%d.%d" % (lib_dir_flag, py_major, py_minor)
+                elif freebsd:
+                    lib_dir_flag = quote("-L%s/lib" % ducfg["prefix"])
+                    link = "%s -lpython%d.%d" % (lib_dir_flag, py_major, py_minor)
                 else:
                     sipconfig.inform("Qt Designer plugin disabled because Python library is static")
                     opts.designer_plugin = False
 
-                pysh_lib = ducfg["LDLIBRARY"]
+                if freebsd:
+                    pysh_lib = "libpython%d.%d" % (py_major, py_minor)
+                else:
+                    pysh_lib = ducfg["LDLIBRARY"]
 
             if opts.designer_plugin:
                 sipconfig.inform("Creating Qt Designer plugin Makefile...")
@@ -994,8 +1062,13 @@
     sipconfig.inform("The %s Qt libraries are in %s." % (lib_type, qt_libdir))
     sipconfig.inform("The Qt binaries are in %s." % qt_bindir)
     sipconfig.inform("The Qt mkspecs directory is in %s." % qt_datadir)
-    sipconfig.inform("These PyQt modules will be built: %s." % ", ".join(pyqt_modules))
-    sipconfig.inform("The PyQt Python package will be installed in %s." % opts.pyqtmoddir)
+    if freebsd:
+        if not freebsd_port in ('dbus', 'demo', 'designerplugin'):
+            sipconfig.inform("These PyQt modules will be built: %s." % ", ".join(pyqt_modules))
+            sipconfig.inform("The PyQt Python package will be installed in %s." % opts.pyqtmoddir)
+    else:
+        sipconfig.inform("These PyQt modules will be built: %s." % ", ".join(pyqt_modules))
+        sipconfig.inform("The PyQt Python package will be installed in %s." % opts.pyqtmoddir)
 
     if opts.no_docstrings:
         sipconfig.inform("PyQt is being built without generated docstrings.")
@@ -1005,18 +1078,36 @@
     if opts.prot_is_public:
         sipconfig.inform("PyQt is being built with 'protected' redefined as 'public'.")
 
-    if opts.designer_plugin:
+    if freebsd_port == 'designerplugin':
         sipconfig.inform("The Designer plugin will be installed in %s." % os.path.join(opts.plugindir, "designer"))
 
     if opts.api:
-        sipconfig.inform("The QScintilla API file will be installed in %s." % os.path.join(opts.qscidir, "api", "python"))
+        if freebsd:
+            if not freebsd_port in ('dbus', 'demo', 'doc', 'designerplugin'):
+                sipconfig.inform("The QScintilla API file will be installed in %s." % os.path.join(opts.qscidir, "api", "python"))
+        else:
+            sipconfig.inform("The QScintilla API file will be installed in %s." % os.path.join(opts.qscidir, "api", "python"))
 
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
@@ -1493,7 +1584,11 @@
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
 
@@ -1579,7 +1674,11 @@
         sipconfig.error("Unable to create the C++ code.")
 
     # Generate the Makefile.
-    sipconfig.inform("Creating the Makefile for the %s module..." % mname)
+    if freebsd:
+        if mname != 'Qt':
+            sipconfig.inform("Creating the Makefile for the %s module..." % mname)
+    else:
+        sipconfig.inform("Creating the Makefile for the %s module..." % mname)
 
     installs = []
 
@@ -2072,6 +2171,10 @@
         p.print_help()
         sys.exit(2)
 
+    if freebsd:
+        # avoid picking up the Qt3 headers instead
+        macros['INCDIR'] = '.'
+    
     sipcfg.set_build_macros(macros)
 
     # Check Qt is what we need.
@@ -2079,7 +2182,7 @@
 
     # Check the licenses are compatible.
     check_license()
-
+    
     # Check which modules to build.
     pyqt.check_modules()
 
@@ -2101,9 +2204,18 @@
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
@@ -2114,15 +2226,33 @@
         if opts.mwg_qwt_dir:
             xtra_modules.append("Qwt5")
 
+    if freebsd:
+        if freebsd_port == 'dbus':
+            s = pyqt.tools()
+        elif freebsd_port in ('designer', 'gui'):
+            s = pyqt.qpy_libs() + [pyqt_modules[-1]]
+        elif freebsd_port == 'designerplugin':
+            s = pyqt.tools()
+        elif freebsd_port == 'xml':
+            s = [pyqt_modules[-1]] + pyqt.tools()
+        else:
+            s = [pyqt_modules[-1]]
+            if freebsd_port == 'core':
+                s = pyqt.qpy_libs() + [pyqt_modules[-1]] + pyqt.tools()
+    else: s = pyqt.qpy_libs() + pyqt_modules + xtra_modules + pyqt.tools()
+
     sipconfig.ParentMakefile(
         configuration=sipcfg,
-        subdirs=pyqt.qpy_libs() + pyqt_modules + xtra_modules + pyqt.tools(),
+        subdirs=s,
         installs=installs
     ).generate()
 
     # Install the configuration module.
-    create_config("pyqtconfig.py", os.path.join(src_dir, "pyqtconfig.py.in"),
-            macros)
+    if freebsd:
+        if freebsd_port == 'core':
+            create_config("pyqtconfig.py", os.path.join(src_dir, "pyqtconfig.py.in"), macros)
+    else:
+        create_config("pyqtconfig.py", os.path.join(src_dir, "pyqtconfig.py.in"), macros)
 
 
 ###############################################################################
