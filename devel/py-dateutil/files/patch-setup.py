--- ./setup.py.orig	2014-08-28 18:39:38.459159039 +1000
+++ ./setup.py	2014-08-28 18:39:48.929863352 +1000
@@ -47,5 +47,6 @@
           'Programming Language :: Python :: 3.2',
           'Programming Language :: Python :: 3.3',
           'Topic :: Software Development :: Libraries',
-      ]
+      ],
+      test_suite='test',
       )
