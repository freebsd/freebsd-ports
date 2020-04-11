--- tortoisehg/util/hgversion.py.orig	2020-04-08 09:44:12 UTC
+++ tortoisehg/util/hgversion.py
@@ -19,16 +19,4 @@ except AttributeError:
 testedwith = b'5.2 5.3'
 
 def checkhgversion(v):
-    """range check the Mercurial version"""
-    reqvers = testedwith.split()
-    v = v.split(b'+')[0]
-    if not v or v == b'unknown' or len(v) >= 12:
-        # can't make any intelligent decisions about unknown or hashes
-        return
-    vers = re.split(br'\.|-|rc', v)[:2]
-    if len(vers) < 2:
-        return
-    if b'.'.join(vers) in reqvers:
-        return
-    return (b'This version of TortoiseHg requires Mercurial version %s.n to '
-            b'%s.n, but found %s') % (reqvers[0], reqvers[-1], v)
+    return
