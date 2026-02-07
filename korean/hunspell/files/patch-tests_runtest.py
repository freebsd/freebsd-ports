--- tests/runtest.py.orig	2017-12-25 07:30:13 UTC
+++ tests/runtest.py
@@ -27,7 +27,7 @@ def main():
         hunspell_cmd = './hunspell'
     else:
         hunspell_cmd = 'hunspell'
-    args = [hunspell_cmd, '-i', 'UTF-8', '-d', '../ko']
+    args = [hunspell_cmd, '-i', 'UTF-8', '-d', '../ko_KR']
     hunspell = subprocess.Popen(args,
                                 stdin=subprocess.PIPE, stdout=subprocess.PIPE)
     hunspell.stdout.readline()  # the first line "Hunspell 1.2.8 ..."
