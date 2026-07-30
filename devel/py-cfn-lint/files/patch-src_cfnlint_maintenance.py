--- src/cfnlint/maintenance.py.orig	2026-07-09 18:08:26 UTC
+++ src/cfnlint/maintenance.py
@@ -80,9 +80,8 @@ def update_documentation(rules):
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
