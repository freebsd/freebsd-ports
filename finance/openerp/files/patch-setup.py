--- setup.py	2011-08-21 16:34:59.526991138 +0200
+++ setup.diffs	2011-08-21 16:35:49.515560426 +0200
@@ -145,16 +145,16 @@
         #    files.append((root, [join(root, name) for name in names]))
         files.append(('.', [join('bin', 'import_xml.rng'),]))
     else:
-        man_directory = join('share', 'man')
-        files.append((join(man_directory, 'man1'), ['man/openerp-server.1']))
-        files.append((join(man_directory, 'man5'), ['man/openerp_serverrc.5']))
-
-        doc_directory = join('share', 'doc', 'openerp-server-%s' % version)
-        files.append((doc_directory, filter(isfile, glob.glob('doc/*'))))
-        files.append((join(doc_directory, 'migrate', '3.3.0-3.4.0'),
-                      filter(isfile, glob.glob('doc/migrate/3.3.0-3.4.0/*'))))
-        files.append((join(doc_directory, 'migrate', '3.4.0-4.0.0'),
-                      filter(isfile, glob.glob('doc/migrate/3.4.0-4.0.0/*'))))
+#        man_directory = join('share', 'man')
+#        files.append((join(man_directory, 'man1'), ['man/openerp-server.1']))
+#        files.append((join(man_directory, 'man5'), ['man/openerp_serverrc.5']))
+#
+#        doc_directory = join('share', 'doc', 'openerp-server-%s' % version)
+#        files.append((doc_directory, filter(isfile, glob.glob('doc/*'))))
+#        files.append((join(doc_directory, 'migrate', '3.3.0-3.4.0'),
+#                      filter(isfile, glob.glob('doc/migrate/3.3.0-3.4.0/*'))))
+#        files.append((join(doc_directory, 'migrate', '3.4.0-4.0.0'),
+#                      filter(isfile, glob.glob('doc/migrate/3.4.0-4.0.0/*'))))
 
         openerp_site_packages = join(get_python_lib(prefix=''), 'openerp-server')
 
