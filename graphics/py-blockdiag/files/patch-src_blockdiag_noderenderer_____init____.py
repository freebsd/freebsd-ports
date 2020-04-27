--- src/blockdiag/noderenderer/__init__.py.orig	2020-01-13 09:55:52 UTC
+++ src/blockdiag/noderenderer/__init__.py
@@ -16,6 +16,7 @@
 from __future__ import division
 
 import pkg_resources
+from blockdiag.noderenderer.base import NodeShape  # NOQA: backward compatibility
 
 renderers = {}
 searchpath = []
