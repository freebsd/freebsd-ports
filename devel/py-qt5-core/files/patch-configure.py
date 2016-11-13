This patch is necessary for us to split PyQt5 up into several different ports.

It works by conditionally building and installing some tools (such as
pylupdate5 and pyrcc5), replacing the all-encompassing PyQt5.api file that
depends on different modules with module-specific .api files.

Also fixes a bug where dbus support drops multiple -I flags produced
by pkg-config --cflags dbus-1 .

--- configure.py.orig	2016-04-24 10:55:08.000000000 +0000
+++ configure.py	2016-10-30 22:16:19.159104000 +0000
@@ -1482,13 +1482,13 @@
 
     generate_sip_module_code(target_config, verbose, no_timestamp, parts,
             tracing, 'Qt', sip_flags)
-    subdirs.append('Qt')
 
     if not target_config.no_tools:
-        # Generate pylupdate5 and pyrcc5.
-        for tool in ('pylupdate', 'pyrcc'):
-            generate_application_makefile(target_config, verbose, tool)
-            subdirs.append(tool)
+        if "QtXml" in target_config.pyqt_modules:
+            # Generate pylupdate5 and pyrcc5.
+            for tool in ('pylupdate', 'pyrcc'):
+                generate_application_makefile(target_config, verbose, tool)
+                subdirs.append(tool)
 
         # Generate the pyuic5 wrapper.
         pyuic_wrapper = generate_pyuic5_wrapper(target_config)
@@ -1507,22 +1507,6 @@
                     source_path('examples', 'quick', 'tutorials', 'extending',
                             'chapter6-plugins'))
 
-    # Generate the QScintilla API file.
-    if target_config.qsci_api:
-        inform("Generating the QScintilla API file...")
-        f = open_for_writing('PyQt5.api')
-
-        for mname in target_config.pyqt_modules:
-            api = open(mname + '.api')
-
-            for l in api:
-                f.write('PyQt5.' + l)
-
-            api.close()
-            os.remove(mname + '.api')
-
-        f.close()
-
     # Generate the Python dbus module.
     if target_config.pydbus_module_dir != '':
         mname = 'dbus'
@@ -1548,21 +1532,24 @@
     out_f.write('''TEMPLATE = subdirs
 CONFIG += ordered nostrip
 SUBDIRS = %s
+''' % ' '.join(subdirs))
 
+    if "QtCore" in target_config.pyqt_modules:
+        out_f.write('''
 init_py.files = %s
 init_py.path = %s
 INSTALLS += init_py
-''' % (' '.join(subdirs), source_path('__init__.py'), qmake_quote(target_config.pyqt_module_dir + '/PyQt5')))
+''' % (source_path('__init__.py'), qmake_quote(target_config.pyqt_module_dir + '/PyQt5')))
 
-    # Install the uic module and the pyuic5 wrapper.
-    out_f.write('''
+        # Install the uic module and the pyuic5 wrapper.
+        out_f.write('''
 uic_package.files = %s
 uic_package.path = %s
 INSTALLS += uic_package
 ''' % (source_path('pyuic', 'uic'), qmake_quote(target_config.pyqt_module_dir + '/PyQt5')))
 
-    if not target_config.no_tools:
-        out_f.write('''
+        if not target_config.no_tools:
+            out_f.write('''
 pyuic5.files = %s
 pyuic5.path = %s
 INSTALLS += pyuic5
@@ -1579,11 +1566,12 @@
 
     # Install the QScintilla .api file.
     if target_config.qsci_api:
+        api_list = ' '.join(['%s.api' % m for m in target_config.pyqt_modules])
         out_f.write('''
-qscintilla_api.files = PyQt5.api
+qscintilla_api.files = %s
 qscintilla_api.path = %s
 INSTALLS += qscintilla_api
-''' % qmake_quote(target_config.qsci_api_dir + '/api/python'))
+''' % (api_list, qmake_quote(target_config.qsci_api_dir + '/api/python')))
 
     out_f.close()
 
@@ -2140,7 +2128,9 @@
     else:
         dlist = target_config.dbus_inc_dirs
 
-    target_config.dbus_inc_dirs = []
+    # Don't reset dbus_inc_dirs, because it will forget the flags
+    # found for dbus, above (which might require multiple -I flags).
+    # target_config.dbus_inc_dirs = []
 
     for d in dlist:
         if os.access(os.path.join(d, 'dbus', 'dbus-python.h'), os.F_OK):
