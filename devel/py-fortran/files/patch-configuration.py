--- configuration.py.orig	Thu Jul 25 01:28:57 2002
+++ configuration.py	Thu Jul 25 01:30:22 2002
@@ -19,6 +19,8 @@
     default_compiler = 'sgi'
 elif sys.platform[0:6] == 'darwin':
     default_compiler = 'fort77'
+elif sys.platform[0:7] == 'freebsd':
+    default_compiler = 'f77'
 
 # B. Set the suffix used for project directories
 # This is added to the project name to produce the container directory
