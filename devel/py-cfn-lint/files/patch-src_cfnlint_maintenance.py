--- src/cfnlint/maintenance.py.orig	2026-04-29 17:17:46 UTC
+++ src/cfnlint/maintenance.py
@@ -99,9 +99,8 @@ def update_documentation(rules):
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
