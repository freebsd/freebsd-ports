This patch is necessary for us to split PyQt5 up into several different ports.

It works by conditionally building and installing some tools (such as
pylupdate5 and pyrcc5), replacing the all-encompassing PyQt5.api file that
depends on different modules with module-specific .api files.

Also fixes a bug where dbus support drops multiple -I flags produced
by pkg-config --cflags dbus-1 .

--- configure.py.orig	2016-07-25 13:55:28.000000000 +0000
+++ configure.py	2016-09-14 18:42:40.977955000 +0000
@@ -1460,8 +1460,9 @@

     # Add the internal modules if they are required.
     if not target_config.no_tools:
-        pyqt_modules.append('pylupdate')
-        pyqt_modules.append('pyrcc')
+        if "QtXml" in target_config.pyqt_modules:
+            pyqt_modules.append('pylupdate')
+            pyqt_modules.append('pyrcc')

     for mname in pyqt_modules:
         metadata = MODULE_METADATA[mname]
@@ -1504,18 +1505,19 @@

     generate_sip_module_code(target_config, verbose, parts, tracing, 'Qt',
             sip_flags, False)
-    subdirs.append('Qt')

     wrappers = []
     if not target_config.no_tools:
-        # Generate the pylupdate5 and pyrcc5 wrappers.
-        for tool in ('pylupdate', 'pyrcc'):
-            wrappers.append((tool,
-                    generate_tool_wrapper(target_config, tool + '5',
-                            'PyQt5.%s_main' % tool)))
-
-        # Generate the pyuic5 wrapper.
-        wrappers.append(('pyuic',
+        if "QtXml" in target_config.pyqt_modules:
+            # Generate the pylupdate5 and pyrcc5 wrappers.
+            for tool in ('pylupdate', 'pyrcc'):
+                wrappers.append((tool,
+                        generate_tool_wrapper(target_config, tool + '5',
+                                'PyQt5.%s_main' % tool)))
+
+        if "QtCore" in target_config.pyqt_modules:
+            # Generate the pyuic5 wrapper.
+            wrappers.append(('pyuic',
                 generate_tool_wrapper(target_config, 'pyuic5',
                         'PyQt5.uic.pyuic')))

@@ -1533,23 +1535,6 @@
                     source_path('examples', 'quick', 'tutorials', 'extending',
                             'chapter6-plugins'))

-    # Generate the QScintilla API file.
-    if target_config.qsci_api:
-        inform("Generating the QScintilla API file...")
-        f = open_for_writing('PyQt5.api')
-
-        for mname in target_config.pyqt_modules:
-            if MODULE_METADATA[mname].public:
-                api = open(mname + '.api')
-
-                for l in api:
-                    f.write('PyQt5.' + l)
-
-                api.close()
-                os.remove(mname + '.api')
-
-        f.close()
-
     # Generate the Python dbus module.
     if target_config.pydbus_module_dir != '':
         mname = 'dbus'
@@ -1577,14 +1562,18 @@
     out_f.write('''TEMPLATE = subdirs
 CONFIG += ordered nostrip
 SUBDIRS = %s
+''' % (' '.join(subdirs)))

+    if "QtCore" in target_config.pyqt_modules:
+        out_f.write('''
 init_py.files = %s
 init_py.path = %s
 INSTALLS += init_py
-''' % (' '.join(subdirs), source_path('__init__.py'), root_dir))
+''' % (source_path('__init__.py'), root_dir))

-    # Install the uic module.
-    out_f.write('''
+        if not target_config.no_tools:
+            # Install the uic module.
+            out_f.write('''
 uic_package.files = %s
 uic_package.path = %s
 INSTALLS += uic_package
@@ -1620,11 +1609,12 @@

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

