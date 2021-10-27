--- setup.py.orig	2021-04-05 11:58:43 UTC
+++ setup.py
@@ -496,7 +496,7 @@ setup_args['install_requires'] = [
     'Jinja2 >= 2.1',
     # required for tests, but Twisted requires this anyway
     'zope.interface >= 4.1.1',
-    'sqlalchemy >= 1.2.0, < 1.4',
+    'sqlalchemy >= 1.2.0, < 1.5',
     'sqlalchemy-migrate>=0.13',
     'python-dateutil>=1.5',
     'txaio ' + txaio_ver,
