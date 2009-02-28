--- setup.py.orig	2009-02-09 20:32:57.000000000 +0800
+++ setup.py	2009-02-09 20:33:48.000000000 +0800
@@ -92,14 +92,14 @@
                             opj('bin', 'server.pkey'), 
                             opj('bin', 'server.cert')]))
     else:
-        man_directory = opj('share', 'man')
-        files.append((opj(man_directory, 'man1'), ['man/openerp-server.1']))
-        files.append((opj(man_directory, 'man5'), ['man/openerp_serverrc.5']))
-
-        doc_directory = opj('share', 'doc', 'openerp-server-%s' % version)
-        files.append((doc_directory, [f for f in glob.glob('doc/*') if os.path.isfile(f)]))
-        files.append((opj(doc_directory, 'migrate', '3.3.0-3.4.0'), [f for f in glob.glob('doc/migrate/3.3.0-3.4.0/*') if os.path.isfile(f)]))
-        files.append((opj(doc_directory, 'migrate', '3.4.0-4.0.0'), [f for f in glob.glob('doc/migrate/3.4.0-4.0.0/*') if os.path.isfile(f)]))
+#        man_directory = opj('share', 'man')
+#        files.append((opj(man_directory, 'man1'), ['man/openerp-server.1']))
+#        files.append((opj(man_directory, 'man5'), ['man/openerp_serverrc.5']))
+
+#        doc_directory = opj('share', 'doc', 'openerp-server-%s' % version)
+#        files.append((doc_directory, [f for f in glob.glob('doc/*') if os.path.isfile(f)]))
+#        files.append((opj(doc_directory, 'migrate', '3.3.0-3.4.0'), [f for f in glob.glob('doc/migrate/3.3.0-3.4.0/*') if os.path.isfile(f)]))
+#        files.append((opj(doc_directory, 'migrate', '3.4.0-4.0.0'), [f for f in glob.glob('doc/migrate/3.4.0-4.0.0/*') if os.path.isfile(f)]))
 
         openerp_site_packages = opj('lib', 'python%s' % py_short_version, 'site-packages', 'openerp-server')
 
