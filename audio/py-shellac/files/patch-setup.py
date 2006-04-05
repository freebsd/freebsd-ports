--- setup.py.orig	Tue Apr  4 18:41:33 2006
+++ setup.py	Tue Apr  4 18:42:07 2006
@@ -7,10 +7,7 @@
         author_email = 'bjernstad@gmail.com',
         url = 'http://hem.bredband.net/b298027/',
         packages=['Shellac'],
-        data_files = [ ('share/doc/shellac',
-                                    ['COPYING', 'README']),
-
-                       ('share/shellac',
+        data_files = [ ('share/shellac',  
                                     ['defaults.conf']),
 
                        ('share/shellac/images',
