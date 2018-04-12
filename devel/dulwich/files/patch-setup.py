--- setup.py.orig	2018-01-24 16:10:15.448366000 -0600
+++ setup.py	2018-01-24 16:10:49.157689000 -0600
@@ -91,8 +91,7 @@
       The project is named after the part of London that Mr. and Mrs. Git live
       in in the particular Monty Python sketch.
       """,
-      packages=['dulwich', 'dulwich.tests', 'dulwich.tests.compat',
-                'dulwich.contrib'],
+      packages=['dulwich', 'dulwich.contrib'],
       package_data={'': ['../docs/tutorial/*.txt']},
       scripts=['bin/dulwich', 'bin/dul-receive-pack', 'bin/dul-upload-pack'],
       classifiers=[
