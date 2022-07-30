--- setup.py.orig	2022-07-12 06:33:06 UTC
+++ setup.py
@@ -133,9 +133,6 @@ for more information.
     entry_points = {
         'console_scripts': [
             'jupyter-nbclassic = nbclassic.notebookapp:main',
-            'jupyter-nbextension = nbclassic.nbextensions:main',
-            'jupyter-serverextension = nbclassic.serverextensions:main',
-            'jupyter-bundlerextension = nbclassic.bundler.bundlerextensions:main',
         ]
     },
 )
