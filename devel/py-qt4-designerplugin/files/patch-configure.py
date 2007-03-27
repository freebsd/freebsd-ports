--- configure.py.orig	Mon Mar 19 04:33:57 2007
+++ configure.py	Mon Mar 19 20:02:07 2007
@@ -133,21 +133,21 @@
         }
 
     def check_modules(self):
-        pyqt_modules.append("QtCore")
+        #pyqt_modules.append("QtCore")
 
-        check_module("QtGui", "qwidget.h", "new QWidget()")
-        check_module("QtNetwork", "qhostaddress.h", "new QHostAddress()")
-        check_module("QtOpenGL", "qgl.h", "new QGLWidget()")
-        check_module("QtSql", "qsqldatabase.h", "new QSqlDatabase()")
-        check_module("QtSvg", "qsvgwidget.h", "new QSvgWidget()")
-        check_module("QtTest", "QtTest", "QTest::qSleep(0)")
-        check_module("QtXml", "qdom.h", "new QDomDocument()")
-        check_module("QtAssistant", "qassistantclient.h", "new QAssistantClient(\"foo\")")
+        #check_module("QtGui", "qwidget.h", "new QWidget()")
+        #check_module("QtNetwork", "qhostaddress.h", "new QHostAddress()")
+        #check_module("QtOpenGL", "qgl.h", "new QGLWidget()")
+        #check_module("QtSql", "qsqldatabase.h", "new QSqlDatabase()")
+        #check_module("QtSvg", "qsvgwidget.h", "new QSvgWidget()")
+        #check_module("QtTest", "QtTest", "QTest::qSleep(0)")
+        #check_module("QtXml", "qdom.h", "new QDomDocument()")
+        #check_module("QtAssistant", "qassistantclient.h", "new QAssistantClient(\"foo\")")
         check_module("QtDesigner", "QExtensionFactory", "new QExtensionFactory()")
-        check_module("QAxContainer", "qaxobject.h", "new QAxObject()", "QAxContainer")
+        #check_module("QAxContainer", "qaxobject.h", "new QAxObject()", "QAxContainer")
 
-        if os.path.isdir("dbus"):
-            check_dbus()
+        #if os.path.isdir("dbus"):
+        #    check_dbus()
 
     def code(self):
         # Note that the order of the dependent modules is important.
@@ -201,31 +201,31 @@
             generate_code("QAxContainer", ["QAxContainer", "QtGui", "QtCore"])
 
         # Generate the consolidated module.
-        sipconfig.inform("Creating Qt consolidated module...")
-        f = open("Qt.py", "w")
+        #sipconfig.inform("Creating Qt consolidated module...")
+        #f = open("Qt.py", "w")
 
-        for m in pyqt_modules:
-            f.write("from PyQt4.%s import *\n" % m)
+        #for m in pyqt_modules:
+        #    f.write("from PyQt4.%s import *\n" % m)
 
-        f.close()
+        #f.close()
 
         # Generate the QScintilla API file.
-        sipconfig.inform("Creating QScintilla API file...")
-        f = open("PyQt4.api", "w")
+        #sipconfig.inform("Creating QScintilla API file...")
+        #f = open("PyQt4.api", "w")
 
-        for m in pyqt_modules:
-            api = open(m + ".api")
+        #for m in pyqt_modules:
+        #    api = open(m + ".api")
 
-            for l in api:
-                f.write("PyQt4." + l)
+        #    for l in api:
+        #        f.write("PyQt4." + l)
 
-            api.close()
-            os.remove(m + ".api")
+        #    api.close()
+        #    os.remove(m + ".api")
 
-        f.close()
+        #f.close()
 
     def module_installs(self):
-        return ["__init__.py", "Qt.py", "pyqtconfig.py"]
+        return []
 
     def qpylibs(self):
         # See which QPy libraries to build.
@@ -278,7 +278,7 @@
             tool.append("dbus")
 
         # Only include ElementTree for older versions of Python.
-        if sipcfg.py_version < 0x020500:
+        """if sipcfg.py_version < 0x020500:
             sipconfig.inform("Creating elementtree Makefile...")
 
             makefile = sipconfig.PythonModuleMakefile(
@@ -309,7 +309,7 @@
         )
 
         makefile.generate()
-        tool.append("pyuic")
+        tool.append("pyuic")"""
 
         if "QtXml" in pyqt_modules:
             sipconfig.inform("Creating pylupdate4 Makefile...")
@@ -344,7 +344,8 @@
             makefile.generate()
             tool.append("pyrcc")
         else:
-            sipconfig.inform("pylupdate4 and pyrcc4 will not be built because the Qt XML module is missing.")
+            #sipconfig.inform("pylupdate4 and pyrcc4 will not be built because the Qt XML module is missing.")
+            pass
 
         if "QtDesigner" in pyqt_modules:
             enabled = True
@@ -364,7 +365,10 @@
                     # We need to work out how to specify the right framework
                     # version.
                     link = "-framework Python"
-                elif ("--enable-shared" in ducfg.get("CONFIG_ARGS", "") and
+                # FreeBSD python port configures and builds for static first, 
+                # then builds for shared later, so this test won't work:
+                #elif ("--enable-shared" in ducfg.get("CONFIG_ARGS", "") and
+                elif (sys.platform[:-1] == "freebsd" and
                       glob.glob("%s/lib/libpython%d.%d*" % (ducfg["prefix"], py_major, py_minor))):
                     link = "-L%s/lib -lpython%d.%d" % (ducfg["prefix"], py_major, py_minor)
                 else:
@@ -420,16 +424,16 @@
     sipconfig.inform("The %s Qt library is in %s." % (qt_lib, qt_libdir))
     sipconfig.inform("The Qt binaries are in %s." % qt_bindir)
     sipconfig.inform("The Qt mkspecs directory is in %s." % qt_datadir)
-    sipconfig.inform("These PyQt modules will be built: %s." % string.join(pyqt_modules))
+    #sipconfig.inform("These PyQt modules will be built: %s." % string.join(pyqt_modules))
 
-    sipconfig.inform("The PyQt modules will be installed in %s." % opt_pyqtmoddir)
+    #sipconfig.inform("The PyQt modules will be installed in %s." % opt_pyqtmoddir)
 
     if pydbusmoddir:
         sipconfig.inform("The dbus support module will be installed in %s." % pydbusmoddir)
 
-    sipconfig.inform("The PyQt .sip files will be installed in %s." % opt_pyqtsipdir)
+    #sipconfig.inform("The PyQt .sip files will be installed in %s." % opt_pyqtsipdir)
 
-    sipconfig.inform("pyuic4, pyrcc4 and pylupdate4 will be installed in %s." % opt_pyqtbindir)
+    #sipconfig.inform("pyuic4, pyrcc4 and pylupdate4 will be installed in %s." % opt_pyqtbindir)
 
     if opt_vendorcheck:
         sipconfig.inform("PyQt will only be usable with signed interpreters.")
@@ -767,7 +771,8 @@
     sipfiles = []
 
     for s in glob.glob("sip/" + mname + "/*.sip"):
-        sipfiles.append(os.path.join("..", "sip", mname, os.path.basename(s)))
+        if mname == "":
+            sipfiles.append(os.path.join("..", "sip", mname, os.path.basename(s)))
 
     installs.append([sipfiles, os.path.join(opt_pyqtsipdir, mname)])
 
@@ -831,7 +836,7 @@
             sipconfig.error("This version of PyQt and the %s edition of Qt have incompatible licenses." % qted)
 
     # Confirm the license.
-    print
+    """print
     print "Type 'L' to view the license."
     print "Type 'yes' to accept the terms of the license."
     print "Type 'no' to decline the terms of the license."
@@ -853,7 +858,7 @@
 
         if resp == "l":
             os.system("more LICENSE")
-
+    """
     # If there should be a license file then check it is where it should be.
     if lfile:
         if os.access(os.path.join("sip", lfile), os.F_OK):
@@ -1372,17 +1377,17 @@
 
     scidir = os.path.join(qt_datadir, "qsci")
 
-    if opt_api or os.path.isdir(scidir):
-        installs.append(("PyQt4.api", os.path.join(scidir, "api", "python")))
+    #if opt_api or os.path.isdir(scidir):
+    #    installs.append(("PyQt4.api", os.path.join(scidir, "api", "python")))
 
     sipconfig.ParentMakefile(
         configuration=sipcfg,
-        subdirs=pyqt.qpylibs() + pyqt_modules + pyqt.tools(),
+        subdirs=pyqt.qpylibs() + pyqt.tools(),
         installs=installs
     ).generate()
 
     # Install the configuration module.
-    create_config("pyqtconfig.py", "pyqtconfig.py.in", macros)
+    #create_config("pyqtconfig.py", "pyqtconfig.py.in", macros)
 
 
 ###############################################################################
