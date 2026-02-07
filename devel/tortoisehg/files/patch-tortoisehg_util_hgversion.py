--- tortoisehg/util/hgversion.py.orig	2022-11-13 03:06:49 UTC
+++ tortoisehg/util/hgversion.py
@@ -39,15 +39,7 @@ def checkhgversion(v: bytes) -> Optional[bytes]:
     return vers
 
 def checkhgversion(v: bytes) -> Optional[bytes]:
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
 
 def checkminhgversion(v: bytes) -> Optional[bytes]:
     """Check if the given Mercurial version is not lower than the minimum
