--- ZODB/ConflictResolution.py.orig	Fri Dec  3 01:28:07 2004
+++ ZODB/ConflictResolution.py	Fri Dec  3 01:28:26 2004
@@ -56,12 +56,12 @@
     data=None
     
     def __call__(self, oid,
-                 getattr=getattr, None=None):
+                 getattr=getattr, _None=None):
 
         data=self.data
         if not data: data=self.data={}
 
-        r=data.get(oid, None)
+        r=data.get(oid, _None)
         if r is None:
             r=PersistentReference()
             r.data=oid
