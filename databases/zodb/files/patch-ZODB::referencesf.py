--- ZODB/referencesf.py.orig	Fri Dec  3 01:29:52 2004
+++ ZODB/referencesf.py	Fri Dec  3 01:30:06 2004
@@ -19,9 +19,9 @@
                 Unpickler=cPickle.Unpickler,
                 StringIO=cStringIO.StringIO,
                 tt=type(()),
-                type=type, None=None):
+                type=type, _None=None):
 
-    if rootl is None: rootl=[]
+    if rootl is _None: rootl=[]
     u=Unpickler(StringIO(p))
     l=len(rootl)
     u.persistent_load=rootl
