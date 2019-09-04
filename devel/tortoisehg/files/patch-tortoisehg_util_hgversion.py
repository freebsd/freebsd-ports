--- tortoisehg/util/hgversion.py.orig	2019-06-27 21:18:37 UTC
+++ tortoisehg/util/hgversion.py
@@ -19,16 +19,4 @@ except AttributeError:
 testedwith = '4.9 5.0'
 
 def checkhgversion(v):
-    """range check the Mercurial version"""
-    reqvers = testedwith.split()
-    v = v.split('+')[0]
-    if not v or v == 'unknown' or len(v) >= 12:
-        # can't make any intelligent decisions about unknown or hashes
-        return
-    vers = re.split(r'\.|-|rc', v)[:2]
-    if len(vers) < 2:
-        return
-    if '.'.join(vers) in reqvers:
-        return
-    return ('This version of TortoiseHg requires Mercurial version %s.n to '
-            '%s.n, but found %s') % (reqvers[0], reqvers[-1], v)
+    return
