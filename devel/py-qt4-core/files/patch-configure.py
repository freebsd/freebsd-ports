--- configure.py.orig	Tue Apr 10 17:59:52 2007
+++ configure.py	Thu Apr 12 20:48:21 2007
@@ -140,24 +140,24 @@
     def check_modules(self):
         pyqt_modules.append("QtCore")
 
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
+
+        #if sipcfg.universal:
+        #    sipconfig.inform("QtDesigner module disabled with universal binaries")
+        #else:
+        #    check_module("QtDesigner", "QExtensionFactory", "new QExtensionFactory()")
 
-        if sipcfg.universal:
-            sipconfig.inform("QtDesigner module disabled with universal binaries")
-        else:
-            check_module("QtDesigner", "QExtensionFactory", "new QExtensionFactory()")
-
-        check_module("QAxContainer", "qaxobject.h", "new QAxObject()", "QAxContainer")
+        #check_module("QAxContainer", "qaxobject.h", "new QAxObject()", "QAxContainer")
 
-        if os.path.isdir("dbus"):
-            check_dbus()
+        #if os.path.isdir("dbus"):
+        #    check_dbus()
 
     def code(self):
         # Note that the order of the dependent modules is important.
@@ -211,31 +211,31 @@
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
+        return ["__init__.py", "pyqtconfig.py"]
 
     def qpylibs(self):
         # See which QPy libraries to build.
@@ -376,7 +376,8 @@
             makefile.generate()
             tool.append("pyrcc")
         else:
-            sipconfig.inform("pylupdate4 and pyrcc4 will not be built because the Qt XML module is missing.")
+            #sipconfig.inform("pylupdate4 and pyrcc4 will not be built because the Qt XML module is missing.")
+            pass
 
         if "QtDesigner" in pyqt_modules:
             enabled = True
@@ -460,7 +461,7 @@
     sipconfig.inform("The Qt mkspecs directory is in %s." % qt_datadir)
     sipconfig.inform("These PyQt modules will be built: %s." % string.join(pyqt_modules))
     sipconfig.inform("The PyQt modules will be installed in %s." % opt_pyqtmoddir)
-    sipconfig.inform("The Designer plugin will be installed in %s." % os.path.join(opt_plugindir, "designer"))
+    #sipconfig.inform("The Designer plugin will be installed in %s." % os.path.join(opt_plugindir, "designer"))
 
     if opt_api:
         sipconfig.inform("The QScintilla API file will be installed in %s." % os.path.join(opt_qscidir, "api", "python"))
@@ -470,7 +471,7 @@
 
     sipconfig.inform("The PyQt .sip files will be installed in %s." % opt_pyqtsipdir)
 
-    sipconfig.inform("pyuic4, pyrcc4 and pylupdate4 will be installed in %s." % opt_pyqtbindir)
+    sipconfig.inform("pyuic4 will be installed in %s." % opt_pyqtbindir)
 
     if opt_vendorcheck:
         sipconfig.inform("PyQt will only be usable with signed interpreters.")
@@ -873,7 +874,7 @@
             sipconfig.error("This version of PyQt and the %s edition of Qt have incompatible licenses." % qted)
 
     # Confirm the license.
-    print
+    """print
     print "Type 'L' to view the license."
     print "Type 'yes' to accept the terms of the license."
     print "Type 'no' to decline the terms of the license."
@@ -895,7 +896,7 @@
 
         if resp == "l":
             os.system("more LICENSE")
-
+    """
     # If there should be a license file then check it is where it should be.
     if lfile:
         if os.access(os.path.join("sip", lfile), os.F_OK):
@@ -1434,7 +1435,7 @@
     installs=[(pyqt.module_installs(), opt_pyqtmoddir)]
 
     if opt_api:
-        installs.append(("PyQt4.api", os.path.join(opt_qscidir, "api", "python")))
+        installs.append(("QtCore.api", os.path.join(opt_qscidir, "api", "python")))
 
     sipconfig.ParentMakefile(
         configuration=sipcfg,
