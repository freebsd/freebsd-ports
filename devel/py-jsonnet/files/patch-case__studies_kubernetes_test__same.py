--- case_studies/kubernetes/test_same.py.orig	2020-11-22 14:19:41 UTC
+++ case_studies/kubernetes/test_same.py
@@ -15,7 +15,11 @@
 import yaml
 import json
 import sys
+import os
 
+os.chdir(os.path.dirname(os.path.abspath(__file__)))
+os.system("jsonnet -m ./ example.jsonnet")
+
 files = [
     'bigquery-controller',
     'redis-master',
@@ -50,10 +54,10 @@ def canonicalize(doc):
 
 for filename in files:
     with open(filename + '.old.yaml', 'r') as f:
-        yaml_doc = canonicalize(yaml.load(f))
+        yaml_doc = canonicalize(yaml.load(f, Loader=yaml.SafeLoader))
 
     with open(filename + '.new.yaml', 'r') as f:
-        jsonnet_doc = yaml.load(f)
+        jsonnet_doc = yaml.load(f, Loader=yaml.SafeLoader)
 
     if jsonstr(yaml_doc) == jsonstr(jsonnet_doc):
         print('Identical: %s' % filename)
@@ -65,6 +69,6 @@ for filename in files:
         with open(filename + '.new.yaml.out', 'w') as f:
             f.write(jsonstr(jsonnet_doc))
 
-        
+    os.remove(filename + '.new.yaml')
 
 
