--- ./setup.py.orig	2013-06-16 18:54:43.668848521 +1000
+++ ./setup.py	2013-06-16 18:54:57.779885292 +1000
@@ -57,5 +57,6 @@
         'Programming Language :: Python :: 3',
         'Programming Language :: Python :: 3.2',
         'Programming Language :: Python :: 3.3',
-    ]
+    ],
+    zip_safe=False,
 )
