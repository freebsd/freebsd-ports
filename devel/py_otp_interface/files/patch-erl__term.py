
$FreeBSD$

--- erl_term.py.orig	Wed May 29 00:09:25 2002
+++ erl_term.py	Sat Nov 16 17:40:38 2002
@@ -282,7 +282,7 @@
         if dataLen < 5:
             return (None, data)
         n = _ReadInt4(data[1:5])
-        return (ErlNumber(i), data[5:])
+        return (ErlNumber(n), data[5:])
 
     elif data0 == MAGIC_FLOAT:
         if dataLen < 32:
@@ -373,7 +373,7 @@
         (elements, remainingData) = _UnpackTermSeq(arity, data[5:])
         if elements == None:
             return (None, data)
-        return (ErlList(elements), remainingData)
+        return (ErlList(elements), remainingData[1:]) # skip MAGIC_NIL
 
     elif data0 == MAGIC_BINARY:
         if dataLen < 5:
@@ -552,11 +552,11 @@
     
 def _PackString(term):
     if len(term) == 0:
-        return PackList([])
+        return _PackList([])
     elif len(term) <= 65535:
         return _PackInt1(MAGIC_STRING) + _PackInt2(len(term)) + term
     else:
-        return PackList(map(lambda c: ord(c), term))
+        return _PackList(map(lambda c: ord(c), term))
 
 def _PackList(term):
     if len(term) == 0:
