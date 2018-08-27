--- src/cc/pyext_DequeChar.cc.orig	2018-08-27 20:06:18 UTC
+++ src/cc/pyext_DequeChar.cc
@@ -59,7 +59,7 @@ DequeChar_New( PyObject* nil, PyObject* args )
 	{
 		// Create a DequeChar C++ object and associate with a Python self object.
 		DequeChar* dequeChar = new DequeChar();
-		sDequeCharMap.insert( make_pair<PyObject*,DequeChar*>(self,dequeChar) );
+		sDequeCharMap.insert( make_pair(self,dequeChar) );
 	}
 	PY_RETURN_NONE
 }
