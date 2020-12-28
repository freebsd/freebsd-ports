--- tests/test_hooks.py.orig	2020-12-28 09:57:55 UTC
+++ tests/test_hooks.py
@@ -42,7 +42,7 @@ def make_test_repo(name):
         post = 'post_gen_project.sh'
         filename = os.path.join(hook_dir, post)
         with open(filename, 'w') as f:
-            f.write("#!/bin/bash\n")
+            f.write("#!/bin/sh\n")
             f.write("\n")
             f.write("echo 'post generation hook';\n")
             f.write("touch 'shell_post.txt'\n")
@@ -143,7 +143,7 @@ class TestExternalHooks(object):
                 f.write("echo. >{{cookiecutter.file}}\n")
         else:
             with open(hook_path, 'w') as fh:
-                fh.write("#!/bin/bash\n")
+                fh.write("#!/bin/sh\n")
                 fh.write("\n")
                 fh.write("echo 'post generation hook';\n")
                 fh.write("touch 'shell_post.txt'\n")
