--- setup.py.orig	2015-02-25 17:30:21 UTC
+++ setup.py
@@ -52,6 +52,7 @@ setup(name='bugwarrior',
           "jira>=0.22",
           "megaplan>=1.4",
       ],
+      test_suite='nose.collector',
       entry_points="""
       [console_scripts]
       bugwarrior-pull = bugwarrior:pull
