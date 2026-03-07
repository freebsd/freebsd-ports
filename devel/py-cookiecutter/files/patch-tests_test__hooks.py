--- tests/test_hooks.py.orig	2026-03-04 04:05:35 UTC
+++ tests/test_hooks.py
@@ -42,7 +42,7 @@ def make_test_repo(name: str, multiple_hooks: bool = F
         post = 'post_gen_project.sh'
         filename = os.path.join(hook_dir, post)
         with Path(filename).open('w') as f:
-            f.write("#!/bin/bash\n")
+            f.write("#!/bin/sh\n")
             f.write("\n")
             f.write("echo 'post generation hook';\n")
             f.write("touch 'shell_post.txt'\n")
@@ -62,7 +62,7 @@ def make_test_repo(name: str, multiple_hooks: bool = F
             pre = 'pre_gen_project.sh'
             filename = os.path.join(hook_dir, pre)
             with Path(filename).open('w') as f:
-                f.write("#!/bin/bash\n")
+                f.write("#!/bin/sh\n")
                 f.write("\n")
                 f.write("echo 'post generation hook';\n")
                 f.write("touch 'shell_pre.txt'\n")
@@ -192,7 +192,7 @@ class TestExternalHooks:
                 f.write("echo. >{{cookiecutter.file}}\n")
         else:
             with Path(hook_path).open('w') as fh:
-                fh.write("#!/bin/bash\n")
+                fh.write("#!/bin/sh\n")
                 fh.write("\n")
                 fh.write("echo 'post generation hook';\n")
                 fh.write("touch 'shell_post.txt'\n")
