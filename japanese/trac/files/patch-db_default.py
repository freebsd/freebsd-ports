--- trac/db_default.py.orig	Sat Jul  8 08:40:03 2006
+++ trac/db_default.py	Sat Jul  8 08:40:05 2006
@@ -385,7 +385,7 @@
  (('trac', 'repository_dir', ''),
   ('trac', 'templates_dir', default_dir('templates')),
   ('trac', 'database', 'sqlite:db/trac.db'),
-  ('trac', 'default_charset', 'iso-8859-15'),
+  ('trac', 'default_charset', 'utf-8'),
   ('trac', 'default_handler', 'WikiModule'),
   ('trac', 'check_auth_ip', 'true'),
   ('trac', 'ignore_auth_case', 'false'),
