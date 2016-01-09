--- setup.py.orig	2016-01-09 17:19:18 UTC
+++ setup.py
@@ -46,11 +46,13 @@ setup(name='bugwarrior',
           "pyxdg",
       ],
       tests_require=[
-          "Mock",
+          "mock",
           "unittest2",
           "nose",
           "jira>=0.22",
           "megaplan>=1.4",
+          "pypandoc",
+          "pyac",
       ],
       test_suite='nose.collector',
       entry_points="""
