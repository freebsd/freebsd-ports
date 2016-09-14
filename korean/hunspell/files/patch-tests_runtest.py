--- tests/runtest.py.orig	2012-10-06 23:29:32 UTC
+++ tests/runtest.py
@@ -19,7 +19,7 @@ def main():
         hunspell_cmd = './hunspell'
     else:
         hunspell_cmd = 'hunspell'
-    hunspell = subprocess.Popen([hunspell_cmd, '-i', 'UTF-8', '-a', '-d', '../ko'],
+    hunspell = subprocess.Popen([hunspell_cmd, '-i', 'UTF-8', '-a', '-d', '../ko_KR'],
                                 stdin=subprocess.PIPE, stdout=subprocess.PIPE)
     hunspell.stdout.readline()  # the first line "Hunspell 1.2.8 ..."
     lineno = 0
