--- ./buildslave/test/__init__.py.orig	2012-12-07 22:20:33.655375165 +1100
+++ ./buildslave/test/__init__.py	2012-12-07 22:21:11.070790866 +1100
@@ -58,6 +58,6 @@
     import mock
     mock = mock
 except ImportError:
-    print >>sys.stderr, ("\nBuildbot tests require the 'mock' module; "
-                         "try 'pip install mock'")
-    os._exit(1)
+    raise ImportError("Buildbot tests require the 'mock' module; "
+                      "try 'pip install mock'")
+
