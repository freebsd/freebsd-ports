--- setup.py.orig	2021-11-12 08:00:52 UTC
+++ setup.py
@@ -57,12 +57,6 @@ setup(
     python_requires=">=3.6.1",
     install_requires=requirements,
     extras_require=extras_require,
-    entry_points={
-        'console_scripts': [
-            'jupyter-run = nbclient.cli:run',
-            'jupyter-execute = nbclient.cli:execute',
-        ],
-    },
     project_urls={
         'Documentation': 'https://nbclient.readthedocs.io',
         'Funding': 'https://numfocus.org/',
