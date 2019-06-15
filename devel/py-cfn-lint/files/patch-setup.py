https://github.com/aws-cloudformation/cfn-python-lint/issues/905

--- setup.py.orig	2019-06-15 13:03:38 UTC
+++ setup.py
@@ -78,7 +78,7 @@ setup(
         'requests>=2.15.0',
         'aws-sam-translator>=1.10.0',
         'jsonpatch',
-        'jsonschema~=2.6',
+        'jsonschema~=3.0',
         'pathlib2>=2.3.0;python_version<"3.4"',
         'setuptools',
     ],
