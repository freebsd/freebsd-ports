Description: force_repeatability() imported i2b from the long-gone idlib,
  raised a plain string, returned str from the fake urandom, used the
  Python 2 long builtin and imported setutil, which is not part of pyutil.
  Build the bytes with int.to_bytes(), raise ValueError, use int() and only
  adjust setutil if it is installed.
Issue ID: https://github.com/tpltnt/pyutil/pull/15
Changeset: none (upstream master has the same code)
TODO: Submit upstream; drop once a release includes the fix.

--- pyutil/repeatable_random.py.orig	2022-12-26 22:48:41 UTC
+++ pyutil/repeatable_random.py
@@ -37,15 +37,13 @@ def force_repeatability():
     time.faketime = faketime
     time.time = faketime
 
-    from idlib import i2b
     def fakeurandom(n):
         if n > 64:
-            raise ("Can't produce more than 64 bytes of pseudorandomness efficiently.")
+            raise ValueError("Can't produce more than 64 bytes of pseudorandomness efficiently.")
         elif n == 0:
-            return ''
+            return b''
         else:
-            z = i2b(random.getrandbits(n*8))
-        x = z + "0" * (n-len(z))
+            x = random.getrandbits(n*8).to_bytes(n, 'big')
         assert len(x) == n
         return x
     os.fakeurandom = fakeurandom
@@ -61,7 +59,7 @@ def force_repeatability():
             subsec = t % 1
             t += (subsec * 1000000)
             t %= 1000000
-            SEED = long(t)
+            SEED = int(t)
         import sys
         sys.stdout.write("REPEATABLE_RANDOMNESS_SEED: %s\n" % SEED) ; sys.stdout.flush()
         sys.stdout.write("In order to reproduce this run of the code, set the environment variable \"REPEATABLE_RANDOMNESS_SEED\" to %s before executing.\n" % SEED) ; sys.stdout.flush()
@@ -74,8 +72,13 @@ def force_repeatability():
         random.seed = seed_which_refuses
         seeded = True
 
-    import setutil
-    setutil.RandomSet.DETERMINISTIC = True
+    try:
+        import setutil
+    except ImportError:
+        # setutil is not part of pyutil; only tweak it if it is installed.
+        pass
+    else:
+        setutil.RandomSet.DETERMINISTIC = True
 
 def restore_real_clock():
     time.time = time.realtime
