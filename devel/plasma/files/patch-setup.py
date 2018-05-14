--- setup.py.orig	2018-04-15 11:48:52 UTC
+++ setup.py
@@ -6,30 +6,33 @@ except ImportError:
     from distutils.core import setup
 
 
-from pip.req import parse_requirements
+#from pip.req import parse_requirements
 from distutils.core import Extension
 import plasma
 
-requirements = parse_requirements('requirements.txt', session=False)
+#requirements = parse_requirements('requirements.txt', session=False)
 
 requires = []
-for item in requirements:
+#for item in requirements:
     # we want to handle package names and also repo urls
-    if getattr(item, 'url', None):  # older pip has url
-        links.append(str(item.url))
-    if getattr(item, 'link', None): # newer pip has link
-        links.append(str(item.link))
-    if item.req:
-        requires.append(str(item.req))
+#    if getattr(item, 'url', None):  # older pip has url
+#        links.append(str(item.url))
+#    if getattr(item, 'link', None): # newer pip has link
+#        links.append(str(item.link))
+#    if item.req:
+#        requires.append(str(item.req))
 
 
 x86_analyzer = Extension('plasma.lib.arch.x86.analyzer',
+    include_dirs = ['%%PREFIX%%/include'],
     sources = ['plasma/lib/arch/x86/analyzer.c'])
 
 mips_analyzer = Extension('plasma.lib.arch.mips.analyzer',
+    include_dirs = ['%%PREFIX%%/include'],
     sources = ['plasma/lib/arch/mips/analyzer.c'])
 
 arm_analyzer = Extension('plasma.lib.arch.arm.analyzer',
+    include_dirs = ['%%PREFIX%%/include'],
     sources = ['plasma/lib/arch/arm/analyzer.c'])
 
 
