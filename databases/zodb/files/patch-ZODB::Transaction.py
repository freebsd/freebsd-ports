--- ZODB/Transaction.py.orig	Fri Dec  3 01:29:04 2004
+++ ZODB/Transaction.py	Fri Dec  3 01:29:17 2004
@@ -351,9 +351,9 @@
 
 else:
     _t={}
-    def get_transaction(_id=thread.get_ident, _t=_t, get=_t.get, None=None):
+    def get_transaction(_id=thread.get_ident, _t=_t, get=_t.get, _None=None):
         id=_id()
-        t=get(id, None)
+        t=get(id, _None)
         if t is None: _t[id]=t=Transaction(id)
         return t
 
