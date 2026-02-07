--- setup.py.orig	2021-01-29 15:23:49 UTC
+++ setup.py
@@ -93,7 +93,6 @@ setuptools.setup(
     zip_safe=True,
     setup_requires=[
         'setuptools_git >= 0.3',
-        'sphinx',
     ],
     install_requires=['lxml'],
     tests_require=[],
@@ -112,11 +111,4 @@ setuptools.setup(
     license='LGPLv2.1+',
     url='https://tecnocode.co.uk/dbus-deviation/',
     cmdclass={'test': DiscoverTest},
-    command_options={
-        'build_sphinx': {
-            'project': ('setup.py', project_name),
-            'version': ('setup.py', __version__),
-            'release': ('setup.py', __version__),
-        },
-    },
 )
