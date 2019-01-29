--- setup.py.orig	2019-01-13 16:56:06 UTC
+++ setup.py
@@ -16,6 +16,7 @@ limitations under the License.
 """
 import re
 import sys
+import codecs
 
 from setuptools import setup, find_packages
 
@@ -29,7 +30,7 @@ def get_version():
 
 def readme():
     """ Returns README.rst contents as str """
-    with open("README.rst") as f:
+    with codecs.open('README.rst', 'r', encoding='utf8') as f:
         return f.read()
 
 
