--- setup.py.orig	2015-03-25 01:54:01 UTC
+++ setup.py
@@ -75,7 +75,7 @@ setup(name='dulwich',
       The project is named after the part of London that Mr. and Mrs. Git live in
       in the particular Monty Python sketch.
       """,
-      packages=['dulwich', 'dulwich.tests', 'dulwich.tests.compat', 'dulwich.contrib'],
+      packages=['dulwich', 'dulwich.contrib'],
       package_data={'': ['../docs/tutorial/*.txt']},
       scripts=['bin/dulwich', 'bin/dul-receive-pack', 'bin/dul-upload-pack'],
       classifiers=[
