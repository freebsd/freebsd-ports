--- configure.py.orig	2014-07-03 17:00:02.000000000 +0300
+++ configure.py	2014-07-19 23:51:03.000000000 +0300
@@ -343,7 +343,7 @@
 
         # Note that the order in which we check is important for the
         # consolidated module - a module's dependencies must be checked first.
-        pyqt_modules.append("QtCore")
+        check_module("QtCore", "qobject.h", "new QObject()")
 
         check_module("QtGui", "qwidget.h", "new QWidget()")
         check_module("QtHelp", "qhelpengine.h", "new QHelpEngine(\"foo\")")
@@ -372,8 +372,8 @@
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
@@ -635,21 +635,6 @@
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
@@ -740,6 +725,9 @@
         return libs, libdirs
 
     def module_installs(self):
+        if "QtCore" not in pyqt_modules:
+            return []
+
         return [os.path.join(src_dir, "__init__.py"), "pyqtconfig.py"]
 
     def qpy_libs(self):
@@ -875,80 +863,82 @@
             makefile.generate()
             tool.append("elementtree")
 
-        # Create the pyuic4 wrapper.  Use the GUI version on MacOS (so that
-        # previews work properly and normal console use will work anyway), but
-        # not on Windows (so that normal console use will work).
-        sipconfig.inform("Creating pyuic4 wrapper...")
+        if "QtCore" in pyqt_modules:
+            # Create the pyuic4 wrapper.  Use the GUI version on MacOS (so that
+            # previews work properly and normal console use will work anyway), but
+            # not on Windows (so that normal console use will work).
+            sipconfig.inform("Creating pyuic4 wrapper...")
 
-        if sys.platform == 'darwin':
-            gui = True
+            if sys.platform == 'darwin':
+                gui = True
 
-            if opts.use_arch is None:
-                use_arch = ''
+                if opts.use_arch is None:
+                    use_arch = ''
+                else:
+                    use_arch = ' '.join(opts.use_arch)
             else:
-                use_arch = ' '.join(opts.use_arch)
-        else:
-            gui = False
-            use_arch = ''
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
+
+            makefile.extra_include_dirs.append(os.path.join(src_dir, "pylupdate"))
+
+            if cxxflags_app != "":
+                makefile.extra_cxxflags.append(cxxflags_app)
+
+            makefile.generate()
+            tool.append("pylupdate")
 
-        makefile = pyrccMakefile()
+            sipconfig.inform("Creating pyrcc4 Makefile...")
 
-        if cxxflags_app != "":
-            makefile.extra_cxxflags.append(cxxflags_app)
+            makefile = pyrccMakefile()
 
-        makefile.generate()
-        tool.append("pyrcc")
+            if cxxflags_app != "":
+                makefile.extra_cxxflags.append(cxxflags_app)
+
+            makefile.generate()
+            tool.append("pyrcc")
 
         if opts.designer_plugin and "QtDesigner" in pyqt_modules:
             py_major = sipcfg.py_version >> 16
@@ -2301,9 +2285,9 @@
     installs=[(pyqt.module_installs(), pyqt_modroot)]
 
     if opts.api:
-        installs.append(("PyQt4.api", os.path.join(opts.qscidir, "api", "python")))
+        installs.append(("%s.api" % pyqt_modules[-1], os.path.join(opts.qscidir, "api", "python")))
 
-    xtra_modules = ["Qt"]
+    xtra_modules = []
 
     if opts.bigqt:
         xtra_modules.append("_qt")
