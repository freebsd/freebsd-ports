--- tests/test_hooks.py.orig	2023-06-13 08:07:06 UTC
+++ tests/test_hooks.py
@@ -41,7 +41,7 @@ def make_test_repo(name, multiple_hooks=False):
         post = 'post_gen_project.sh'
         filename = os.path.join(hook_dir, post)
         with Path(filename).open('w') as f:
-            f.write("#!/bin/bash\n")
+            f.write("#!/bin/sh\n")
             f.write("\n")
             f.write("echo 'post generation hook';\n")
             f.write("touch 'shell_post.txt'\n")
@@ -61,7 +61,7 @@ def make_test_repo(name, multiple_hooks=False):
             pre = 'pre_gen_project.sh'
             filename = os.path.join(hook_dir, pre)
             with Path(filename).open('w') as f:
-                f.write("#!/bin/bash\n")
+                f.write("#!/bin/sh\n")
                 f.write("\n")
                 f.write("echo 'post generation hook';\n")
                 f.write("touch 'shell_pre.txt'\n")
@@ -189,7 +189,7 @@ class TestExternalHooks:
                 f.write("echo. >{{cookiecutter.file}}\n")
         else:
             with Path(hook_path).open('w') as fh:
-                fh.write("#!/bin/bash\n")
+                fh.write("#!/bin/sh\n")
                 fh.write("\n")
                 fh.write("echo 'post generation hook';\n")
                 fh.write("touch 'shell_post.txt'\n")
