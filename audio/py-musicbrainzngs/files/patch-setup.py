--- setup.py.orig	2013-06-06 19:19:28.876582953 -0500
+++ setup.py	2013-06-06 19:19:45.698579171 -0500
@@ -52,15 +52,6 @@
     author_email="alastair@porter.net.nz",
     url="https://github.com/alastair/python-musicbrainz-ngs",
     packages=['musicbrainzngs'],
-    package_data={'musicbrainzngs': ['CHANGES',
-                                     '../docs/*',
-                                     '../examples/*',
-                                     '../test/data/*.xml',
-                                     '../test/data/artist/*',
-                                     '../test/data/label/*',
-                                     '../test/data/release/*',
-                                     '../test/data/release-group/*',
-                                     '../test/data/work/*']},
     cmdclass={'test': test },
     license='BSD 2-clause',
     classifiers=[
