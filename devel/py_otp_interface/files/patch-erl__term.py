
$FreeBSD$

--- erl_term.py.orig	Fri Nov 15 18:53:36 2002
+++ erl_term.py	Fri Nov 15 18:54:03 2002
@@ -282,7 +282,7 @@
         if dataLen < 5:
             return (None, data)
         n = _ReadInt4(data[1:5])
-        return (ErlNumber(i), data[5:])
+        return (ErlNumber(n), data[5:])
 
     elif data0 == MAGIC_FLOAT:
         if dataLen < 32:
