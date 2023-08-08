--- src/cfnlint/maintenance.py.orig	2023-05-08 16:34:58 UTC
+++ src/cfnlint/maintenance.py
@@ -226,9 +226,8 @@ def update_documentation(rules):
                 "../"
                 + subprocess.check_output(
                     [
-                        "git",
                         "grep",
-                        "-l",
+                        "-lr",
                         'id = "' + rule.id + '"',
                         "src/cfnlint/rules/",
                     ]
