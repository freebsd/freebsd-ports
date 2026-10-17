Description: The byte count passed to os.urandom() was computed with true
  division, a float on Python 3; use floor division. randcookie also
  imported the zbase32 package, which is not ported and is Python 2 only;
  encode z-base-32 in randcookie.b2a_l() instead, which behaves like
  zbase32.b2a_l() (only the first lengthinbits bits count).
Issue ID: https://github.com/tpltnt/pyutil/pull/15
Changeset: none (upstream master has the same code)
TODO: Submit upstream; drop once a release includes the fix.

--- pyutil/scripts/randcookie.py.orig	2022-12-26 22:48:41 UTC
+++ pyutil/scripts/randcookie.py
@@ -6,7 +6,29 @@
 
 from __future__ import print_function
 import os, sys
-import zbase32
+
+# z-base-32, http://philzimmermann.com/docs/human-oriented-base-32-encoding.txt
+ZBASE32_ALPHABET = "ybndrfg8ejkmcpqxot1uwisza345h769"
+
+def b2a_l(data, lengthinbits):
+    """
+    Encode the first lengthinbits bits of data in z-base-32, using as few
+    characters as hold that many bits.  data must be exactly long enough
+    for lengthinbits; any bits after the first lengthinbits are ignored.
+
+    This gives the same result as b2a_l() from the zbase32 package, which
+    randcookie used to require but which does not install on Python 3.
+    """
+    if (lengthinbits + 7) // 8 != len(data):
+        raise ValueError("lengthinbits (%d) does not fit exactly in %d bytes"
+                         % (lengthinbits, len(data)))
+    numquintets = (lengthinbits + 4) // 5
+    # Keep the first lengthinbits bits and pad them with zero bits to a
+    # whole number of quintets.
+    n = int.from_bytes(data, "big") >> (len(data) * 8 - lengthinbits)
+    n <<= numquintets * 5 - lengthinbits
+    return "".join(ZBASE32_ALPHABET[(n >> (5 * i)) & 31]
+                   for i in reversed(range(numquintets)))
 
 def main():
     if len(sys.argv) > 1:
@@ -14,9 +36,9 @@ def main():
     else:
         l = 64
 
-    bl = (l + 7) / 8
+    bl = (l + 7) // 8
 
-    s = zbase32.b2a_l(os.urandom(bl), l)
+    s = b2a_l(os.urandom(bl), l)
 
     # insert some hyphens for easier memorization
     chs = 3 + (len(s)%8==0)
