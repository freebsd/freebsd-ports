--- xcaplib/xpath_completion.py.orig	2016-01-12 11:22:06 UTC
+++ xcaplib/xpath_completion.py
@@ -50,7 +50,7 @@ def fix_namespace_prefix(selector, prefix = 'default')
             steps.append(prefix + ':' + step)
     return '/'.join(steps)
 
-def path_element((prefix, name)):
+def path_element(prefix, name):
     if prefix:
         return prefix + ':' + name
     else:
