--- setup.py.orig	2016-07-05 22:58:08 UTC
+++ setup.py
@@ -83,7 +83,7 @@ setup(name='dulwich',
       The project is named after the part of London that Mr. and Mrs. Git live in
       in the particular Monty Python sketch.
       """,
-      packages=['dulwich', 'dulwich.tests', 'dulwich.tests.compat', 'dulwich.contrib'],
+      packages=['dulwich', 'dulwich.contrib'],
       package_data={'': ['../docs/tutorial/*.txt']},
       scripts=['bin/dulwich', 'bin/dul-receive-pack', 'bin/dul-upload-pack'],
       classifiers=[
