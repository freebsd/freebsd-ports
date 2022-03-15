--- tortoisehg/util/hgversion.py.orig	2022-03-06 02:33:21 UTC
+++ tortoisehg/util/hgversion.py
@@ -33,15 +33,7 @@ def checkhgversion(v):
     return vers
 
 def checkhgversion(v):
-    """range check the Mercurial version"""
-    reqvers = testedwith.split()
-    vers = _splitversion(v)
-    if not vers:
-        return
-    if b'.'.join(vers) in reqvers:
-        return
-    return (b'This version of TortoiseHg requires Mercurial version %s.n to '
-            b'%s.n, but found %s') % (reqvers[0], reqvers[-1], v)
+    return
 
 def checkminhgversion(v):
     """Check if the given Mercurial version is not lower than the minimum
