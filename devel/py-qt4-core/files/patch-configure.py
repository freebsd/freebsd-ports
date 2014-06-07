--- configure.py.orig	2014-06-06 00:15:32.000000000 +0300
+++ configure.py	2014-06-06 00:20:20.000000000 +0300
@@ -342,7 +342,7 @@
 
         # Note that the order in which we check is important for the
         # consolidated module - a module's dependencies must be checked first.
-        pyqt_modules.append("QtCore")
+        check_module("QtCore", "qobject.h", "new QObject()")
 
         check_module("QtGui", "qwidget.h", "new QWidget()")
         check_module("QtHelp", "qhelpengine.h", "new QHelpEngine(\"foo\")")
@@ -371,8 +371,8 @@
         check_module("QtTest", "QtTest", "QTest::qSleep(0)")
         check_module("QtWebKit", "qwebpage.h", "new QWebPage()")
         check_module("QtXmlPatterns", "qxmlname.h", "new QXmlName()")
-        check_module("phonon", "phonon/videowidget.h",
-                "new Phonon::VideoWidget()")
+        check_module("phonon", "phonon/mediacontroller.h",
+                "new Phonon::MediaController(0)")
         check_module("QtAssistant", "qassistantclient.h",
                 "new QAssistantClient(\"foo\")", extra_lib_dirs=ass_lib_dirs,
                 extra_libs=ass_libs)
@@ -636,21 +636,6 @@
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
@@ -741,6 +726,9 @@
         return libs, libdirs
 
     def module_installs(self):
+        if "QtCore" not in pyqt_modules:
+            return []
+
         return [os.path.join(src_dir, "__init__.py"), "pyqtconfig.py"]
 
     def qpy_libs(self):
@@ -876,76 +864,78 @@
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
 
-        sipconfig.inform("Creating pylupdate4 Makefile...")
+        if "QtXml" in pyqt_modules:
+            sipconfig.inform("Creating pylupdate4 Makefile...")
 
-        cxxflags_app = sipcfg.build_macros().get("CXXFLAGS_APP", "")
+            cxxflags_app = sipcfg.build_macros().get("CXXFLAGS_APP", "")
 
-        makefile = sipconfig.ProgramMakefile(
-            configuration=sipcfg,
-            build_file=os.path.join(src_dir, "pylupdate", "pylupdate.sbf"),
-            dir="pylupdate",
-            install_dir=opts.pyqtbindir,
-            console=1,
-            qt=["QtCore", "QtXml"],
-            debug=opts.debug,
-            warnings=1,
-            universal=sipcfg.universal,
-            arch=sipcfg.arch,
-            deployment_target=sipcfg.deployment_target
-        )
-
-        makefile.extra_include_dirs.append(os.path.join(src_dir, "pylupdate"))
-
-        if cxxflags_app != "":
-            makefile.extra_cxxflags.append(cxxflags_app)
-
-        makefile.generate()
-        tool.append("pylupdate")
-
-        sipconfig.inform("Creating pyrcc4 Makefile...")
+            makefile = sipconfig.ProgramMakefile(
+                configuration=sipcfg,
+                build_file=os.path.join(src_dir, "pylupdate", "pylupdate.sbf"),
+                dir="pylupdate",
+                install_dir=opts.pyqtbindir,
+                console=1,
+                qt=["QtCore", "QtXml"],
+                debug=opts.debug,
+                warnings=1,
+                universal=sipcfg.universal,
+                arch=sipcfg.arch,
+                deployment_target=sipcfg.deployment_target
+            )
 
-        makefile = pyrccMakefile()
+            makefile.extra_include_dirs.append(os.path.join(src_dir, "pylupdate"))
 
-        if cxxflags_app != "":
-            makefile.extra_cxxflags.append(cxxflags_app)
+            if cxxflags_app != "":
+                makefile.extra_cxxflags.append(cxxflags_app)
 
-        makefile.generate()
-        tool.append("pyrcc")
+            makefile.generate()
+            tool.append("pylupdate")
+
+            sipconfig.inform("Creating pyrcc4 Makefile...")
+
+            makefile = pyrccMakefile()
+
+            if cxxflags_app != "":
+                makefile.extra_cxxflags.append(cxxflags_app)
+
+            makefile.generate()
+            tool.append("pyrcc")
 
         if opts.designer_plugin and "QtDesigner" in pyqt_modules:
             py_major = sipcfg.py_version >> 16
@@ -972,9 +962,6 @@
                     # include the ABI information.
                     abi = ""
                 else:
-                    dynamic_pylib = "--enable-shared" in config_args
-
-                if dynamic_pylib:
                     if glob.glob("%s/lib/libpython%d.%d*" % (ducfg["exec_prefix"], py_major, py_minor)):
                         lib_dir_flag = quote("-L%s/lib" % ducfg["exec_prefix"])
                     elif glob.glob("%s/libpython%d.%d*" % (ducfg["LIBDIR"], py_major, py_minor)):
@@ -985,9 +972,6 @@
                         opts.designer_plugin = False
 
                     link = "%s -lpython%d.%d%s" % (lib_dir_flag, py_major, py_minor, abi)
-                else:
-                    sipconfig.inform("Qt Designer plugin disabled because Python library is static")
-                    opts.designer_plugin = False
 
                 pysh_lib = ducfg.get("LDLIBRARY", "")
 
@@ -1380,6 +1364,7 @@
 def check_dbus():
     """See if the DBus support module should be built.
     """
+    return # Kill search for dbus. Search key: 6f29b27e48
     sipconfig.inform("Checking to see if the dbus support module should be built...")
 
     sout = get_command_stdout("pkg-config --cflags-only-I --libs dbus-1")
@@ -1988,6 +1973,7 @@
     sipcfg.qt_framework = qt_framework
     sipcfg.qt_threaded = 1
     sipcfg.qt_dir = qt_dir
+    sipcfg.qt_data_dir = qt_datadir
     sipcfg.qt_lib_dir = qt_libdir
 
     return ConfigurePyQt4(generator)
@@ -2323,6 +2309,9 @@
         p.print_help()
         sys.exit(2)
 
+    # Avoid picking up the Qt3 headers instead
+    macros['INCDIR'] = '.'
+
     sipcfg.set_build_macros(macros)
 
     # Check Qt is what we need.
@@ -2364,9 +2353,9 @@
     installs=[(pyqt.module_installs(), pyqt_modroot)]
 
     if opts.api:
-        installs.append(("PyQt4.api", os.path.join(opts.qscidir, "api", "python")))
+        installs.append(("%s.api" % pyqt_modules[-1], os.path.join(opts.qscidir, "api", "python")))
 
-    xtra_modules = ["Qt"]
+    xtra_modules = []
 
     if opts.bigqt:
         xtra_modules.append("_qt")
@@ -2379,7 +2368,7 @@
 
     sipconfig.ParentMakefile(
         configuration=sipcfg,
-        subdirs=pyqt.qpy_libs() + pyqt_modules + xtra_modules + pyqt.tools(),
+        subdirs=pyqt.qpy_libs() + [pyqt_modules[-1]] + xtra_modules + pyqt.tools(),
         installs=installs
     ).generate()
 
