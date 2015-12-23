This patch is necessary for us to split PyQt5 up into several different ports.

It works by conditionally building and installing some tools (such as
pylupdate5 and pyrcc5), replacing the all-encompassing PyQt5.api file that
depends on different modules with module-specific .api files.
--- configure.py.orig	2015-10-25 11:42:16 UTC
+++ configure.py
@@ -1458,13 +1458,13 @@ def generate_makefiles(target_config, ve
 
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
@@ -1483,22 +1483,6 @@ def generate_makefiles(target_config, ve
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
@@ -1526,21 +1510,24 @@ def generate_makefiles(target_config, ve
     out_f.write('''TEMPLATE = subdirs
 CONFIG += ordered nostrip
 SUBDIRS = %s
+''' % (' '.join(subdirs)))
 
+    if "QtCore" in target_config.pyqt_modules:
+        out_f.write('''
 init_py.files = %s
 init_py.path = %s/PyQt5
 INSTALLS += init_py
-''' % (' '.join(subdirs), source_path('__init__.py'), target_config.pyqt_module_dir))
+''' % (source_path('__init__.py'), target_config.pyqt_module_dir))
 
-    # Install the uic module and the pyuic5 wrapper.
-    out_f.write('''
+        # Install the uic module and the pyuic5 wrapper.
+        out_f.write('''
 uic_package.files = %s
 uic_package.path = %s/PyQt5
 INSTALLS += uic_package
 ''' % (source_path('pyuic', 'uic'), target_config.pyqt_module_dir))
 
-    if not target_config.no_tools:
-        out_f.write('''
+        if not target_config.no_tools:
+            out_f.write('''
 pyuic5.files = %s
 pyuic5.path = %s
 INSTALLS += pyuic5
@@ -1548,11 +1535,12 @@ INSTALLS += pyuic5
 
     # Install the QScintilla .api file.
     if target_config.qsci_api:
+        api_list = ' '.join(['%s.api' % m for m in target_config.pyqt_modules])
         out_f.write('''
-qscintilla_api.files = PyQt5.api
+qscintilla_api.files = %s
 qscintilla_api.path = %s/api/python
 INSTALLS += qscintilla_api
-''' % target_config.qsci_api_dir)
+''' % (api_list, target_config.qsci_api_dir))
 
     out_f.close()
 
