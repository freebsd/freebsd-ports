From 1f137150f8d4e01386c8c8ffacdcf5e556cea427 Mon Sep 17 00:00:00 2001
Date: Sun, 21 Jun 2015 14:52:38 +1000
Subject: [PATCH] Fix test command invocation causing ERROR
https://patch-diff.githubusercontent.com/raw/pypa/virtualenv/pull/773.patch

--- setup.py.orig	2016-01-21 12:49:27 UTC
+++ setup.py
@@ -31,7 +31,6 @@ try:
         'entry_points': {
             'console_scripts': [
                 'virtualenv=virtualenv:main',
-                'virtualenv-%s.%s=virtualenv:main' % sys.version_info[:2]
             ],
         },
         'zip_safe': False,
