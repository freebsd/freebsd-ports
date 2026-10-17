Description: --dictionary used argparse.FileType('rU'), which Python 3.11
  removed. Open it as binary, like the bundled word list read through
  resource_stream(), since the words are decoded from UTF-8 afterwards.
  gen_passphrase() also took math.log(0) when the dictionary has no words
  of up to 2 letters; skip empty word-length sets.
Issue ID: https://github.com/tpltnt/pyutil/pull/15
Changeset: none (upstream master has the same code)
TODO: Submit upstream; drop once a release includes the fix.

--- pyutil/scripts/passphrase.py.orig	2022-12-26 22:48:41 UTC
+++ pyutil/scripts/passphrase.py
@@ -38,12 +38,15 @@ def recursive_subset_sum(entropy_needed,
 def gen_passphrase(entropy, allwords):
     maxlenwords = []
     i = 2 # The smallest set is words of length 1 or 2.
-    words = [x for x in allwords if len(x) <= i]
-    maxlenwords.append((math.log(len(words), 2), words))
-    while len(maxlenwords[-1][1]) < len(allwords):
-        i += 1
+    while True:
         words = [x for x in allwords if len(x) <= i]
-        maxlenwords.append((math.log(len(words), 2), words))
+        # A dictionary need not have words of every length; skip the
+        # empty sets (log2 of 0 is undefined).
+        if words:
+            maxlenwords.append((math.log(len(words), 2), words))
+        if len(words) >= len(allwords):
+            break
+        i += 1
 
     sr = random.SystemRandom()
     passphrase = []
@@ -60,7 +63,7 @@ def gen_passphrase(entropy, allwords):
 def main():
     parser = argparse.ArgumentParser(prog="passphrase", description="Create a random passphrase by picking a few random words.")
 
-    parser.add_argument('-d', '--dictionary', help="what file to read a list of words from (or omit this option to use passphrase's bundled dictionary)", type=argparse.FileType('rU'), metavar="DICT")
+    parser.add_argument('-d', '--dictionary', help="what file to read a list of words from (or omit this option to use passphrase's bundled dictionary)", type=argparse.FileType('rb'), metavar="DICT")
     parser.add_argument('bits', help="how many bits of entropy minimum", type=float, metavar="BITS")
     args = parser.parse_args()
 
