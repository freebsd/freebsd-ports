--- setup.py.orig	Sun Sep 24 14:59:57 2006
+++ setup.py	Sun Sep 24 15:00:21 2006
@@ -7,11 +7,7 @@
 __version__ = "$Revision: 1.33 $"[11:-2]
 # $Source: /data/cvsroot/LivingLogic/Python/core/setup.py,v $
 
-
-try:
-	import setuptools as tools
-except ImportError:
-	from distutils import core as tools
+from distutils import core as tools
 
 
 DESCRIPTION = """ll-core is a collection of the following modules:
